#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

void sortPatientsByID(Patient* patients, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (patients[j].id > patients[j + 1].id) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Patient* patients, int count, int searchID) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID) {
            return mid;
        } else if (patients[mid].id < searchID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void loadPatientsFromFile(Patient* patients, int& count) {
    ifstream inFile("patients.txt");

    if (!inFile.is_open()) {
        return;
    }

    while (inFile >> patients[count].id
                  >> patients[count].name
                  >> patients[count].age
                  >> patients[count].gender
                  >> patients[count].diagnosis) {
        count++;
    }

    inFile.close();
    sortPatientsByID(patients, count);
}

void addPatient(Patient* patients, int& count, int maxSize) {
    if (count >= maxSize) {
        cout << "Patient list is full." << endl;
        return;
    }

    cout << "Enter Patient ID: ";
    cin >> patients[count].id;

    cout << "Enter Name: ";
    cin >> patients[count].name;

    cout << "Enter Age: ";
    cin >> patients[count].age;

    cout << "Enter Gender: ";
    cin >> patients[count].gender;

    cout << "Enter Diagnosis: ";
    cin >> patients[count].diagnosis;

    count++;
    sortPatientsByID(patients, count);

    cout << "Patient added successfully." << endl;
}

void displayPatients(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patient records found." << endl;
        return;
    }

    cout << "Patient Records" << endl;

    for (int i = 0; i < count; i++) {
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
        cout << "--------------------------" << endl;
    }
}

void searchPatient(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patient records found." << endl;
        return;
    }

    int searchID;
    cout << "Enter patient ID to search: ";
    cin >> searchID;

    int index = binarySearch(patients, count, searchID);

    if (index != -1) {
        cout << "Patient Found" << endl;
        cout << "ID: " << patients[index].id << endl;
        cout << "Name: " << patients[index].name << endl;
        cout << "Age: " << patients[index].age << endl;
        cout << "Gender: " << patients[index].gender << endl;
        cout << "Diagnosis: " << patients[index].diagnosis << endl;
    } else {
        cout << "Patient not found." << endl;
    }
}

void updatePatient(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patient records found." << endl;
        return;
    }

    int searchID;
    cout << "Enter patient ID to update: ";
    cin >> searchID;

    int index = binarySearch(patients, count, searchID);

    if (index != -1) {
        cout << "Enter new Name: ";
        cin >> patients[index].name;

        cout << "Enter new Age: ";
        cin >> patients[index].age;

        cout << "Enter new Gender: ";
        cin >> patients[index].gender;

        cout << "Enter new Diagnosis: ";
        cin >> patients[index].diagnosis;

        cout << "Patient updated successfully." << endl;
    } else {
        cout << "Patient not found." << endl;
    }
}

void savePatientsToFile(Patient* patients, int count) {
    ofstream outFile("patients.txt");

    if (!outFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outFile << patients[i].id << " "
                << patients[i].name << " "
                << patients[i].age << " "
                << patients[i].gender << " "
                << patients[i].diagnosis << endl;
    }

    outFile.close();
    cout << "Patients saved to file." << endl;
}

void showMenu() {
    cout << "\nHospital Patient System" << endl;
    cout << "1. Add Patient" << endl;
    cout << "2. Display Patients" << endl;
    cout << "3. Search Patient" << endl;
    cout << "4. Update Patient" << endl;
    cout << "5. Save Patients" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    const int MAX_PATIENTS = 100;
    Patient* patients = new Patient[MAX_PATIENTS];
    int count = 0;
    int choice;

    loadPatientsFromFile(patients, count);

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(patients, count, MAX_PATIENTS);
                break;
            case 2:
                displayPatients(patients, count);
                break;
            case 3:
                searchPatient(patients, count);
                break;
            case 4:
                updatePatient(patients, count);
                break;
            case 5:
                savePatientsToFile(patients, count);
                break;
            case 6:
                savePatientsToFile(patients, count);
                cout << "Good Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    delete[] patients;
    return 0;
}
