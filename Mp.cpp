#include <iostream>
using namespace std;
#include <process.h>
#include <fstream>

class item
{
    int itemno;
    char itemname[50];
    float price, qnt, tax, dis;

public:
    void getdata()
    {
        system("clr");
        cout << "\nPlease Enter the Item No.:\t";
        cin >> itemno;
        cout << "\nPlease Enter the Name.:\t";
        fflush(stdin);
        gets(itemname);
        cout << "\nPlease Enter the price:\t";
        cin >> price;
        cout << "\nPlease Enter the price:\t";
        cin >> dis;
    }

    void showdata()
    {
        system("clr");
        cout << "\nThe item no.: " << itemno;
        cout << "\nThe name of item: " << itemname;
        cout << "\nThe price of item:  " << price;
        cout << "\nThe discount: " << dis;
    }

    int retitemno()
    {
        return itemno;
    }

    float retprice()
    {
        return price;
    }

    char *retitemname()
    {
        return itemname;
    }

    int retdis()
    {
        return dis;
    }

}; // end class

fstream f; // globle
item i;

void write_to_file()
{
    f.open("store.dat", ios::out | ios ::app);
    i.getdata();
    f.write((char *)&i, sizeof(i));
    f.close();
    cout << "\nItem has been created....";
}

void disp_all()
{
    system("cls");
    cout << "\n\n\\t\tDISPLAY ALL RECORD...!!\n\n";
    f.open("store.dat", ios::in);
    while (f.read((char *)&i, sizeof(i)))
    {
        i.showdata();
        cout << "\n\n******************************************\n";
    }
    f.close();
}

void display_sp(int n)
{
    int flag = 0;
    f.open("store.dat", ios::in);
    while (i.retitemno() == n)
    {
        system("cls");
        i.showdata();
        flag = 1;
    }
    f.close();
    if (flag = 0)
    {
        cout << "\n\n Record dose not exit...";
    }
}

void modify()
{
    int no, found = 0;
    system("cls");
    cout << "\n\nTo Modify";
    cout << "\n\nplease Enter the item no: ";
    cin >> no;
    f.open("store.dat", ios::in | ios::out);
    while (f.read((char *)&i, sizeof(i)) && found == 0)
    {
        if (i.retitemno() == no)
        {
            i.showdata();
            system("cls");
            cout << "Please Enter tthe new details of the item: " << endl;
            i.getdata();
            int pos = -1 * ((int)sizeof(i));
            f.seekp(pos, ios::cur);
            cout << "\n\n\tRecord update...";
            found = 1;
        }
    }
    f.close();
    if (found == 0)
    {
        cout << "\n\n Record not found...";
    }
}

void delectrec()
{
    int no;
    system("cls");
    cout << "\n\n Delete Record...";
    cout << "Enter the item number that you want to delete: ";
    cin >> no;
    f.open("store.dat", ios::in | ios::out);
    fstream f2;
    f2.open("temp.dat", ios::out);
    f.seekg(0, ios::beg);
    while (f.read((char *)&i, sizeof(i)))
    {
        if (i.retitemno() != no)
        {
            f2.write((char *)&i, sizeof(i));
        }
    }
    f2.close();
    f.close();
    remove("store.dat");
    remove("temp.dat"
           "store.dat");
    cout << "\n\nRecord delete";
}

void menu()
{
    system("cls");
    f.open( "store.dat", ios::in);
    if (!f)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\nGo to admin menu and create file..";
        cout << "\n\n!!!Program is closing!!!";
    }
    cout << "\n\n\n\tItem Menu\n\n";
    cout << "==============================================================";
    cout << "ITEM.NO.\t\tNAME\t\tPRICE\n";
    cout << "==============================================================";
    while (f.read((char *)&i, sizeof(i)))
    {
        cout << i.retitemno() << "\t\t" << i.retitemname() << "\t\t" << i.retprice() << endl;
    }
    f.close();
}
void order_place()
{
    system("cls");
    int order_array[50], quen[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n==============================";
    cout << "\n      PLACE YOUR ORDER";
    cout << "\n==============================\n";

    do
    {
        cout << "\n\n\nEnter the item No.: ";
        cin >> order_array[c];
        cout << "\nQuantity in a number : \n";
        cin >> quen[c];
        c++;
        cout << "Do You want to order another? (y/n): ";
        cin >> ch;
    } while (ch == 'y' ||ch == 'Y');
    cout << "Thank you for placeing the order";
    system("cls");
    cout << "**************INVOICE****************";
    cout << "\nItem no. \tName \tQuantity \tPrice \tAmount \tAmount after Discount\n";
    for (int x = 0; x <= c; x++)
    {
        f.open("store.dat", ios::in);
        f.read((char *)&i, sizeof(i));
        while (!f.eof())
        {
            if (i.retitemno() == order_array[x])
            {
                amt = i.retprice() * quen[x];
                damt = amt - (amt * i.retdis() / 100);
                cout << "\n"
                     << order_array[x] << "\t" << i.retitemname() << "\t" << quen[x] << "\t\t" << i.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            f.read((char *)&i, sizeof(i));
        }
        f.close();
    }
    cout << "\n\n\nTotal= " << total;
}

void admin_menu()
{
    system("cls");
    char ch2;
    cout << "\n\n\tADMIN MENU";
    cout << "\n\t1. Create Item: ";
    cout << "\n\t2. Display All Items: ";
    cout << "\n\t3. Query: ";
    cout << "\n\t4. Modify Item : ";
    cout << "\n\t5. Delete Item: ";
    cout << "\n\t6. Back to Main Menu: ";
    cout << "\n\tPlease Enter the Your choice: ";
    cin >> ch2;
    switch (ch2)
    {
    case '1':
        system("cls");
        write_to_file();
        break;
    case '2':
        disp_all();
        break;
    case '3':
        int num;
        system("cls");
        cout << "please Enter the Item No.: ";
        cin >> num;
        display_sp(num);
        break;
    case '4':
        modify();
        break;
    case '5':
        delectrec();
        break;
    case '6':
        menu();
        break;

    default:
        cout << "\a";
        admin_menu();
        break;
    }
}

int main()
{
    char ch;
    do
    {
        system("cls");
        cout << "\n\n\tMAIN MENU";
        cout << "\n\n\t1. CUSTOMER";
        cout << "\n\n\t2. ADMIN";
        cout << "\n\n\t3. EXIT";
        cout << "\n\n\t Please Enter your Choice: (1-3)  ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            system("clr");
            order_place();
            break;
        case '2':
            admin_menu();
            break;
        case '3':
            exit(0);

        default:
            cout << "\a";
            break;
        }
    } while (ch != '3');

    return 0;
}
