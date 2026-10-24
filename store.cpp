//code for store class here
#include "store.h"
#include <sstream>
using namespace std;

Store::Store()
{
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}
//Number of customers
void Store::num_customers(int c)
{
    num_customers_ = c;
}
int Store::num_customers()
{
    return num_customers_;
}
//Number of products
void Store::num_products(int p)
{
    num_products_ = p;
}
int  Store::num_products()
{
    return num_products_;
}
//Number of transactions
void Store::num_transactions(int t)
{
    num_transactions_ = t;
}
int Store::num_transactions()
{
    return num_transactions_;
}

bool Store::add_customer(Person customer)
{
    if(num_customers_ >= 100)
    {
        return false;
    }
    customers_[num_customers_++] = customer;
    return true;
}

bool Store::update_customer(int index, Person customer)
{
    if ((index < 0) || (index >= num_customers_))
    {
      return false;  
    }
    if (customers_[index].name() != customer.name())
    {
        return false;
    }
    customers_[index] = customer;
    return true;
}

Person Store::get_customer(int index)
{
    return customers_[index];
}

bool Store::add_product(product item)
{
    if(num_products_ >= 100)
    {
        return false;
    }
    products_[num_products_++] = item;
    return true;
}
product Store::get_product(int index)
{
    return products_[index];
}

bool Store::add_transaction(transaction ntransaction)
{
    if(num_transactions_ >= 100)
    {
        return false;
    }
    transactions_[num_transactions_++] = ntransaction;
    return true;
}
transaction Store::get_transaction(int index)
{
    return transactions_[index];
}

int Store::find_customer(Person cust)
{
    for (int i = 0; i < num_customers_; i++)
    {
        if (customers_[i].name() == cust.name())
        {
            return i;
        }
    }
    return -1;
}

bool Store::make_purchase(Person customer, product item, int amount)
{
    int idx = find_customer(customer);

    if (idx < 0 || amount <= 0 || num_transactions_ >= 100)
    {
      return false;  
    }
    Person stored = customers_[idx];
    credit_card cc = stored.person_credit_card();

    if (!cc.make_purchase(item.price * amount))
    {
        return false;
    }

    stored.person_credit_card(cc);
    customers_[idx] = stored;

    transaction t;
    t.transaction_number = num_transactions_ + 1;
    t.customer = stored;
    t.purchased_item = item;
    t.quantity = amount;
    return add_transaction(t);
}

string Store::product_info()
{
    string prod_info = "";

    for (int i = 0; i < num_products_; i++)
    {
        prod_info += products_[i].product_info() + "\n";
    }
    return prod_info;
}

string Store::transaction_info()
{
    string tran_info = "";
    for (int i = 0; i < num_transactions_; i++)
    {
        tran_info += transactions_[i].transaction_info() + "\n";
    }
    return tran_info;
}

string Store::customer_info()
{
    string cust_info = "";
    
    for (int i = 0; i < num_customers_; i++)
    {
        cust_info += customers_[i].person_info() + "\n";
    }
    return cust_info;
}

string Store::store_info()
{ 
    return "Customers: \n" + customer_info() +
           "Products: \n" + product_info() +
           "All Transactions: \n" + transaction_info();
}

string Store::purchase_history(Person customer)
{
    string tran_info = "";
    for (int i = 0; i < num_transactions_; i++)
    {
        tran_info += transactions_[i].transaction_info() + "\n";
    }
    return tran_info;
}
