#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsMainScreen.h"
#include"clsInputValidate.h"
#include <fstream>

class clsLoginScreen :protected clsScreen
{

private:
    static void _ReadUserInfo()
    {
        cout << "\n\t\t\t\t\t\033[0;37mEnter FirstName: ";
        CurrentUser.FirstName = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\t\033[0;37mEnter LastName: ";
        CurrentUser.LastName = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\t\033[0;37mEnter Email: ";
        CurrentUser.Email = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\t\033[0;37mEnter Phone: ";
        CurrentUser.Phone = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\t\033[0;37mEnter Password? ";
        CurrentUser.Password = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\t\033[0;37mEnter Account Balance? ";
        CurrentUser.AccountBalance = clsInputValidate::ReadNumber<float>();

    }


    static bool _SignUp()
    {
        string Username, Password;
        float AccountBalance;

      
        cout << "\n\t\t\t\t\t\033[0;37mEnter Username? ";
        Username = clsInputValidate::ReadString();
      
        while (clsUser::IsUserExist(Username))
        {
            cout << "\n\t\t\t\t\t\033[0;31mThis Account is Already Exists, Enter Again..\n";
            cout << "\n\t\t\t\t\t\033[0;37mEnter Username? ";
            Username = clsInputValidate::ReadString();
         
        }
        
        CurrentUser = clsUser::GetAddNewUserObject(Username);
        _ReadUserInfo();

        clsUser::enSaveResults SaveResult;

        SaveResult = CurrentUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\n\n\t\t\t\t\t\033[0;32mUser Addeded Successfully :-)\n";
            cout << "\n\n\t\t\t\t\t\033[0;37mPress Any Key to go Main Screen...\n";
            system("pause>0");
            clsMainScreen::ShowMainMenue();
            return true;
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
            
           
        

    }

    static bool _Login()
    {
        bool LoginFaild = false;
        

        string Username, Password;
        short FaildLoginCount = 0;
        do
        {

            if (LoginFaild)
            {

                FaildLoginCount++;
                cout << "\n\t\t\t\t\t\033[0;37mInvlaid Username / Password!....Press Any Key to try Again\n";
                cout << "\t\t\t\t\t\033[0;37mYou have " << (3 - FaildLoginCount) << " Trials to login.\n\n";

                if (FaildLoginCount == 3)
                {
                    cout << "\n\t\t\t\t\t\033[0;31mYou are Locked after 3 faild trails\n";
                    return false;;
                }

            }

            

            cout << "\n\t\t\t\t\t\033[0;37mEnter Username? ";
            cin >> Username;

            cout << "\n\t\t\t\t\t\033[0;37mEnter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        
        clsMainScreen::ShowMainMenue();

        return true;

    }

public:


    static bool ShowLoginSignUpScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login/Sign Up Screen");
        short Choice = 0;

        cout << "\t\t\t\t\t\033[0;37mAre you Have [Account = 1] or [Create Account = 2] ? ";
        Choice = clsInputValidate::ReadNumberBetween<short>(1, 2);

        if (Choice == 1)
            return _Login();

        else if (Choice == 2)
            return _SignUp();

    }

};

