#include "mydatastore.h"
#include "util.h"
#include "datastore.h"


MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore(){
  for(size_t i = 0; i < products_size(); ++i){
    delete products_[i]; 
  }
  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    delete it->second; 
  }
}

void MyDataStore::addProduct(Product* p){
  products_.insert(p); 
}

void MyDataStore::adduser(User* u){
  users_[convToLower(u->getName())] = u; 
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  
}


void MyDataStore::dump(std::ostream& ofile){
  ofile << "<products>" << std::endl; 
  for(Product* p : products_){
    p->dump(ofile); 
  }
  ofile << "</products>" << std::endl; 
  ofile << "<users>" << std::endl; 

  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_end(); ++it){
    it->second->dump(ofile); 
  }
  ofile << "</users>" << std::endl; 
}

void MyDataStore::addCart(std::string username, size_t index){
  
}

void MyDataStore::viewCart(std::string username) {

}

void MyDataStore::buyCart(std::string username) {

}