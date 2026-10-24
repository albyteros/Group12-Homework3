//code for product struct here
#include "product.h"
#include <sstream>
#include <iomanip>
std::string product::product_info()
{
    //format string for price
    std::ostringstream price_str;
    price_str<<std::fixed<<std::setprecision(2);
    price_str >> price;

    return "Product Name: " + name  + 
    "\nDescription: " + description +
     "\nPrice: $" + price_str.str();

}


