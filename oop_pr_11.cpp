#include <iostream>
using namespace std;
class employee
{
private:
    int emp_no;
    char emp_name[20], desighation[20];

public:
    void getemp(void)
    {
        cout << "Enter the Employee number: ";
        cin >> emp_no;
        cout << "Enter the name: ";
        fflush(stdin);
        gets(emp_name);
        cout << "Enter desighnation: ";
        cin >> desighation;
    }

    void displayemp(void)
    {
        cout << "Emplyoee Number: " << emp_no << endl;
        cout << "Employee name: " << emp_name << endl;
        cout << "desighnation: " << desighation << endl;
    }
};

class salary : public employee
{
private:
    long basic, HRA, DA, gross_sal;

public:
    void getsalary(void)
    {
        cout << "Enter basic salary: ";
        cin >> basic;
        DA = basic * 35 / 100;
        HRA = basic * 15 / 100;
        gross_sal = basic + DA + HRA;
    }
    void displaysalay(void)
    {
        cout << "basic salary: " << basic << endl;
        cout << "DA : " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "Gross salary: " << gross_sal << endl;
    }
};
int main()
{
    salary s;
    cout << "Enter information of employee: " << endl;
    s.getemp();
    s.getsalary();
    cout << "information of employee" << endl;
    s.displayemp();
    s.displaysalay();

    return 0;
}