//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"


class clsInputValidate
{

public:

	
// Fix for the error E0463: 'template' non autorisé  
template <typename T>  
static bool IsNumberBetween(T Number, T From, T To) {  
   if (Number >= From && Number <= To)  
       return true;  
   else  
       return false;  
}

	
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadNumber<short>();

		while (!IsNumberBetween<short>(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<short>();
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadNumber<int >();

		while (!IsNumberBetween<int>(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<int>();
		}
		return Number;
	}

	

	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadNumber<float>();

		while (!IsNumberBetween<float>(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadNumber<float>();
		}
		return Number;
	}

	

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadNumber<double>();

		while (!IsNumberBetween<double>(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadNumber<double>();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}
	
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}


};
