#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define PRE_RELEASE

struct STUDENT_DATA
{
    string firstName;
    string lastName;
    string email;
};

int main()
{
    vector<STUDENT_DATA> students;

    #ifdef PRE_RELEASE
    cout << "Running Pre-Release" << endl;
    ifstream inputFile("StudentData_Emails.txt");

    #else
    cout << "Running Standard" << endl;
    ifstream inputFile("StudentData.txt");

    #endif

    if (!inputFile.is_open())
    {
        cout << "Can't open the StudentData file" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line))
    {
        STUDENT_DATA student;

    #ifdef PRE_RELEASE
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        student.firstName = line.substr(0, firstComma);
        student.lastName = line.substr(firstComma + 1, secondComma - firstComma - 1);
        student.email = line.substr(secondComma + 1);

     #else
        size_t commaPosition = line.find(',');

        student.firstName = line.substr(0, commaPosition);
        student.lastName = line.substr(commaPosition + 1);

    #endif

        students.push_back(student);
    }

    inputFile.close();

    #ifdef _DEBUG
    cout << "DEBUG Running" << endl;

    for (const STUDENT_DATA& student : students)
    {
        cout << student.firstName << " , " << student.lastName;

    #ifdef PRE_RELEASE
        cout << " , " << student.email;

    #endif

        cout << endl;
    }

    #endif

    return 0;
}