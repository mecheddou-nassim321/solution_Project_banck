#pragma once
#include<stdio.h>
#include<iostream>
#include<string.h>
#include"clsScreen.h"
#include "clsUser.h"
#include"clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsShowTransfer :protected clsScreen {
private:
	static void _print(clsBankClient& Client) {
		cout << "Client Card:\n";
		cout << "--------------------------\n";
		cout << "Full Name:" << Client.FullName();
		cout << "\nAcc.Number:" << Client.AccountNumber();
		cout << "\n Balance:" << Client.AccountBalance;
		cout << "\n--------------------------\n";
	}
	static string readAccountNumber() {
		string accountNumber = "";
		cout << "please Enter Account Number To transfer from";
		accountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(accountNumber)) {
			cout << "this client is not exsiste enter another again?";
			accountNumber = clsInputValidate::ReadString();

		}
		return accountNumber;
	}
static	double _readAmount() {
		double amount = 0;
		cout << "Enter Transfer Amount";
		amount = clsInputValidate::ReadNumber<double>();
		return amount;

	}
public:
	static void showTranserAmount() {
		_DrawScreenHeader("\tTransfer Screen");
		string AccountNumber1 = "";
		AccountNumber1 = readAccountNumber();
		clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
		_print(Client1);
		string AccountNumber2 = "";
		AccountNumber2 = readAccountNumber();
		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		_print(Client2);

		double Amount = _readAmount();


		
		char answer = 'n';
		cout << "Are you sure you want to perform this tranasaction?y/n?" << endl;
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			if (Client1.transfer(Amount, Client2)) {
				
				cout << "\n transfer done seccsessffully";
			}
			else {
				cout << "\n`Transfer Faild\n";
			}
			
		}
		
		_print(Client1);
		_print(Client2);
	
		



	}
};
