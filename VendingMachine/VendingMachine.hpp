#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Snack.hpp"

class VendingMachine {
public:
	VendingMachine(string brandname = "BRAND NAME", string filename = "Product_Info.txt");
	void SetBrand(string brandName);
	void SetFile(string fileName);
	void DecrementQty(int snackLocation);
	string GetBrand() const;
	string GetFile() const;
	vector<Snack> GetSnacklist() const;
	void FillMachine(); //setter for snacklist
    void SaveMachine();
	void DisplayMachine() const;
	int GetSelection() const;
	bool vendingMachineCheck(int snackLocation);
    void PrintSnackInfo(int snackLocation);
    bool GetMoney(int snackLocation, double& userMoney);
    bool AnotherSelection();
private:
	vector<Snack> snacklist;
	string brand;
	string file;
	int width; //display width of vending machine--limit of code numbers
	int height; //display height of vending machine--limit of code letters
	//functions only accessed by FillMachine
	string getString(char x);
	string createCode(char myChar, int myNum);
};

#endif
