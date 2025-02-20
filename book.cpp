#include "book.h"
#include <string>
#include <set>
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string& isbn, const std::string& author) : Product(name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

std::set<std::string> Book::keywords() const {
  std::set<std::string> words = parseStringToWords(name_); 
  std::set<std::string> authorWords = parseStringToWords(author_); 
  words.insert(authorWords.begin(), authorWords.end()); 
  words.insert(isbn_); 
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
