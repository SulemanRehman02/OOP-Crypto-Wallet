#include <iostream>
#include<string>
#include <stdio.h>
#include <windows.h>
#include"Currency.h"
#include "Ether.h"
#include "BitCoinAccount.h"
#include "BitCoin.h"
#include "EtherAccount.h"
#include "AccountManagerHashed.h"
#include "TransactionHashed.h"
#include "Transaction.h"
#include <vector>
#include "Account.h"
#include "AccountManager.h"


////#include <bits/stdc++.h>
using namespace std;
AccountManager manager;

void MENU()
{

    int choice;
    while(choice!=5)
        {
    cout << "\n1.Create Account\n2.Make a Transaction\n3.See Transaction Log\n4.See All Accounts\n5.Exit\n";
    cin >> choice;
    switch(choice)
    {
    case 1:
        {

            int account;
            cout << "What type of Account do you want to create?\n1.BITCOIN\n2.ETHER? " << endl;
            cin >> account;
            while(account!=1 && account!=2)
             {
                cout << "Error! Kindly correctly choose the account type i.e. 1 or 2 \n";
                cin >> account;
            }
            if(account == 1)
             {
                manager.CreateAccount(BITCOIN);
            }
            else if(account == 2)
            {
                manager.CreateAccount(ETHER);
            }
            break;
        }

    case 2:
            {
            string sender_pub,sender_priv,receiver_pub;
            double amount;
            cout << "Enter Sender's Public Key: " << endl;
            cin >>  sender_pub;
            cout << "Enter Sender's Private Key: " << endl;
            cin >> sender_priv;
            cout << "Enter Receiver's Public Key: " << endl;
            cin >> receiver_pub;
            cout << "Enter the amount you want to transfer: " << endl;
            cin >> amount;
            manager.MakeTransaction(sender_pub,sender_priv,receiver_pub,amount);
            break;
            }

    case 3:
        {
            cout << "TRANSACTIONS:\n";
            cout << manager.ToStringTransactionLog() << endl;
            break;
            }
    case 4:
        {
            cout << "ACCOUNTS:\n";
            manager.Display_All_Accounts();
            break;
            }

    default:
            {
            break;
            }
        }
    }
}

int main()
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                            FOREGROUND_GREEN |
                                                            FOREGROUND_INTENSITY |
                                                            BACKGROUND_INTENSITY
                          );
    cout << "~ SOME ACCOUNTS ARE CREATED BY DEFUALT IN ORDER TO PROVIDE CONVENIENCE TO THE USER IN CASE HE JUST WANTS TO PRINT ACCOUNTS OR MAKE A TRANSACTION ~\n" << endl;
    cout << "BitCoin Default Account's --> Public key: default_Bitcoin & Private Key: 1234\n";
    cout << "Ether Default Account's --> Public key: default_Ether & Private Key: 4321\n";
    cout << "\n\n\n";
    BitCoinAccount b1("default_Bitcoin", "1234");
    EtherAccount e1("default_Ether","4321");
    manager.AddAccount(b1);
    manager.AddAccount(e1);

    MENU();
}


