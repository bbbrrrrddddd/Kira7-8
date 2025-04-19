#include "Technician.h"

void Technician::DisplayInfo(User* user) {
    user->Access(); // Виклик доступу
    cout << "Technician - Name: " << Name << ", Call Sign: " << CallSign
        << ", Location: " << Location << ", Certification Level: " << CertificationLevel << endl;
}