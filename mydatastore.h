#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "util.h"
#include "datastore.h"
#include <map>
#include <string>
 
class MyDataStore : public DataStore {
public: 
  MyDataStore(); 

  ~MyDataStore(); 

  void addProduct(Product* p) override; 
  void addUser(User* u) override; 
  std::vector<Product*> search(std::vector<std::string>& terms, int type) override; 
  void dump(std::ostream& ofile) override; 
  void addToCart(std::string username, size_t index);
  void viewCart(std::string username); 
  void buyCart(std::string username); 

private: 
  std::set<Product*> products_; 
  std::map<std::string, User*> users_; 
  std::map<std::string, std::vector<Product*>> carts_; 
  std::vector<Product*> hits_; 
};

#endif 
