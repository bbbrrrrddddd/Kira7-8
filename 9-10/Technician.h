#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "RadioAmateur.h"

class Technician : public RadioAmateur {
private:
    string CertificationLevel;

public:
    Technician(string name, string callSign, string location, string certLevel)
        : RadioAmateur(name, callSign, location), CertificationLevel(certLevel) {}

    void DisplayInfo(User* user) override; // Переопределення методу
};

#endif // TECHNICIAN_H