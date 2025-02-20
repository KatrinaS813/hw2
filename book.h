#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <string>
#include <set>

class Book : public Product {
private:
  std::string isbn_; 
  std::string author_; 

public: 
  Book(const std::string& category, const std::string& name, double price, int qty, std::string& isbn, std::string& author);

  ~Book(); 

  std::set<std::string> keywords() const override; 
  std::string displayString() const override; 
  void dump(std::ostream& os) const override; 
  std::string getISBN() const;
  std::string getAuthor() const; 
}; 

#endif
