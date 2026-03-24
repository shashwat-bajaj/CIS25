#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// This class stores 6 fields from each row of the Titanic dataset.
class Passenger {
public:
    string passengerId;
    string survived;
    string pclass;
    string name;
    string sex;
    string age;
};

// This function splits one CSV row into fields.
// It handles commas inside quotation marks, which is important
// for the Titanic dataset because the Name field may contain commas.
vector<string> parseCSVLine(const string& line) {
    vector<string> fields;
    string currentField = "";
    bool insideQuotes = false;

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];

        if (ch == '"') {
            insideQuotes = !insideQuotes;
        } else if (ch == ',' && !insideQuotes) {
            fields.push_back(currentField);
            currentField = "";
        } else {
            currentField += ch;
        }
    }

    fields.push_back(currentField);
    return fields;
}

int main() {
    ifstream file("train.csv");

    // Check if the file opened correctly.
    if (!file.is_open()) {
        cout << "Error: Could not open train.csv" << endl;
        return 1;
    }

    string line;

    // Read and ignore the header row.
    getline(file, line);

    Passenger passengers[10];
    int count = 0;

    // Read up to 10 rows from the dataset.
    while (getline(file, line) && count < 10) {
        vector<string> fields = parseCSVLine(line);

        // The Titanic train.csv file has enough columns.
        // We use these 6 fields:
        // 0 = PassengerId
        // 1 = Survived
        // 2 = Pclass
        // 3 = Name
        // 4 = Sex
        // 5 = Age
        if (fields.size() >= 6) {
            passengers[count].passengerId = fields[0];
            passengers[count].survived = fields[1];
            passengers[count].pclass = fields[2];
            passengers[count].name = fields[3];
            passengers[count].sex = fields[4];
            passengers[count].age = fields[5];
            count++;
        }
    }

    file.close();

    // Display the loaded information in a readable format.
    cout << "===== TITANIC DATA (FIRST 10 ENTRIES) =====" << endl;

    for (int i = 0; i < count; i++) {
        cout << "Passenger " << i + 1 << endl;
        cout << "Passenger ID: " << passengers[i].passengerId << endl;
        cout << "Survived: " << passengers[i].survived << endl;
        cout << "Passenger Class: " << passengers[i].pclass << endl;
        cout << "Name: " << passengers[i].name << endl;
        cout << "Sex: " << passengers[i].sex << endl;
        cout << "Age: " << passengers[i].age << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
