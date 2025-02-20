#include "product.h"
#include <string>
#include <set>

class Movie : public Product {
public: 
  Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating); 

  std::set<std::string> keywords() const override; 
  std::string displayString() const override; 
  void dump(std::ostream& os) const override;
  std::string getGenre() const; 
  std::string getRating() const; 

private:
  std::string genre_; 
  std::string rating_; 
};