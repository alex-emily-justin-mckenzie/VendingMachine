//
//  MakeChange.hpp
//  VendingMachine
//
//  Created by McKenzie Humann on 10/2/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#ifndef VendingMachineBank_hpp
#define VendingMachineBank_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "MoneyType.hpp"

class VendingMachineBank {
private:
    vector<MoneyType> bank;
    
public:
    void LoadBank();
    bool MakeChange(double inputMoney, double totalCost);
    void CheckBank();
    void SaveBank();
};

#endif /* MVendingMachineBank_hpp */
