#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
public:
    virtual void Access() = 0;
    virtual void SaveToFile(ofstream& out) const = 0;
    virtual ~User() {}
};

class RegularUser : public User {
public:
    void Access() override {
        cout << "Regular user access." << endl;
    }
    void SaveToFile(ofstream& out) const override {
        out << "RegularUser: Regular user access.\n";
    }
};

class Admin : public User {
public:
    void Access() override {
        cout << "Admin access." << endl;
    }
    void SaveToFile(ofstream& out) const override {
        out << "Admin: Admin access.\n";
    }
};

class Manager : public User {
public:
    void Access() override {
        cout << "Manager access." << endl;
    }
    void SaveToFile(ofstream& out) const override {
        out << "Manager: Manager access.\n";
    }
};

class Director : public User {
public:
    void Access() override {
        cout << "Director access." << endl;
    }
    void SaveToFile(ofstream& out) const override {
        out << "Director: Director access.\n";
    }
};

#endif // USER_H
