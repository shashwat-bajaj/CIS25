#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "SIMPLE MENU" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        cout << "You selected: Check Balance" << endl;
    }
    else if (choice == 2) {
        cout << "You selected: Deposit Money" << endl;
    }
    else if (choice == 3) {
        cout << "You selected: Withdraw Money" << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
