// Q5. Create a database with Teacher class to store the teacher’s name, the subject they teach,
// and their years of experience, with the name and subject stored as dynamic strings. First, write
// the class without a copy constructor or assignment operator and observe what happens when
// you copy one teacher object into another (shallow copy problem). Then implement the Rule of
// Three to fix the issue. Display both teacher objects before and after the fix to demonstrate the
// difference.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Teacher
{

    public:
        char* teachersName;
        char* teachersSubject;
        int yearsOfExperience; 

        Teacher(const string& m, const string& n, int o) : yearsOfExperience(o)
        {
            // boys we discovered a new technique today////
            teachersName = new char[m.size()];
            teachersSubject = new char[strlen(n) + 1];
        }

        Teacher(const Teacher& obj)
        {
            this->teachersName = new char[strlen(obj.teachersName) + 1];

            for (int m = 0; m < strlen(obj.teachersName); m++)
            {
                teachersName[m] = obj.teachersName[m];
            }

            this->tecahersSubject = new char[strlen(obj.teachersSubject) + 1]

            for (int m = 0; m < strlen(obj.teachersSubject); m++)
            {
                teachersName[m] = obj.teachersName[m];
            }

            this->yearsOfExperience = obj.yearsOfExperience;

            cout << "Copy constructor was called////" << endl;
            cout << "Object Successfully copied////" << endl;
        }

        Teacher& operator= (const Teacher& obj)
        {
            if (*this == obj)
            {
                cout << "Can not call copy assignment opertor on same object////" << endl;
                return this;
            }

            this->teachersName = new char[strlen(obj.teachersName) + 1];

            for (int m = 0; m < strlen(obj.teachersName); m++)
            {
                this->teachersName[m] = obj.teachersName[m];
            }

            this->teachersSubject = new char[strlen(obj.tecahersSubject) + 1];

            for(int m = 0; m < strlen(obj.teachersSubject); m++)
            {
                this->teachersSubject[m] = obj.teachersSubject[m];
            }

            this->yearsOfExperience = obj.yearsOfExperience;

            cout << "Copy assignment opertor successfully called////\n";
            return this;

        }

        ~Teacher()
        {
            delete[] teachersName;
            delete[] teachersSubject;
        }

        void display(void)
        {
            cout << "Teacher's Name: " << this->teachersName << endl;
            cout << "Teacher's Subject: " << this->teachersSubject << endl;
            cout << "Teacher's Years Of Experience: " << this->yearsOfExperience << endl;
        }
};

int main(void)
{

    Teacher t1("Abu Bakar", "Programming FUndamentals", 23);
    Teacher t2("Waqar", "Maths", 3);

    t1.display();
    t2.display();

    return 0;
}