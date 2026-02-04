#include <iostream>
#include <string>
using namespace std;

int main() {
    string itemName;
    int quantity;
    float cost;
    float totalCost;

    cout << "Enter item name: ";
    cin >> itemName;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter cost: ";
    cin >> cost;

    totalCost = quantity * cost;
  
    cout << "\nTotal cost for " << itemName << ": $" << totalCost << endl;

    return 0;
}
