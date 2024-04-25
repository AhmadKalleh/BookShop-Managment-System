#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t\033[0;37m======================================";
        cout << "\n\t\t\t\t\t\033[0;33m  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\033[0;34m  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t\033[0;37m======================================\n\n";

        cout << "\t\t\t\t\tUser:\033[0;36m " << CurrentUser.UserName << "\n";
        cout << "\033[0;37m\t\t\t\t\tDate: \033[0;31m" << clsDate::DateToString(clsDate()) << "\n\n";

    }

    

};

