#include "mydatastore.h"
#include "util.h"
#include "datastore.h"
#include <set>
#include <map>
#include <vector> 


MyDataStore::MyDataStore() {}

/**
 * Destructor.  Calls delete on all Products and Users
 * in the data store.  Does not delete products or users that
 * have been added to carts.
 */
/******  4be3cb60-231f-424e-94a5-26f2b9a61803  *******/
MyDataStore::~MyDataStore(){
  for(Product* p : products_){
    delete p; 
  }
  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    delete it->second; 
  }
}

void MyDataStore::addProduct(Product* p){
  products_.insert(p); 
}

void MyDataStore::addUser(User* u){
  users_[convToLower(u->getName())] = u; 
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  if(type != 0 && type != 1){
    return std::vector<Product*>();
  }
  std::vector<Product*> result; 
  std::set<std::string> matches; 

  for(size_t i = 0; i < terms.size(); ++i){
    //std::cout<<terms[i]<<std::endl;
    matches.insert(convToLower(terms[i]));
  }
  for(Product* p : products_){
    size_t matchCount = setIntersection(p->keywords(), matches).size(); 
    if(type == 0 && matchCount == matches.size()){
      result.push_back(p); 
    }
    else if (type == 1 && matchCount > 0){
      result.push_back(p);
    }
  }
  hits_ = result;
  return result;
}

void MyDataStore::dump(std::ostream& ofile){
  ofile << "<products>" << std::endl; 
  for(Product* p : products_){
    p->dump(ofile); 
  }
  ofile << "</products>" << std::endl; 
  ofile << "<users>" << std::endl; 

  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    it->second->dump(ofile); 
  }
  ofile << "</users>" << std::endl; 
}

void MyDataStore::addToCart(std::string username, size_t index){
  std::string lowerUsername = convToLower(username); 
  std::map<std::string, User*>::iterator userIt = users_.find(lowerUsername);
  if (userIt == users_.end()) {
    std::cout << "Invalid request1" << std::endl;
    return;
  }
  if (index > hits_.size()) {
    std::cout << "Invalid request" << std::endl;
    return;
  }
  carts_[lowerUsername].push_back(hits_[index - 1]);
}

void MyDataStore::viewCart(std::string username) {
  if(carts_.find(username) == carts_.end()){
    std::cout << "Invalid username" << std::endl;
  } 
  std::vector<Product*>& cart = carts_[username]; 
  for(size_t i = 0; i < cart.size(); ++i){
    std::cout << "Item " << i+1 << std::endl; 
    std::cout << cart[i]->displayString() << std::endl << std::endl;
  }
}

void MyDataStore::buyCart(std::string username) {
  if (carts_.find(username) == carts_.end() || users_.find(username) == users_.end()) {
    std::cout << "Invalid username" << std::endl;
    return;
  }
  User* u = users_[username]; 
  std::vector<Product*>& cart = carts_[username]; 
  for (size_t i = 0; i < cart.size(); i++) {
    if (u->getBalance() >= cart[i]->getPrice() && cart[i]->getQty() > 0) {
      u->deductAmount(cart[i]->getPrice()); 
      cart[i]->subtractQty(1); 
      cart.erase(cart.begin() + i); 
      i--; 
      }
  }
}