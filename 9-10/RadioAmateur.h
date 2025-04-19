#ifndef RADIOAMATEUR_H
#define RADIOAMATEUR_H

#include <iostream>
#include <string>
#include "User.h" // ������ ��� ������� �� ����� User

using namespace std;

class RadioAmateur {
protected:
    string Name;
    string CallSign;
    string Location;

public:
    RadioAmateur(string name, string callSign, string location)
        : Name(name), CallSign(callSign), Location(location) {}

    virtual void DisplayInfo(User* user); // ³��������� ����� ��� ���������������
};

#endif // RADIOAMATEUR_H