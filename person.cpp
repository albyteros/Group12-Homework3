//code for person class here
#include "person.h"

Person::Person(string name, string phone, address person_address, credit_card person_credit_card)
{
    name_ = name;
    phone_ = phone;
    person_address_ = person_address;
    person_credit_card_ = person_credit_card;     
}

Person::Person()
{
    name_ = "";
    phone_ = "";
    person_credit_card_.cc_number = 0;
    person_credit_card_.limit = 0.0;
    person_credit_card_.current_balance = 0.0;
}
//name
void Person::name(string n)
{
    name_ = n;
}
string Person::name()
{
    return name_;
}
//phone
void Person::phone(string p)
{
    phone_ = p;
}
string Person::phone()
{
    return phone_;
}
//address
void Person::person_address(address a)
{
    person_address_ = a;
}
address Person::person_address()
{
    return person_address_;
}
//credit card
void Person::person_credit_card(credit_card c)
{
    person_credit_card_ = c;
}
credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

string Person::person_info()
{
    return "Name: " + name_ +
           "\nPhone: " + phone_ +
           "\nAddress: \n" + person_address_.address_info() +
           "Credit Card: \n" + person_credit_card_.credit_card_info();
}
