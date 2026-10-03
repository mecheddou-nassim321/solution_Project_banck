#pragma once
#include<stdio.h>
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "Global.h"
#include "clsUser.h"
using namespace std;
class clsTaransferLog :protected clsScreen {
private:

    static void _PrintUserRecordLine(clsBankClient::stTransferLog Transfer)
    {
        cout << setw(8) << left << "" << "| " << setw(5) << left << Transfer.DateTime;
        cout << "| " << setw(12) << left << Transfer.source_AccountNumber;
        cout << setw(8) << left << "" << "| " << setw(5) << left << Transfer.destination_AccountNumber;
        cout << setw(8) << left << "" << "| " << setw(5) << left << Transfer.Amount;
        cout << setw(8) << left << "" << "| " << setw(5) << left << Transfer.source_balnce;
        cout << setw(8) << left << "" << "| " << setw(5) << left << Transfer.destination_balnce;
        cout << setw(8) << left << "" << "| " << setw(5) << left << Transfer.UserName;


        

    }
public:
	static void showTransferLog() {
		_DrawScreenHeader("\t Transfer Log screen");
        
        vector <clsBankClient::stTransferLog> vTransfer =clsBankClient::GetListTransfer() ;

        string Title = "\t  Transfer Log Screen";
        string SubTitle = "\t    (" + to_string(vTransfer.size()) + ") Register(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";

        cout << "| " << left << setw(5) << "d.acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.balance";
        cout << "| " << left << setw(10) << "d.balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransfer.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankClient::stTransferLog Transfer:vTransfer )
            {

                _PrintUserRecordLine(Transfer);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

	
};

