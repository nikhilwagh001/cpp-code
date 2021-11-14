//practical 11.1 
//nikhil wagh 
using namespace std;
#include<iostream>
#include<iomanip.h>
//Base class
class person
{//Data members
private:
char *name;
char *gender;
int age;
public:
//Member function
void getperson(void)
{
cout<<"Enter Name: ";gets(name);
cout<<"Enter Gender: "; cin>>gender;
cout<<"Enter Age: "; cin>>age;
}
void putperson(void)
{
cout<<"Name: "<<name<<endl;
cout<<"Gender: "<<gender<<endl;
cout<<"Age: "<<age<<endl;
}
};//End of Base class
//Intermediat Base class
class employee : public person
{ //Data Members
private:
long emp_id;
char *company;
long salary;
public:
//Member function
void getemp(void)
{
cout<<"Enter Emp_id: "; cin>>emp_id;
cout<<"Enter Compny Name: "; gets(company);
cout<<"Enter Salary: "; cin>>salary;
}
void putemp(void)
{
cout<<"Emp_ID: "<<emp_id<<endl;
cout<<"Company: "<<company<<endl;
cout<<"Salary: "<<salary<<endl;
}
}; //End of Intermediate Base class
//Derived class
class programmer :public employee
{ //Data Members

private:
int no_of_prog_lang_known;
public:
//Member function
void getnumber(void)
{
cout<<"Enter no. of ProgrammingLanguages Known: ";
cin>>no_of_prog_lang_known;
}
void putnumber(void)
{
cout<<"No. of Programming Languages Known:
"<<no_of_prog_lang_known<<endl;
}
}; //End of Derived class
//Main function
int main()
{
programmer p; //Object of Derived class
cout<<"Enter Information of Programmer: \n";
p.getperson(); //Base class function call
p.getemp();
p.getnumber(); //Derived class function call
cout<<"\nInformation of Programmer: \n";
p.putperson();
p.putemp();
p.putnumber();
return 0;
}
