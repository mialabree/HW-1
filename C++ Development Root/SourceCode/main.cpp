int main()
{
  std::cout << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information." << std::endl;
  std::cout << "enclose string entries in quotes, separate fields with comas" << std::endl;
  std::cout << "for example:  '00016000306707', 'Betty Crocker', 'Betty Crocker Double Chocolate Chunk Cookie Mix', 17.19" << std::endl;
  std::cout << "Enter CTL-Z (Windows) or CTL-D (Linux) to quit" << std::endl;

  std::vector<std::unique_ptr<GroceryItem>>itemList;
  std::string inputLine;

  while(std::cin >> inputLine)
  {
    std::cout << "Enter UPC, Product Brand, Product Name, and Price" << std::endl;
    auto newItem = std::make_unique <GroceryItem> (inputLine);
    itemList.push_back(std::move(newItem));
    std::cout << "Item added to shopping cart:" << inputLine << '\n';
  }

  std::cout << "Here is an itemized list of the items in your shopping cart:\n"

  for(std::vector<std::unique_ptr<GroceryItem>>::const_reverse_iterator i = shoppingCart.crbegin(); i != shoppingCart.crend(); ++i) {
    std::cout << i << '\n';
  }
  return 0;
}

