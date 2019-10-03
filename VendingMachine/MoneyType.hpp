//
//  MoneyType.hpp
//  VendingMachine
//
//  Created by McKenzie Humann on 10/2/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#ifndef MoneyType_hpp
#define MoneyType_hpp

#include <stdio.h>
#include <string>

using namespace std;

class MoneyType {
private:
    string name;
    double value;
    int count;
    
public:
    MoneyType(string name, double value, int count);
    string GetName();
    int GetCount();
    double GetValue();
    int SubtractCount(int subAmount);
};

#endif /* MoneyType_hpp */
