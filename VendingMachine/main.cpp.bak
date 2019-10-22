//
//  main.cpp
//  VendingMachine


#include <iostream>
#include "VendingMachineBank.hpp"
#include "MoneyType.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// BASIC FUNCTIONALITY:
// read in file with snack info
// store snack info
// user interface where they pick snack
// if snack is available, ask for money
// user "inputs" money, use makechange function to give back change
// ask for more money if not enough
// "output" snack

// REACH GOALS:
// offer snack suggestions
// ability to buy more than one snack at a time


int main() {
    VendingMachineBank vendingBank;
    vendingBank.LoadBank(); // only need to do once at the beginning
    // vendingBank.CheckBank();
    
    double totalCost = 10;
    double inputAmount = 9;
    char option;
    
    while (totalCost > inputAmount) {
        double additionalInput = 0;

        do {
            cout << "You have not entered enough money to buy your item." << endl;
            cout << "Hit q to cancel the transaction or any other key to continue." << endl;
            cin >> option;
            option = tolower(option);
            if (option != 'q') {
                cout << "Please enter additional money to be added to your total input" << endl;
                cin >> additionalInput;
                inputAmount += additionalInput;
            }
            else {
                abort();
            }
            
        } while (option != 'q' && totalCost > inputAmount);
    }
    // input totalCost, inputAmount
    vendingBank.MakeChange(totalCost, inputAmount);

    
    return 0;
}
