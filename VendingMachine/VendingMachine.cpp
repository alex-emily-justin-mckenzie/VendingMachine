#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

#include "VendingMachine.hpp"
#include "VendingMachineBank.hpp"

VendingMachine::VendingMachine(string brandName, string fileName) {
	brand = brandName;
	file = fileName;
}

void VendingMachine::SetBrand(string brandName) { brand = brandName; }

void VendingMachine::SetFile(string fileName) { file = fileName; }

void VendingMachine::DecrementQty(int snackLocation) { snacklist.at(snackLocation).DecrementQty(); }

int VendingMachine::GetSelection() const {
	string userInput;
	bool foundSnack = false;
	int location;
	while (!foundSnack) {
		cout << "Choose your snack: ";
		cin >> userInput;
		cout << endl;
		for (unsigned int i = 0; i < snacklist.size(); ++i) {
			if (snacklist.at(i).GetCode() == userInput) {
				location = i;
				foundSnack = true;
				break;
			}
			else { foundSnack = false; }
		}
		if (!foundSnack) { cout << "Invalid selection" << endl; }
	}
	return location;
}

string VendingMachine::GetBrand() const { return brand; }

string VendingMachine::GetFile() const { return file; }

vector<Snack> VendingMachine::GetSnacklist() const { return snacklist; }

string VendingMachine::getString(char x) {
	string s(1, x);
	return s;
}

string VendingMachine::createCode(char myChar, int myNum) {
	string myCharStr = getString(myChar); //eg "A"
	string myNumStr = to_string(myNum); //eg "1"
	string myCode = myCharStr + myNumStr; //eg "A1"
	return myCode;
}

void VendingMachine::FillMachine() {
	ifstream inFS;
	string name, code;
	double price;
	int quantity;
	char codeChar = 'A'; //starting letter of codes
	int codeNum = 1; //starting number of codes
	const int WIDTH = 4; //last number of codes
	Snack currSnack;

	inFS.open(file); //write product file into snacklist vector
    while (!inFS.eof()) {
        code = createCode(codeChar, codeNum);
        if (codeNum <= WIDTH - 1) { codeNum += 1; }
        else { codeNum = 1; codeChar += 1; } //resets next row to 1, goes to next ltr
        //read in
        getline(inFS, name, '\t');
        inFS >> price >> quantity;
        inFS.ignore();
        Snack currSnack(name, code, price, quantity);
        snacklist.push_back(currSnack);
    }
	inFS.close();
    
}

void VendingMachine::SaveMachine() {
    ofstream outFS;
    
    outFS.open(file, ios::out | ios::trunc);
    outFS << setprecision(2) << fixed;
    for (int i = 0; i < snacklist.size() - 1; ++i) {
        outFS << snacklist.at(i).GetName() << "\t";
        outFS << snacklist.at(i).GetPrice() << " ";
        outFS << snacklist.at(i).GetQuantity() << endl;
    }
    
    outFS << snacklist.at(snacklist.size() - 1).GetName() << "\t";
    outFS << snacklist.at(snacklist.size() - 1).GetPrice() << " ";
    outFS << snacklist.at(snacklist.size() - 1).GetQuantity();

    outFS.close();
    
}

void VendingMachine::DisplayMachine() const {
	vector<Snack> displayVector(20); //Vending machine can only hold 20 snacks
	int limit = (GetSnacklist().size() < 20) ? GetSnacklist().size() : displayVector.size();//prevent out-of-range if less than 20 snacks
	for (int i = 0; i < limit; ++i) {
		displayVector.at(i) = GetSnacklist().at(i);
	}
	cout << "_____________________" << endl;
	cout << ".<---" << GetBrand() << "--->." << endl;
	cout << "|._________________.|" << endl;
	cout << "|===================|" << endl;
	cout << "|--[" << displayVector.at(0).GetQuantity() 
		 << "]-["  << displayVector.at(1).GetQuantity()
		 << "]-["  << displayVector.at(2).GetQuantity() 
		 << "]-["  << displayVector.at(3).GetQuantity()
		 << "]--|" << endl;
	cout << "|--A1--A2---A3--A4--|" << endl;
	cout << "|-------------------|" << endl;
	cout << "|--[" << displayVector.at(4).GetQuantity()
		 << "]-["  << displayVector.at(5).GetQuantity()
		 << "]-["  << displayVector.at(6).GetQuantity()
		 << "]-["  << displayVector.at(7).GetQuantity()
		 << "]--|" << endl;
	cout << "|--B1--B2---B3--B4--|" << endl;
	cout << "|-------------------|" << endl;
	cout << "|--[" << displayVector.at(8).GetQuantity()
		 << "]-["  << displayVector.at(9).GetQuantity()
		 << "]-["  << displayVector.at(10).GetQuantity()
		 << "]-["  << displayVector.at(11).GetQuantity()
		 << "]--|" << endl;
	cout << "|--C1--C2---C3--C4--|" << endl;
	cout << "|-------------------|" << endl;
	cout << "|--[" << displayVector.at(12).GetQuantity()
		 << "]-["  << displayVector.at(13).GetQuantity()
		 << "]-["  << displayVector.at(14).GetQuantity()
		 << "]-["  << displayVector.at(15).GetQuantity()
		 << "]--|" << endl;
	cout << "|--D1--D2---D3--D4--|" << endl;
	cout << "|-------------------|" << endl;
	cout << "|--[" << displayVector.at(16).GetQuantity()
		 << "]-["  << displayVector.at(17).GetQuantity()
		 << "]-["  << displayVector.at(18).GetQuantity()
		 << "]-["  << displayVector.at(19).GetQuantity()
		 << "]--|" << endl;
	cout << "|--E1--E2---E3--E4--|" << endl;
	cout << "|-------------------|" << endl;
	cout << "|--_______________--|" << endl;
	cout << "|--| ___________ |--|" << endl;
	cout << "|===================|" << endl;
	cout << "'-------------------'" << endl;
	cout << " ||               || " << endl << endl;
}
// returns true or false if successful transaction or not
bool VendingMachine::vendingMachineCheck(int snackLocation) {
    
    if (GetSnacklist().at(snackLocation).GetQuantity() == 0) {
        cout << "We don\'t have any more " << GetSnacklist().at(snackLocation).GetName() << "." << endl;
        return false;
    }
    else {
        return true;
    }
}
    
void VendingMachine::PrintSnackInfo(int snackLocation) {
    cout << fixed << setprecision(2);
    cout << "Snack : " << GetSnacklist().at(snackLocation).GetName() << endl;
    cout << "Price : $" << GetSnacklist().at(snackLocation).GetPrice() << endl << endl;
}

bool VendingMachine::GetMoney(int snackLocation, double& userMoney) {
    bool snackBought = true;
    double snackPrice = GetSnacklist().at(snackLocation).GetPrice();
    char option;
    double additionalInput = 0;

    cout << "Please enter your money" << endl;
    cout << "$: ";
    cin >> userMoney;
    
    while (cin.fail()) { // while we don't get a valid data type
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInput is invalid.\n Please try again. \n";
        cin >> userMoney;
    }
    
    while (option != 'q' && snackPrice > userMoney) {
        cout << "You have not entered enough money to buy your item." << endl;
        cout << "Hit q to cancel the transaction or any other letter to continue.";
        cout << endl;
        
        cin >> option;
        option = tolower(option);
        
        if (option != 'q') {
            additionalInput = 0;
            cout << "Please enter additional money to be added to your total input"<< endl;
            cin >> additionalInput;
            userMoney += additionalInput;
            snackBought = true;
        }
        else {
            snackPrice = 0;
            snackBought = false;
        }
    }

    return snackBought;
}

bool VendingMachine::AnotherSelection() {
    bool continueShopping;
    cout << "Do you want to choose another snack? Enter (Y)es or (N)o." << endl;
    char option;
    cin >> option;
    option = toupper(option);
    if (option == 'Y') {
        continueShopping = true;
    }
    else {
        cout << "Thank you! Have a nice day." << endl;
        continueShopping = false;
    }
    return continueShopping;
}
    

