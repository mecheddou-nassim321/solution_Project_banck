#pragma once
#include<stdio.h>
#include<iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include<vector>
#include<iomanip>
using namespace std;
class clsCurrnciesList :protected clsScreen {
private:
	static void _print(clsCurrency& Currency) {
		
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountryName();
        cout << "| " << setw(8) << left << Currency.GetCurencyCode();
        cout << "| " << setw(45) << left << Currency.GetcurncyName();
        cout << "| " << setw(10) << left << Currency.Rate();
        
	}

public:
    static void showCurrencyList() {
        vector <clsCurrency> vCurrency = clsCurrency::GetListCurrency();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;


        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

              _print(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
    
};
