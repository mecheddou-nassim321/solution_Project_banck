#pragma once
#include<stdio.h>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class  clsRegistreList:protected clsScreen {
private:

    static void _PrintUserRecordLine(clsUser::stRgestreLogin Register)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << Register.DateTime;
        cout << "| " << setw(12) << left << Register.userName;
        cout << setw(8) << left << "" << "| " << setw(12) << left << Register.password;
      
        
        cout << "| " << setw(12) << left << Register.permession;

    }

public:

    static void ShowRegistreList()
    {
        if (!checkAccesRight(clsUser::enPermissions::pRegistre) ){
            return;
        }
        vector <clsUser::stRgestreLogin> vUsers = clsUser::GetListLogin();

        string Title = "\t  Registre List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Register(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "Date/Time";
        cout << "| " << left << setw(25) << "User Name";
      
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stRgestreLogin User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


};
