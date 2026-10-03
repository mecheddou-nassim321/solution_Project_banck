#pragma once
#include<stdio.h>
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsCurrency.h"
using namespace std;
class clsFindCurrency :protected clsScreen {
private:
	
	
	static void _print(clsCurrency& Currency) {
		cout << "Country:" << Currency.GetCountryName() << endl;
		cout << "Code:" << Currency.GetCurencyCode() << endl;
		cout << "name:" << Currency.GetcurncyName() << endl;
		cout << "Rate:" << Currency.Rate();
	}
	static void _show_FindCurrency(clsCurrency Currency) {
		
		if (Currency.isEmpty()) {
			cout << "this Currency is empty";
		}
		else {
			_print(Currency);
		}
	}

	
public:
	static void showFindCurrency() {
		_DrawScreenHeader("\t Find Currency Screen");
		short answer;
		string code;
		string countery;
		cout << "Find by:[1] Code or [2] Countery?:";
		answer = clsInputValidate::ReadShortNumberBetween(1, 2);
		if (answer == 1) {
			cout << "please Enter Currency Code";
			code = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCurrencyCode(code);
			_show_FindCurrency(currency);
		}
		else if(answer==2) {
			cout << "please Enter Countery Name";
			countery = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCunterry(countery);
			_show_FindCurrency(currency);
		}

	}
	
};


