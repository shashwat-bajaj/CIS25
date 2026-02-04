#include <iostream>                     // Fixed: Correct header include
using namespace std;                    // Fixed: Proper namespace usage

int main() {                            // Fixed: Correct main function syntax

    float n1, n2, n3;                  // Fixed: Proper variable declaration

    cout << "Enter three numbers: ";   // Fixed: Correct output operator
    cin >> n1 >> n2 >> n3;             // Fixed: Correct input syntax

    // Fixed: Correct comparison operator and nested if logic
    if (n1 >= n2) {
        if (n1 >= n3) {
            cout << "Largest number: " << n1 << endl;   // Fixed: Correct output variable
        } else {
            cout << "Largest number: " << n3 << endl;   // Fixed: Correct output variable
        }
    }
    else {
        if (n2 >= n3) {
            cout << "Largest number: " << n2 << endl;   // Fixed: Correct output variable
        } else {
            cout << "Largest number: " << n3 << endl;   // Fixed: Correct output variable
        }
    }

    return 0;                           // Fixed: Proper program termination
}
