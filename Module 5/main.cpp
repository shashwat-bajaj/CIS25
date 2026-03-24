#include <iostream>
#include "menu.h"
using namespace std;

int main() {
    int option;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1:
                addNumbers();
                break;
            case 2:
                findSquare();
                break;
            case 3:
                displayMessage();
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

        cout << endl;

    } while(option != 3);

    return 0;
}
