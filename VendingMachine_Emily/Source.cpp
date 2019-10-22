#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "VendingMachine.hpp"
#include "Snack.hpp"
#include "VendingMachineBank.hpp"

int main() {
	bool boolCheck = true;
	VendingMachine machine1;
	machine1.SetBrand("Roo Vending");
	machine1.FillMachine();

	
	while (boolCheck) { // while the user interacts with the vending machine
		machine1.DisplayMachine();
		int locateSnack = machine1.GetSelection(); //get desired snack from user
		boolCheck = machine1.vendingMachineCheck(locateSnack); //interact with user for transaction
		if (boolCheck) { // if transaction was successful
			machine1.DecrementQty(locateSnack); // decrementation of quantity
		}
	}
	return 0;
}
