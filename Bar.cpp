#include<bits/stdc++.h>
using namespace std;

string drinks[] = {"Vodka", "Scotch", "Cocktail", "Champagne", "Red Wine", "Cocktail", "Whisky", "Desi Daru"};
int price[] = {550, 650, 700, 600, 800, 900, 590, 50};
class Customer{
    public:
    string c_name;
    int c_age;
    Customer()
    {
        cout<<"------------------------------------------------------"<<endl;
        cout<<"\t\t\t The Bidi Bar"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Please, Enter your Details: "<<endl<<"Name: ";
        getline(cin, c_name);
        cout<<"Age: ";
        cin>>c_age;
    }
};

class Order: public Customer{
    private:
        unsigned int total_quantity, total_price, quantity[8]={};
    public:
        void Get_order()
        {
            int order_choice=0;
            char reorder;
            //quantity[7]={};
            //total_quantity=0;
            do
            {
                system("cls");
                cout<<"------------------------------------------------------"<<endl;
                cout<<"\t\t\t The Bidi Bar"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cout<<"Please select from the following menu: "<<endl;
                cout<<"------------------------------------------------------"<<endl;
                for(int count=0; count<8; count++)
                {
                    cout<<count+1<<"."<<drinks[count]<<":\tRs."<<price[count]<<endl;
                }
                cout<<"------------------------------------------------------"<<endl;
                cout<<"Enter your Choice: ";
                cin>>order_choice;
                cout<<"------------------------------------------------------"<<endl;
                if(order_choice<9&&order_choice>0)
                {
                    cout<<"Please select the quantity: ";
                    cin>>quantity[order_choice-1];
                }
                else
                {
                    cout<<"Please try again and make a Valid Input"<<endl;
                }
                cout<<"------------------------------------------------------"<<endl;
                cout<<"Do you want to Order more Drinks(y/n): ";
                cin>>reorder;
            }
            while(reorder=='y');
        }
        void Get_bill()
        {
            system("cls");
            cout<<"------------------------------------------------------"<<endl;
            cout<<"\t\t\t The Bidi Bar"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            int serial_no=1;
            total_quantity=0;
            total_price=0;
            cout<<c_name<<endl<<"Your Detailed Bill is: "<<endl;
            cout<<"------------------------------------------------------"<<endl;
            for(int count=0; count<8; count++)
            {
                if(quantity[count]!=0)
                {
                    cout<<serial_no<<". "<<drinks[count]<<":\t"<<quantity[count]<<" X "<<price[count]<<"\t= Rs."<<quantity[count]*price[count]<<endl;
                    serial_no++;
                    total_price += quantity[count]*price[count];
                    total_quantity += quantity[count];
                }
            }
            cout<<"------------------------------------------------------"<<endl;
            cout<<"The total order quantity is: "<<total_quantity<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"The total Bill is: "<<total_price<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }
        Order()
        {
            Get_order();
            Get_bill();
        }

};
int main()
{
    char continue_ordering;
    do
    {
        system("cls");
        Order *ptr = new Order;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Do you want to Continue Ordering(y/n): ";
        cin>>continue_ordering;
    }
    while(continue_ordering=='y');

    return 0;
}
