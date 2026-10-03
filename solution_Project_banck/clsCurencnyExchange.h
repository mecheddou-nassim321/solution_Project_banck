#pragma once
#include<stdio.h>
#include<iostream>
#include<string.h>
#include"clsScreen.h"
#include "clsCurrency.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsListCurencies.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsClculatorExchange.h"
using namespace std;
class clsShowCurencyExchange :protected clsScreen {
private:
    enum enumCurrencyOption{eListCurrencies=1,eFindCurrency=2,eUpdateRate=3,eCurrencyCalculator=4,eXit=5};
    static void _showListCurrency() {
        clsCurrnciesList::showCurrencyList();
  }
    static void  _showFindCurrencies() {
        clsFindCurrency::showFindCurrency();
    }
    static void _showUpdateRate() {
        clsShowUpdateRate::showUpdateRate();
    }
    static void _showCurrencyCalculator() {
        clsCalculatorScreen::showCalculator();
    }
      
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        showCurncyExchange();
    }
  static  short readMinueOption() {
        cout << "choose what do you want to do?[1 to 5]:";
        short option = clsInputValidate::ReadShortNumberBetween(1, 5);
        return option;
    }
  static void _performeMinueOption(enumCurrencyOption Option) {
      switch (Option)
      {
      case enumCurrencyOption::eListCurrencies: {
          system("cls");
          _showListCurrency();
          _GoBackToMainMenue();
          break;

      }

      case enumCurrencyOption::eFindCurrency: {
          system("cls");
          _showFindCurrencies();
          _GoBackToMainMenue();
          break;
      }
      case enumCurrencyOption::eUpdateRate: {
          system("cls");
          _showUpdateRate();
          _GoBackToMainMenue();
          break;
      }
      case enumCurrencyOption::eCurrencyCalculator: {
          system("cls");
          _showCurrencyCalculator();
          _GoBackToMainMenue();
          break;
      }
      case enumCurrencyOption::eXit: {
          //
      }

      }
  }
public:
   
   
	static void showCurncyExchange() {
        system("cls");
		_DrawScreenHeader("Currancy Echange Main Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";

        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
      
        cout << setw(37) << left << "" << "\t[5] Main Minue.\n";
      
        cout << setw(37) << left << "" << "===========================================\n";
        _performeMinueOption((enumCurrencyOption)readMinueOption());

	}
};
