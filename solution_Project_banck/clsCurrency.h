#pragma once
#include<stdio.h>
#include<iostream>
#include "clsString.h"
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class clsCurrency {
private:
	enum enumMode{emptyMode=0,UpdateMode=1};
	enumMode _Mode;
	string _countryName;
	string _curencyName;
	string _curencyCode;
	float _rate;
	static clsCurrency _GetEmptyCurrency() {
		return clsCurrency(enumMode::emptyMode, "", "", "", 0);
	}
	static clsCurrency _convrteLineTo_Object(string line, string sperator = "#//#") {
		vector<string>vCurrency = clsString::Split(line, sperator);
		if (vCurrency.size() >= 4) {
			return	clsCurrency(enumMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
		}
		return _GetEmptyCurrency();
	}
	static string _converteReccordToLine(clsCurrency Currency, string sperator = "#//#") {
		string reccord = "";
		reccord += Currency.GetCountryName()+sperator;
		
		reccord += Currency.GetCurencyCode()+sperator;
		reccord += Currency.GetcurncyName() + sperator;
		reccord += to_string(Currency.Rate());
		return reccord;
	}

	static vector<clsCurrency>_loadCurrencyToFile() {
		fstream myFile;
		vector<clsCurrency>vCurrency;
		myFile.open("Currencies.txt", ios::in);
	
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency Currency = _convrteLineTo_Object(line);
				vCurrency.push_back(Currency);
			}
			myFile.close();
		}
		return vCurrency;
	}
	static void _SaveCurrenctyToFile(vector<clsCurrency>&vCurrency) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::out);
		string CurrencyLine;
		if (myFile.is_open()) {
			for (clsCurrency U : vCurrency) {
				CurrencyLine = _converteReccordToLine(U);
				myFile << CurrencyLine << endl;
			
			}
			myFile.close();
		}

	}
	void _Update() {
		vector<clsCurrency>vCurency;
		vCurency = _loadCurrencyToFile();
		for (clsCurrency C : vCurency) {
			if (C.GetCurencyCode() == GetCurencyCode()) {
				C = *this;
				break;
			}
		}
		_SaveCurrenctyToFile(vCurency);
	}
public:
	clsCurrency(enumMode Mode,string countryName, string curencyCode,string curencyName,float rate) {
		_Mode = Mode;
		_countryName = countryName;
		_curencyName = curencyName;
		_curencyCode = curencyCode;
		_rate = rate;

	}
 	bool isEmpty() {
		return (_Mode == enumMode::emptyMode);
	}
	string GetCountryName() {
		return _countryName;
	}
	string GetcurncyName() {
		return _curencyName;
	}
	string GetCurencyCode() {
		return _curencyCode;
	}
	float Rate() {
		return _rate;
	}
	void UpdateRate(float newRate) {
		_rate = newRate;
		_Update();
	}
	static clsCurrency FindByCurrencyCode(string currencyCode) {
		fstream myFile;
		currencyCode = clsString::UpperAllString(currencyCode);
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency Currency = _convrteLineTo_Object(line);
				if (clsString::UpperAllString(  Currency.GetCurencyCode()) == currencyCode) {
					
					myFile.close();
					return Currency;
				}
			}
			myFile.close();
		}
		return _GetEmptyCurrency();
	}

	static clsCurrency FindByCunterry(string cuntery) {
		fstream myFile;
		
		myFile.open("Currencies.txt", ios::in);
		cuntery = clsString::UpperAllString(cuntery);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency Currency = _convrteLineTo_Object(line);
				if ((clsString::UpperAllString(  Currency.GetCountryName())) == cuntery) {

					myFile.close();
					return Currency;
				}
			}
			myFile.close();
		}
		return _GetEmptyCurrency();
	}
 static	bool isExsiste(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		return !(Currency.isEmpty());
	}
	static vector<clsCurrency>GetListCurrency() {
		return _loadCurrencyToFile();
	}
	float conveToUSD(float Amount) {
		return (float)Amount / Rate();
	}
	float convTOtherCurrency(float Amount,clsCurrency currency2) {
		Amount = conveToUSD(Amount);
		if (currency2.GetCurencyCode() == "USD") {
			return Amount;
		}
		return Amount * currency2.Rate();
	}
};
