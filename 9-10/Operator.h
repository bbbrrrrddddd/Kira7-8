#ifndef OPERATOR_H
#define OPERATOR_H

#include "RadioAmateur.h"

class Operator : public RadioAmateur {
private:
    int YearsOfExperience;

public:
    Operator(string name, string callSign, string location, int years)
        : RadioAmateur(name, callSign, location), YearsOfExperience(years) {}

    void DisplayInfo(User* user) override; // Переопределення методу
};

#endif // OPERATOR_H