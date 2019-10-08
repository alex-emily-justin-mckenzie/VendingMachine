#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Snack.h"

class VendingMachine {
public:
	VendingMachine(string brandname = "BRAND NAME", string filename = "Product_Info.txt");
	void SetBrand(string brandName);
	void SetFile(string fileName);
	string GetBrand() const;
	string GetFile() const;
	void FillMachine(); //setter for snacklist
	vector<Snack> snacklist;
private:
	string brand;
	string file;
	//functions only accessed by FillMachine
	string getString(char x);
	string createCode(char myChar, int myNum);
};

#endif