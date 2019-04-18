#include <iostream>
#include <cstring>
using namespace std;

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

int main()
{
    return 0;
}
