//implementation code for credit_card struct here
#include "credit_card.h"
#include <sstream>
#include <iomanip>
using namespace std;

bool credit_card::make_purchase(double purchase_amount)
{
    if((purchase_amount <= 0) || ((current_balance + purchase_amount) > limit))
    {
        return false;
    }
    current_balance += purchase_amount;
    return true;

}

bool credit_card::make_payment(double payment_amount)
{
    if((payment_amount <= 0)|| (payment_amount > current_balance))
    {
      return false;  
    }
    current_balance -= payment_amount;
    return true;

}

string credit_card::credit_card_info()
{
  ostringstream cc_str;
  cc_str << fixed << setprecision (2);
  cc_str << "Credit card number: " << cc_number
         << "\nCredit Card Limit $" << limit
         << "\nCurrent Balance: $" << current_balance;

    return cc_str.str();
}

