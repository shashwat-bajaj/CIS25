#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    double getTotalPrice() {
        return price * quantity;
    }
};

void showMenu();
void addItemToCart();
void viewCheckout();

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addItemToCart();
                break;
            case 2:
                viewCheckout();
                break;
            case 3:
                cout << "Thank you for shopping!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 3);

    return 0;
}

void showMenu() {
    cout << "===== SHOPPING CART MENU =====" << endl;
    cout << "1. Add item to cart" << endl;
    cout << "2. View checkout" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}

void addItemToCart() {
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;

    cout << "Enter item price: ";
    cin >> item.price;

    cout << "Enter item quantity: ";
    cin >> item.quantity;

    ofstream outFile("cart.txt", ios::app);

    if (outFile.is_open()) {
        outFile << item.name << " " << item.price << " " << item.quantity << endl;
        outFile.close();
        cout << "Item added to cart." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void viewCheckout() {
    ifstream inFile("cart.txt");
    Item item;
    double grandTotal = 0.0;

    if (!inFile.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    cout << "===== CHECKOUT =====" << endl;

    while (inFile >> item.name >> item.price >> item.quantity) {
        double total = item.getTotalPrice();
        grandTotal += total;

        cout << item.name << " - $" 
             << fixed << setprecision(2) << item.price
             << " x " << item.quantity
             << " = $" << total << endl;
    }

    cout << "Total: $" << fixed << setprecision(2) << grandTotal << endl;

    inFile.close();
}
