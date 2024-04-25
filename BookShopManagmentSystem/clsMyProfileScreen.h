#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"Global.h"

class clsMyProfileScreen:protected clsScreen
{

private:


    static void _ReadUserInfo()
    {
        cout << "\nEnter FirstName: ";
        CurrentUser.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        CurrentUser.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        CurrentUser.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        CurrentUser.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        CurrentUser.Password = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\t\033[0;37mEnter Account Balance? ";
        CurrentUser.AccountBalance = clsInputValidate::ReadNumber<float>();


    }

    static void _PrintUser()
    {
        cout << "\n\033[0;36mUser Card:";
        cout << "\n\033[0;37m___________________";
        cout << "\nFirstName   : " << CurrentUser.FirstName;
        cout << "\nLastName    : " << CurrentUser.LastName;
        cout << "\nFull Name   : " << CurrentUser.FullName();
        cout << "\nEmail       : " << CurrentUser.Email;
        cout << "\nPhone       : " << CurrentUser.Phone;
        cout << "\nUser Name   : " << CurrentUser.UserName;
        cout << "\nPassword    : " << CurrentUser.Password;
        cout << "\nBalance     : " << CurrentUser.AccountBalance;
        cout << "\n___________________\n";

    }

public:

	static void ShowMyProfile()
	{
		system("cls");
		_DrawScreenHeader("\t\tMy Profile");

        _PrintUser();

        cout << "\nAre you sure you want to update your Profile y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo();

            clsUser::enSaveResults SaveResult;

            SaveResult = CurrentUser.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\n\n\033[0;32mUser Updated Successfully :-)\n";

                
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }
	}

};

