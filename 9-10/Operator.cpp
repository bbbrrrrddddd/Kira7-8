#include "Operator.h"

void Operator::DisplayInfo(User* user) {
    user->Access(); // ������ �������
    cout << "Operator - Name: " << Name << ", Call Sign: " << CallSign
        << ", Location: " << Location << ", Years of Experience: " << YearsOfExperience << endl;
}