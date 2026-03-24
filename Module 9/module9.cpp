#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;

public:
    User(string uname) {
        username = uname;
    }

    virtual void accessLevel() {
        cout << "User: " << username << endl;
        cout << "General Access" << endl;
    }

    virtual ~User() {
    }
};

class Employee : public User {
public:
    Employee(string uname) : User(uname) {
    }

    void accessLevel() override {
        cout << "User: " << username << endl;
        cout << "Role: Employee" << endl;
        cout << "Permissions: View inventory" << endl;
    }
};

class Manager : public User {
public:
    Manager(string uname) : User(uname) {
    }

    void accessLevel() override {
        cout << "User: " << username << endl;
        cout << "Role: Manager" << endl;
        cout << "Permissions: View and update inventory" << endl;
    }
};

class Admin : public User {
public:
    Admin(string uname) : User(uname) {
    }

    void accessLevel() override {
        cout << "User: " << username << endl;
        cout << "Role: Admin" << endl;
        cout << "Permissions: Full access: add, update, delete inventory" << endl;
    }
};

int main() {
    Employee emp("john_employee");
    Manager mgr("sarah_manager");
    Admin adm("alex_admin");

    cout << "===== ROLE-BASED INVENTORY SYSTEM =====" << endl;
    cout << endl;

    emp.accessLevel();
    cout << "--------------------------" << endl;

    mgr.accessLevel();
    cout << "--------------------------" << endl;

    adm.accessLevel();
    cout << "--------------------------" << endl;

    return 0;
}
