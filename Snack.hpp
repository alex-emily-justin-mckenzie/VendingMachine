#ifndef SNACK_H
#define SNACK_H

class Snack {
public:
	Snack(string itemName = "none", string itemCode = "none", double itemPrice = 0.0, int itemQuantity = 0);
	void SetName(string itemName);
	void SetCode(string itemCode);
	void SetPrice(double itemPrice);
	void SetQuantity(int itemQuantity);
	void DecrementQty();
	string GetName() const;
	string GetCode() const;
	double GetPrice() const;
	int GetQuantity() const;
private:
	string name;
	string code;
	double price;
	int quantity;
};

#endif
