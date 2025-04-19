#include "RadioAmateur.h"

void RadioAmateur::DisplayInfo(User* user) {
    user->Access(); // Виклик доступу
    cout << "Name: " << Name << ", Call Sign: " << CallSign << ", Location: " << Location << endl;
}