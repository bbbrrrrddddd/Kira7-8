#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "Technician.h"
#include "Operator.h"
#include "User.h"

using namespace std;

void SaveAmateursToFile(const vector<RadioAmateur*>& amateurs) {
    ofstream out("amateurs.txt");
    if (out.is_open()) {
        for (auto amateur : amateurs) {
            amateur->SaveToFile(out);
        }
        out.close();
    }
}

void LoadAmateursFromFile(vector<RadioAmateur*>& amateurs) {
    ifstream in("amateurs.txt");
    if (in.is_open()) {
        string type;
        while (in >> type) {
            string name, callSign, location;
            in >> ws; getline(in, name);
            in >> callSign;
            in >> ws; getline(in, location);

            if (type == "Technician") {
                string level;
                in >> level;
                amateurs.push_back(new Technician(name, callSign, location, level));
            }
            else if (type == "Operator") {
                int years;
                in >> years;
                amateurs.push_back(new Operator(name, callSign, location, years));
            }
        }
        in.close();
    }
}

RadioAmateur* FindByCallSign(const vector<RadioAmateur*>& amateurs, const string& callSign) {
    for (auto amateur : amateurs) {
        if (amateur->getCallSign() == callSign) return amateur;
    }
    return nullptr;
}

int main() {
    vector<RadioAmateur*> amateurs;
    LoadAmateursFromFile(amateurs);

    char choice;

    cout << "Select your access level:\n[1] RegularUser\n[2] Admin\n[3] Manager\n[4] Director\nChoice: ";
    cin >> choice;
    User* user;
    switch (choice) {
    case '1': user = new RegularUser(); break;
    case '2': user = new Admin(); break;
    case '3': user = new Manager(); break;
    case '4': user = new Director(); break;
    default: user = new RegularUser(); break;
    }

    do {
        cout << "\n-------- Radio Amateur Directory --------\n";
        cout << "[1] Add Technician\n";
        cout << "[2] Add Operator\n";
        cout << "[3] Display All\n";
        cout << "[4] Delete by Call Sign\n";
        cout << "[5] Filter Operators with >10 Years Experience\n";
        cout << "[e] Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == '1') {
            string name, callSign, location, certLevel;
            cout << "Enter Name: "; cin >> ws; getline(cin, name);
            cout << "Enter Call Sign: "; cin >> callSign;
            cout << "Enter Location: "; cin >> ws; getline(cin, location);
            cout << "Enter Certification Level: "; cin >> certLevel;
            amateurs.push_back(new Technician(name, callSign, location, certLevel));
        }
        else if (choice == '2') {
            string name, callSign, location;
            int years;
            cout << "Enter Name: "; cin >> ws; getline(cin, name);
            cout << "Enter Call Sign: "; cin >> callSign;
            cout << "Enter Location: "; cin >> ws; getline(cin, location);
            cout << "Enter Years of Experience: "; cin >> years;
            amateurs.push_back(new Operator(name, callSign, location, years));
        }
        else if (choice == '3') {
            cout << "\n-------- All Radio Amateurs --------\n";
            for (auto amateur : amateurs) {
                amateur->DisplayInfo(user);
                cout << "-------------------------------------\n";
            }
        }
        else if (choice == '4') {
            if (dynamic_cast<Admin*>(user) || dynamic_cast<Manager*>(user)) {
                string target;
                cout << "Enter call sign to delete: "; cin >> target;
                auto it = remove_if(amateurs.begin(), amateurs.end(), [&](RadioAmateur* a) {
                    if (a->getCallSign() == target) {
                        delete a;
                        return true;
                    }
                    return false;
                    });
                amateurs.erase(it, amateurs.end());
            }
            else {
                cout << "Access Denied. Only Admin/Manager can delete.\n";
            }
        }
        else if (choice == '5') {
            cout << "\nOperators with more than 10 years of experience:\n";
            for (auto amateur : amateurs) {
                Operator* op = dynamic_cast<Operator*>(amateur);
                if (op && op->getYearsOfExperience() > 10) {
                    op->DisplayInfo(user);
                }
            }
        }

    } while (choice != 'e');

    SaveAmateursToFile(amateurs);
    ofstream outFile("users.txt");
    if (outFile.is_open()) {
        user->SaveToFile(outFile);
        outFile.close();
    }

    for (auto amateur : amateurs) delete amateur;
    delete user;
    return 0;
}
