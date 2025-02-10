#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include "GroceryItem.hpp"

int main()
{
  std::vector<std::unique_ptr<GroceryItem>> shoppingCart{};
  GroceryItem newProduct; 

  std::cout << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information.\n" 
            << "enclose string entries in quotes, separate fields with comas\n" 
            << "for example:  '00016000306707', 'Betty Crocker', 'Betty Crocker Double Chocolate Chunk Cookie Mix', 17.19\n" 
            << "Enter CTL-Z (Windows) or CTL-D (Linux) to quit \n\n";

  std::cout << "Enter UPC, Product Brand, Product Name, and Price: ";
  while(std::cin >> newProduct)
    {
        auto newItem = std::make_unique<GroceryItem>(newProduct);
        shoppingCart.push_back(std::move(newItem));
        std::cout << "Item added to shopping cart: " << newProduct << "\n\n";
        std::cout << "Enter UPC, Product Brand, Product Name, and Price: ";
    }

    std::cout << "Here is an itemized list of the items in your shopping cart:\n";
    for (auto i = shoppingCart.crbegin(); i != shoppingCart.crend(); ++i) {
        std::cout << **i << '\n';
    }
  return 0;}