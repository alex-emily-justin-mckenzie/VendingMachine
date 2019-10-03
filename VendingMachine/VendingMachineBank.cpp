//
//  MakeChange.cpp
//  VendingMachine
//
//  Created by McKenzie Humann on 10/2/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#include "VendingMachineBank.hpp"
#include "MoneyType.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

// user "inputs" money
// each additional input adds to the total amount they have inserted
// calculate the necessary change
// given the vending machine 'bank', select what coins/dollars to return
// if not enough money is given, ask for more money or to cancel transaction

void VendingMachineBank::LoadBank() {
    vector<MoneyType> newBank;
    
    ifstream startBank("VendingMachineStartingBank.txt");
    if (startBank.is_open()) {
        while (!startBank.eof())  {
            string tempName;
            double tempValue;
            int tempCount;
            
            startBank >> tempName;
            startBank >> tempValue;
            startBank >> tempCount;
            
            MoneyType moneyType(tempName, tempValue, tempCount);
            
            newBank.push_back(moneyType);
        }
        startBank.close();
    }
    else {
        cout << "Unable to open file";
    }
    
    bank = newBank;
}

void VendingMachineBank::CheckBank() {
    for (int i = 0; i < bank.size(); ++i) {
        cout << bank.at(i).GetCount() << " ";
        cout << bank.at(i).GetName() << "s " << endl;
    }
}

void VendingMachineBank::MakeChange(double inputMoney, double totalCost) {
    // will check that inputMoney is greater or equal to totalCost in other function
    bool changePossible = true;
    double change;
    double remainingChange;
    vector<int> moneyChange;
    
    change = totalCost - inputMoney;
    remainingChange = change;
    
    for (int i = 0; i < bank.size(); ++i) {
        int tempCount;
        tempCount = floor(remainingChange / bank.at(i).GetValue());
        moneyChange.push_back(bank.at(i).SubtractCount(tempCount));
        remainingChange -= moneyChange.at(i) * bank.at(i).GetValue();
    }
    
    if (remainingChange > 0.01) {
        changePossible = false;
        cout << "Sorry, there is not enough money in the vending machine to make your change." << endl;
    }
    else {
        if (change < 0.001) {
            cout << "No change." << endl;
        }
        else {
            cout << "Your change is: " << endl;
            for (int i = 0; i < bank.size(); ++i) {
                if (moneyChange.at(i) > 0) {
                    cout << moneyChange.at(i) << " ";
                    cout << bank.at(i).GetName() << "s" << endl;
                }
            }
            cout << "for a total of $" << change << endl;
        }

    }

}

