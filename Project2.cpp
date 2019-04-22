#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int totCustomers = 0;
const int MAX = 100;
const float MIN_BALANCE = 50.0;

struct Account { //structure for account types
    int number;
    char type[20];
    float balance;
};

struct Customer { //structure for customers
    char name[30];
    char address[50];
    char id[10];
    Account accounts[5];
    int totAccounts;
};

//function prototypes
void readCustomer(Customer []);
int totalCustomers();
bool findCustomer(const Customer [], const char []);
void printAccountDetails(const Customer [], const int);
void printCustomerDetails(const Customer [], const char []);
void newAccount(Customer [], const char [], const char []);

int main()
{
    Customer customers[MAX];

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
        for(int i = 0; i < totCustomers; i++) //for-loop checking if ID entered is in use already
        {
            if(strcmp(cust[totCustomers].id, cust[i].id) == 0)
            {
                cout << "The ID entered is already in use.\n";
                i = totCustomers; //if ID is in use already, assign exit value to i in order to exit for-loop
                check = true;
            }
            else
                check = false;
        }
    }while(check && totCustomers > 0);
    cust[totCustomers].totAccounts = 0;
    int num;
    do
    {
        cout << "\nHow many accounts would you like to open?(Maximum limit of accounts is 5) ";
        cin >> num;
    }while(num < 0 || num > 5);
    for(int i = 0; i < num; i++)
        newAccount(cust, cust[totCustomers].name, cust[totCustomers].id);
    totCustomers++;
}

int totalCustomers()
{
    return totCustomers;
}

bool findCustomer(const Customer cust[], const char checkID[10])
{
    for(int i = 0; i < totCustomers; i++)
        if(strcmp(checkID, cust[i].id) == 0)
            return true;
    return false;
}

void printAccountDetails(const Customer cust[], const int accNum)
{
    for(int i = 0; i < totCustomers; i++)
    {
        for(int j = 0; j < cust[i].totAccounts; j++)
        {
            if(cust[i].accounts[j].number == accNum)
            {
                cout << "\nAccount holder name: " << cust[i].name;
                cout << "\nAccount holder address: " << cust[i].address;
                cout << "\nAccount holder ID: " << cust[i].id << endl;
                i = totCustomers;
            }
        }
    }
}

void printCustomerDetails(const Customer cust[], const char custID[])
{
    for(int i = 0; i < totCustomers; i++)
    {
        if(strcmp(custID, cust[i].id) == 0)
        {
            cout << "\nCustomer name: " << cust[i].name;
            cout << "\nCustomer address: " << cust[i].address;
            for(int j = 0; j < cust[i].totAccounts; j++)
            {
                cout << "\nAccount " << j + 1 << ":";
                cout << "\nAccount number: " << cust[i].accounts[j].number;
                cout << "\nAccount type: " << cust[i].accounts[j].type;
                cout << "\nAccount balance: " << cust[i].accounts[j].balance << endl;
            }
            i = totCustomers;
        }
    }
}

void newAccount(Customer cust[], const char custName[], const char custID[])
{
    int i = 0;
    bool check = true;
    while(i < totCustomers && check)
    {
        if(strcmp(cust[i].name, custName) == 0)
            if(strcmp(cust[i].id, custID) == 0)
                check = false;
        i++;
    }
    i--;
    if(check)
        cout << "\nWrong customer details entered!\n";
    else
    {
        if(cust[i].totAccounts >= 5)
            cout << "\nMaximum number of accounts reached!\n";
        else
        {
            int choice;
            bool loop;
            do
            {
                srand(time(0));
                loop = false;
                cust[i].accounts[cust[i].totAccounts].number = (rand() % 9999) + 1000;
                for(int j = 0; j < totCustomers; j++)
                {
                    for(int k = 0; j < cust[j].totAccounts; k++)
                        if(cust[i].accounts[cust[i].totAccounts].number == cust[j].accounts[k].number)
                            loop = true;
                }
            }while(loop);
            cout << "\nChoose which type of account to open:\n1) Checking Account\n2) Savings Account\n3) Money market Account\n";
            cout << "\nEnter a number between 1-3: ";
            cin >> choice;
            do
            {
                switch(choice)
                {
                    case 1: strcpy(cust[i].accounts[cust[i].totAccounts].type, "Checking Account");
                            break;
                    case 2: strcpy(cust[i].accounts[cust[i].totAccounts].type, "Savings Account");
                            break;
                    case 3: strcpy(cust[i].accounts[cust[i].totAccounts].type, "Money market Account");
                            break;
                    default: cout << "\nInvalid input!\n";
                            break;
                }
            }while(choice < 1 || choice > 3);
            float dep;
            do
            {
                cout << "\nPlease enter the amount you wish to deposit: ";
                cin >> dep;
                if(dep < MIN_BALANCE)
                    cout << "\nMinimum balance required is " << MIN_BALANCE << endl;
            }while(dep < MIN_BALANCE);
            cust[i].totAccounts++;
        }
    }
}
























