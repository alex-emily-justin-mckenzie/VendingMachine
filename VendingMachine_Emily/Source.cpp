#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "VendingMachine.h"
#include "Snack.h"

int main() {
	VendingMachine machine1;
	cout << machine1.GetBrand() << endl;
	cout << machine1.GetFile() << endl;
	machine1.SetFile("Myfile.txt");
	machine1.SetBrand("Super Awesome Vending");
	cout << machine1.GetBrand() << endl;
	cout << machine1.GetFile() << endl;
	machine1.SetFile("Product_Info.txt");
	machine1.FillMachine();
	
	for (unsigned int i = 0; i < machine1.snacklist.size(); ++i) {
		cout << machine1.snacklist.at(i).GetCode() << endl;
		cout << machine1.snacklist.at(i).GetName() << endl;
		cout << machine1.snacklist.at(i).GetPrice() << endl;
		cout << machine1.snacklist.at(i).GetQuantity() << endl << endl;
	}

	cout << "Old quantity: " << machine1.snacklist.at(1).GetQuantity() << endl;
	machine1.snacklist.at(1).DecrementQty();
	cout << "New quantity: " << machine1.snacklist.at(1).GetQuantity();

	return 0;
}