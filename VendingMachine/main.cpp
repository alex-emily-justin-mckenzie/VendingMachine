#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "VendingMachine.hpp"
#include "Snack.hpp"
#include "VendingMachineBank.hpp"
#include "MoneyType.hpp"
#include <fstream>

int main() {
    bool snackAvail;
    bool snackBought;
    bool changePossible;
    bool continueShopping = false;

    VendingMachine machine1("Roo Vending", "Product_Info.txt");
    machine1.FillMachine();
    
    VendingMachineBank vmb;
    vmb.LoadBank();
    
    do { // while the user interacts with the vending machine
        double userMoney = 0.0;
        machine1.DisplayMachine();
        int locateSnack = machine1.GetSelection(); //get desired snack from user
        snackAvail = machine1.vendingMachineCheck(locateSnack); //interact with user for transaction
        if (snackAvail) {
            machine1.PrintSnackInfo(locateSnack);
            snackBought = machine1.GetMoney(locateSnack, userMoney);
            if (snackBought) {
                double snackPrice = machine1.GetSnacklist().at(locateSnack).GetPrice();
                changePossible = vmb.MakeChange(userMoney, snackPrice);
                if (changePossible) {
                    machine1.DecrementQty(locateSnack); // decrementation of quantity
                    cout << "Congratulations! You just bought a " << machine1.GetSnacklist().at(locateSnack).GetName() << endl;
                }
            }
        }
        
        continueShopping = machine1.AnotherSelection();
        
    } while(continueShopping);
    
    vmb.SaveBank();
    machine1.SaveMachine();
    
    return 0;
}
