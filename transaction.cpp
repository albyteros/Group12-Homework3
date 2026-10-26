//code for transaction struct here
#include "transaction.h"
#include <sstream>
using namespace std;
string transaction::transaction_info()
{
    //format 
    ostringstream tran_str;
    ostringstream quan_str;
    ostringstream purc_str;
    tran_str << transaction_number;
    quan_str << quantity;



    return "Transaction #: " + tran_str.str()  +
    "\nCustomer: \n" + customer.person_info() +
     "\nProduct: \n" + purchased_item.product_info() +
     "\nQuantity: " + quan_str.str();
}