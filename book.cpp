#include "book.h"
#include <string>
#include <set>
#include "util.h"
#include <iostream>
Book::Book(const std::string& category, const std::string& name, double price, int qty, std::string& isbn, std::string& author): Product(category,name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

std::set<std::string> Book::keywords() const {
  std::set<std::string> words = parseStringToWords(convToLower(name_)); 
  std::set<std::string> authorWords = parseStringToWords(convToLower(author_)); 
  words.insert(authorWords.begin(), authorWords.end()); 
  words.insert(isbn_); 
  // std::cout<<"word\n";
  // for(std::string word : words){
  //   std::cout<<word<<std::endl;
  // }
  return words; 
}

std::string Book::displayString() const{
  std::string result = name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left."; 
  return result; 
}

void Book::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << "\n"; 
}

std::string Book::getISBN() const {
  return isbn_; 
}

std::string Book::getAuthor() const {
  return author_; 
}
