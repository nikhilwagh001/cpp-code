#include <iostream>
using namespace std;
class area
{
	public:
		float find_area(float len, float br)
		{
			float area;
			area = len*br;
			return area;
		}
};

class perimeter
{
	public:
		float find_perimeter(float len, float br)
		{
			float per;
			per = 2 *(len+br);
			return per;
		}
};

class rectangle : public area , public perimeter
{
	private:
		float len, bar;
	public:
		void get(void)
		{
			cout<<"Enter the length and bradth :";
			cin>>len>>bar;
		}
		
		void display(void)
		{
			float area, per;
			area= find_area(len, bar);
			cout<<"Area is :"<<area<<endl;
			per= find_perimeter(len, bar);
			cout<<"Perimeter is: "<<per;
		}
};
int main ()
{
	rectangle r;
	r.get();
	r.display();
	return 0;
}
