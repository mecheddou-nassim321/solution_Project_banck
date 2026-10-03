#pragma once
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
        bool LoginFaild = false;
        short countLogin = 0;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                countLogin++;
                cout << "You have " << 3 - countLogin << " trials To login\n";
                if (countLogin == 3) {
                    cout << "your system locked after 3 fail"<<endl;
                    system("pause"); // Only works on Windows
                    exit (0);
                  
                }
            }

            cout << "\nEnter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegistreLogin(CurrentUser);
        clsMainScreen::ShowMainMenue();
        

    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       
            _Login();
      
        

    }

};
