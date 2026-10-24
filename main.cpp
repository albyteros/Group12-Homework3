#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{

	//import from text files
	ifstream cred_card ("credit_card.txt");
	ifstream people ("people.txt");
	ifstream products ("products.txt");


	if (!cred_card.is_open())
	{
		cout<<"Couldn't open credit_card.txt"<<endl;
		return 1;
	}
	if(!people.is_open())
	{
		cout<<"Couldn't open people.txt"<<endl;
		return 1;
	}
	if(!products.is_open())
	{
		cout<<"Couldn't open products.txt"<<endl;
		return 1;
	}

	const int MAX_SIZE = 100;

	//Credit Card
	int num_cards;
	string line;
	getline(cred_card, line);
	num_cards = stoi(line);
	if ((num_cards > MAX_SIZE) || (num_cards < 0))
	{
		cout<<"Wrong amount of credit cards"<<endl;
		return 1;
	}
	
	string cc_name[MAX_SIZE];
	credit_card cards[MAX_SIZE];
	for (int i = 0; i < num_cards; i++)
	{
		getline(cred_card, cc_name[i]);

		getline(cred_card, line);
		cards[i].cc_number = stoi(line);

		getline(cred_card, line);
		cards[i].limit = stod(line);

		getline(cred_card, line);
		cards[i].current_balance = stod(line);
	}

	//People
	Store store1;
	getline(people, line);
	int num_people = stoi(line);
	if (num_people < 0 || num_people > MAX_SIZE)
	{
		cout << "Wrong amount of people" << endl;
		return 1;
	}

	for (int i = 0; i < num_people; i++)
	{
		string name;
		string phone;
		address addr;

		getline(people, name);
		getline(people, phone);
		getline(people, addr.address_line1);
		getline(people, addr.address_line2);
		getline(people, addr.city);
		getline(people, addr.state);
		getline(people, addr.zip);

		credit_card card = {0, 0.0, 0.0};
		for (int i = 0; i < num_cards; i++)
		{
			if (cc_name[i] == name)
			{
				card = cards[i];
				break;
			}
		}
		store1.add_customer(Person(name, phone, addr, card));
	}

	//products
	getline(products, line);
	int num_prods = stoi(line);
	
	if (num_prods < 0 || num_prods > MAX_SIZE)
	{
		cout << "Wrong amount of products" << endl;
		return 1;
	}
	for (int i = 0; i < num_prods; i++)
	{
		product p;
		getline(products, p.name);
		getline(products, p.description);
		getline(products, line);
		p.price = stod(line);
		store1.add_product(p);
	}
	
	

		
	
	

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions
	int ran_num = rand() % 89 + 11;
	
	for (int i = 0; i < ran_num; i++)
	{
		Person cust = store1.get_customer(rand() % store1.num_customers());
		product item = store1.get_product(rand() % store1.num_products());
		int qty = 1 + rand() % 10;
		if(store1.make_purchase(cust, item, qty))
		{
			int tran = store1.num_transactions() - 1;
			transaction t = store1.get_transaction(tran);

			cout << "Successfull transaction!" << endl;
			cout <<	"Transaction Details: " << endl;
			cout << t.transaction_info() << endl;
		}
		else
		{
			Person per = store1.get_customer(store1.find_customer(cust));
			cout << "Unsuccessfull transaction!" << endl;
			cout << "Transaction Details: " << endl;
			cout << "Person: " << per.person_info() << endl;
			cout << "Product: \n" << item.product_info() << endl;
			cout << "Purchase Quantity: " << qty << endl;
		}
	}
	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
	cred_card.close();
	people.close();
	products.close();
	return 0;
}
