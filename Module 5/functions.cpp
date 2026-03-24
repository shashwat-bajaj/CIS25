#include <iostream>
#include <cmath>
#include "menu.h"
using namespace std;

void showMenu() {
    cout << "===== MENU =====\n";
    cout << "1. Add Two Numbers\n";
    cout << "2. Find Square of a Number\n";
    cout << "3. Exit\n";
}

void addNumbers() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Sum = " << num1 + num2 << endl;
}

void findSquare() {
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Square = " << pow(num, 2) << endl;
}

void displayMessage() {
    cout << "Exiting program. Goodbye!\n";
}
