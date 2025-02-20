#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "util.h"
#include "datastore.h"
#include <string>
 
class MyDataStore : public DataStore {
public: 
  MyDataStore(); 

  ~MyDataStore(); 

  void addProduct(Product* p) override; 
  void addUser(User* u) override; 
  std::vector<Product*> search(std::vector<std::string>& terms, int type) override; 
  void dump(std::ostream& ofile) override; 
  void addCart(std::string username, size_t index);
  void viewCart(std::string username); 
  void buyCart(std::string username); 

private: 
  std::set<Product*> products_; 
  std::map<std::string, User*> users_; 
  



}






