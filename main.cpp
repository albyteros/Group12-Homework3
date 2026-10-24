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
	int num_cards;
	cred_card >> num_cards;
	if ((num_cards > MAX_SIZE) || (num_cards < 0))
	{
		cout<<"Wrong amount of creed cards"<<endl;
		return 1;
	}
	
	string cc_name[MAX_SIZE];
	

		
	
	//add to store and other variables

/*	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
	*/
	return 0;
}
