#pragma once
#include<stdio.h>
#include<iostream>
#include<string.h>
#include"clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsShowUpdateRate :protected clsScreen {
private:
	static void _print(clsCurrency& Currency) {
		cout << "Currency Card:\n";
		cout << "n\____________________________________________________\n";
		cout << "Country:" << Currency.GetCountryName() << endl;
		cout << "Code:" << Currency.GetCurencyCode() << endl;
		cout << "name:" << Currency.GetcurncyName() << endl;
		cout << "Rate:" << Currency.Rate();
		cout << "\n____________________________________________________\n";
	}
	static float _readNewRate() {
		float rate = 0;
	
		cout << "Enter New  Rate";
		rate = clsInputValidate::ReadNumber<float>();
		return rate;
	}
public:
	static void showUpdateRate() {
		_DrawScreenHeader("\t Update Currency Screen");
		string code = "";
		cout << "please Enter Currency Code:";
		code = clsInputValidate::ReadString();
		while (!(clsCurrency::isExsiste(code))) {
			cout << "this code is not exsiste enter another again:\n";
			code = clsInputValidate::ReadString();
		}
		clsCurrency currency = clsCurrency::FindByCurrencyCode(code);
		_print(currency);
		char answer = 'n';
		cout << "Are you sure you want to  update the rate of this currency y/n?";
		cin >> answer;
		float rate = 0;
		if (answer == 'y' || answer == 'Y') {
			cout << "Update Currency Rate:\n";
			cout << "_____________________________\n";
			
			currency.UpdateRate(_readNewRate());
			cout << endl;
			cout << "Currency Rate Updated Successefully :)";
			_print(currency);


		}

	}
};
