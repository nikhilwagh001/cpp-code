/*practical 12.2
Nikhil wagh
*/
using namespace std;
#include<iostream>
#include<conio.h>
//Base class
class car
{
private:
char car_type[15];
public:
void get_type(void)
{
cout<<"Enter car type : ";
cin>>car_type;
}
void display_type(void)
{
cout<<"Car Type : "<<car_type<<"\n";

}
}; //End of Base class
//Intermediat Base class
class brand : public car
{
private:
char brand_name[15];
int speed;
public:
void get_brand(void)
{
cout<<"Enter Brand of Car : ";
cin>>brand_name;
cout<<"Enter Speed of Car :";
cin>>speed;
}
void display_brand(void)
{
cout<<"Brand of Car : "<<brand_name<<"\n"<<"Speed of Car :
"<<speed<<"\n";
}
}; //End of Intermediate Base class
//Derived class
class model : public brand
{
private:
char model_name[15];
long price;
public:
void get_model(void)
{
cout<<"Enter Model of Car : ";
cin>>model_name;
cout<<"Enter Price of Car :";
cin>>price;
}
void display_model(void)
{
cout<<"Model of Car : "<<model_name<<"\n"<<"Price of Car :
"<<price<<"\n";
}
};
//Main function
int main()
{
model car;
cout<<"Enter information of Car : \n";
car.get_type();
car.get_brand();
car.get_model();
cout<<"\nInformation of Car : \n";
car.display_type();

car.display_brand();
car.display_model();
return 0;
}
