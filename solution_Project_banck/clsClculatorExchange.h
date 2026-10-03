#pragma once
#include<stdio.h>
#include<string.h>
#include"clsString.h"
#include <iostream>
#include"clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsUtil.h"
using namespace std;
class clsCalculatorScreen :protected clsScreen {
private:
	static void _print(clsCurrency& Currency,string Title) {
		
		cout << "\n______________"<<Title<<"________________________________\n";
		cout << "Country:" << Currency.GetCountryName() << endl;
		cout << "Code:" << Currency.GetCurencyCode() << endl;
		cout << "name:" << Currency.GetcurncyName() << endl;
		cout << "Rate:" << Currency.Rate();
		cout << "\n____________________________________________________\n";
	}
	static float _readAmount() {
		float Amount=0;
		cout << "Enter  Amount to exchange:";
		Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}
	static clsCurrency _GetCurrency( string message) {
		string currencyCode = "";
		cout << message;
		
		currencyCode = clsInputValidate::ReadString();
		while (!(clsCurrency::isExsiste(currencyCode))) {
			cout << "this currency code is not exsiste,choose another again ";
			currencyCode = clsInputValidate::ReadString();
		}
		clsCurrency	curency = clsCurrency::FindByCurrencyCode(currencyCode);
		return curency;

	}
	static void _printCalculationResult(clsCurrency currencyFrom, clsCurrency currencyTo, float amount) {
		_print(currencyFrom, "Converte From:");
		cout << amount << " " << currencyFrom.GetCurencyCode() << "=" << currencyFrom.conveToUSD(amount) << "USD";
		if (currencyTo.GetCurencyCode() == "USD") {
			return;
		}

		_print(currencyTo, "Converte From USD TO:");
		cout << "To\n";
		cout << amount << " " << currencyFrom.GetCurencyCode() << "=" << currencyFrom.convTOtherCurrency(amount, currencyTo) << "" << currencyTo.GetCurencyCode();
	}
	
public:
	static void showCalculator() {
		_DrawScreenHeader("\t   claculator currency");

		char answer = 'y'; // Declare 'answer' before using it  

		while (answer == 'y' || answer == 'Y') {

			system("cls");
			_DrawScreenHeader("\t   claculator currency");
			clsCurrency Currency1= _GetCurrency("\n please enter currencyCode1\n");
			clsCurrency Currency2 = _GetCurrency("\n please enter currencyCode2\n");
			float Amount = 0;
			Amount = _readAmount();
			
			_printCalculationResult(Currency1, Currency2, Amount);

			cout << "\nDo you want to perfrom another Calculation";
			cin >> answer;
		}
	
	}


    
       
       
};
