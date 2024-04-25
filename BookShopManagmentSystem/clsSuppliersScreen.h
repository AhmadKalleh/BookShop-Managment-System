#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBook.h"
#include"clsAddNewSupplierScreen.h"
#include"clsDeleteSupplierScreen.h"
#include"clsFindSupplierScreen.h"
#include"clsUpdateSupplierScreen.h"
#include"clsSuppliersListScreen.h"

class clsSuppliersScreen:protected clsScreen
{
private:

    enum enSupplierMenueOptions {
        eAddSupplier = 1, eDeleteSupplier = 2,
        eFindSupplier = 3, eUpdateSupplier = 4,
        eSupplierList = 5, eMain = 6
    };

    static short _ReadSupplierMenueOption()
    {
        cout << "\n" << setw(37) << left << "" << "  Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToSupplierMenue()
    {
        cout << setw(37) << left << "" << "\n\t\033[0;37mPress any key to go back to Supplier Menue...\n";

        system("pause>0");

        ShowSuppliersMenue();

    }

    static void _ShowAddSupplierScreen()
    {
        clsAddNewSupplierScreen::ShowAddNewSupplier();
    }

    static void _ShowDeleteSupplierScreen()
    {
        clsDeleteSupplierScreen::ShowDeleteSupplierScreen();
    }

    static void _ShowFindSupplierScreen()
    {
        clsFindSupplierScreen::ShowFindSupplierScreen();
    }

    static void _ShowUpdateSupplierScreen()
    {
        clsUpdateSupplierScreen::ShowUpdateSupplier();
    }

    static void _ShowSuppliersListScreen()
    {
        clsSuppliersListScreen::ShowSuppliersList();
    }

    static void _PerfromSupplierMenueOption(enSupplierMenueOptions SupplierMenueOption)
    {
        switch (SupplierMenueOption)
        {
        case enSupplierMenueOptions::eAddSupplier:
        {
            system("cls");
            _ShowAddSupplierScreen();
            _GoBackToSupplierMenue();
            break;
        }

        case enSupplierMenueOptions::eDeleteSupplier:
        {
            system("cls");
            _ShowDeleteSupplierScreen();
            _GoBackToSupplierMenue();
            break;
        }

        case enSupplierMenueOptions::eFindSupplier:
        {
            system("cls");
            _ShowFindSupplierScreen();
            _GoBackToSupplierMenue();
            break;
        }

        case enSupplierMenueOptions::eUpdateSupplier:
        {
            system("cls");
            _ShowUpdateSupplierScreen();
            _GoBackToSupplierMenue();
            break;
        }

        case enSupplierMenueOptions::eSupplierList:
        {
            system("cls");
            _ShowSuppliersListScreen();
            _GoBackToSupplierMenue();
            break;

        }

        case enSupplierMenueOptions::eMain:
        {

        }

        }
    }


public:

	static void ShowSuppliersMenue()
	{
        
        _DrawScreenHeader("\t    Suppliers Screen");

        cout << "\n\t     \033[0;37m________________________________________________________________________________________________\n";
        cout << "\t     ________________________________________________________________________________________________\n\n\n";


        cout << "\t\t  ******************               ******************               ******************\n";
        cout << "\t\t  *\033[0;36m 1- Add Supp    \033[0;37m*               *\033[0;36m 2- Delete Supp\033[0;37m *               *\033[0;36m  3 - Find\033[0;37m      *\n";
        cout << "\t\t  ******************               ******************               ******************\n\n";

        cout << "\t\t\t\t   ******************              ******************\n";
        cout << "\t\t\t\t   *\033[0;36m 4- Update Supp\033[0;37m *              *\033[0;36m 5- Supp List\033[0;37m   *\n";
        cout << "\t\t\t\t   ******************              ******************\n\n";
        cout << "\t\t\t\t\t\t   ******************\n ";
        cout << "\t\t\t\t\t\t   *\033[0;36m  6 - Exit\033[0;37m      *\n ";
        cout << "\t\t\t\t\t\t   ******************\n ";


       _PerfromSupplierMenueOption((enSupplierMenueOptions)_ReadSupplierMenueOption());

	}
};

