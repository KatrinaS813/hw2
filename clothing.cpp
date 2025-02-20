#include "clothing.h"
#include "util.h"
#include <set>
#include <string>

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) : Product(category, name, price, qty), size_(size), brand_(brand){}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> keyName = parseStringToWords(convToLower(name_)); 
  std::set<std::string> keyBrand = parseStringToWords(convToLower(brand_));
  std::set<std::string> keywords = setUnion(keyName, keyBrand); 
  return keywords; 
}

std::string Clothing::displayString() const {
  std::string result = name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left."; 
  return result; 
}

void Clothing::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << "\n"; 
}