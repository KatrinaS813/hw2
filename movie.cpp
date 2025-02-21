#include "movie.h"
#include "util.h"
#include <set>
#include <string>

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) 
      : Product(category, name, price, qty), genre_(genre), rating_(rating){}

std::set<std::string> Movie::keywords() const {
  std::set<std::string> keywords = parseStringToWords(convToLower(name_)); 
  keywords.insert(convToLower(genre_)); 
  return keywords; 
}

std::string Movie::displayString() const {
  std::string result = name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left."; 
  return result; 
}

void Movie::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << "\n"; 
}