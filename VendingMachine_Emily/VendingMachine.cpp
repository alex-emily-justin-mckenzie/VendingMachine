#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "VendingMachine.h"

VendingMachine::VendingMachine(string brandName, string fileName) {
	brand = brandName;
	file = fileName;
}
void VendingMachine::SetBrand(string brandName) { brand = brandName; }
void VendingMachine::SetFile(string fileName) { file = fileName; }
string VendingMachine::GetBrand() const { return brand; }
string VendingMachine::GetFile() const { return file; }
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
	const int WIDTH = 4; //display width of vending machine--limit of code numbers
	char codeChar = 'A'; //starting letter of codes
	int codeNum = 1; //starting number of codes
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
		currSnack.SetName(name);
		currSnack.SetCode(code);
		currSnack.SetPrice(price);
		currSnack.SetQuantity(quantity);
		snacklist.push_back(currSnack);
	}
	inFS.close();
}