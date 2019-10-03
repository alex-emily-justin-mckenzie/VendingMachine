//
//  MoneyType.cpp
//  VendingMachine
//
//  Created by McKenzie Humann on 10/2/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#include "MoneyType.hpp"
#include <string>
#include <stdio.h>

using namespace std;


MoneyType::MoneyType (string newName, double newValue, int newCount) {
    name = newName;
    value = newValue;
    count = newCount;
}

string MoneyType::GetName() {
    return name;
}

int MoneyType::GetCount() {
    return count;
}

double MoneyType::GetValue() {
    return value;
}

int MoneyType::SubtractCount(int subAmount) {
    int newCount;
    newCount = count - subAmount;
    if (newCount < 0) {
        int i = 0;
        while (newCount >= 0) {
            newCount = count - i;
            ++i;
        }
        subAmount = i;
    }
    count -= subAmount;
    
    return subAmount;
}




