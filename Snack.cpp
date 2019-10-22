#include <string>
using namespace std;

#include "Snack.hpp"

Snack::Snack(string itemName, string itemCode, double itemPrice, int itemQuantity) {
	name = itemName;
	code = itemCode;
	price = itemPrice;
	quantity = itemQuantity;
}
void Snack::SetName(string itemName) { name = itemName; }
void Snack::SetCode(string itemCode) { code = itemCode; }
void Snack::SetPrice(double itemPrice) { price = itemPrice; }
void Snack::SetQuantity(int itemQuantity) { quantity = itemQuantity; }
void Snack::DecrementQty() { quantity -= 1; }
string Snack::GetName() const { return name; }
string Snack::GetCode() const { return code; }
double Snack::GetPrice() const { return price; }
int Snack::GetQuantity() const { return quantity; }
