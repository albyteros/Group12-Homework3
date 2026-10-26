//code for product struct here
#include "product.h"
#include <sstream>
#include <iomanip>
using namespace std;
string product::product_info()
{
    //format string for price
    ostringstream price_str;
    price_str << fixed << setprecision(2);
    price_str <<  price;

    return "Name: " + name  + 
    "\nDescription: " + description +
     "\nPrice: $" + price_str.str();

}


