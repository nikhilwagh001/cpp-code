#include <iostream>
using namespace std;
class cricketer
{ 
	private:
	char name[20], cou[10];
	public:
		void get_cricketer(void)
		{
			cout<<"Enter Name: ";
			fflush(stdin);
			gets(name);
			cout<<"Enter Country: ";
			fflush(stdin);
			gets(cou);
		}
		
		void put_cricketer(void)
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Country: "<<cou<<endl;
		}
}; 
class bowler :virtual public cricketer
{
	
	int wic;
	public:
	void get_wc(void)
	{
		cout<<"Enter Wicket: ";
		cin>>wic;
	}
	void put_wc(void)
	{
		cout<<"Wicket : "<<wic<<endl;
	}
};

class bating: virtual public cricketer
{
	int run;
	public: 
	void get_run(void)
	{
		cout<<"Enter run: ";
		cin>>run;
	}
	void put_run(void)
	{
		cout<<"Run: "<<run;
	}
};

class allrounder: public  bowler, public bating
{
	public:
		void show(void)
		{
			put_cricketer();
			put_wc();
			put_run();
		}
};
int main ()
{
allrounder p;
	cout<<"Enter Info about player:"<<endl;
	p.get_cricketer();
	p.get_wc();
	p.get_run();
	cout<<"Information of allrounder"<<endl;
	p.show();
	return 0;
}
