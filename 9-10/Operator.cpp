#include "Operator.h"

void Operator::DisplayInfo(User* user) {
    user->Access(); // Виклик доступу
    cout << "Operator - Name: " << Name << ", Call Sign: " << CallSign
        << ", Location: " << Location << ", Years of Experience: " << YearsOfExperience << endl;
}