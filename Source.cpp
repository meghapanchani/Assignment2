#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
    vector<STUDENT_DATA> students;

    ifstream inputFile("StudentData.txt");

    if (!inputFile.is_open())
    {
        cout << "Cant open the StudentData.txt" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line))
    {
        size_t commaPosition = line.find(',');

        STUDENT_DATA student;

        student.firstName = line.substr(0, commaPosition);
        student.lastName = line.substr(commaPosition + 1);

        students.push_back(student);
    }

    inputFile.close();

    return 0;
}