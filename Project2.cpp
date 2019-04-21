#include <iostream>
#include <cstring>
using namespace std;

int totCustomers = 0;
const int MAX = 100;

struct Account {
    int number;
    char type[20];
    float balance;
};

struct Customer {
    char name[30];
    char address[50];
    char id[10];
    Account accounts[5];
    int totAccounts;
};

void readCustomer(Customer []);

int main()
{
    Customer customers[MAX];
    readCustomer(customers);
    readCustomer(customers);

    return 0;
}

void readCustomer(Customer cust[MAX])
{
    bool check = true;
    cout << "\nPlease enter customer name: ";
    cin.ignore();
    cin.getline(cust[totCustomers].name, 30);
    cout << "Please enter customer address: ";
    cin.getline(cust[totCustomers].address, 50);
    do
    {
        cout << "Please enter customer ID: ";
        cin >> cust[totCustomers].id;
        for(int i = 0; i < totCustomers; i++)
        {
            if(strcmp(cust[totCustomers].id, cust[i].id) == 0)
            {
                cout << "The ID entered is already in use.\n";
                i = totCustomers;
                check = true;
            }
            else
                check = false;
        }
    }while(check && totCustomers > 0);
    totCustomers++;
}





























