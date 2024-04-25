#pragma once
#include<iostream>
#include"clsBook.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsNewOrderScreen.h"
#include"clsCancelOrderScreen.h"
#include"clsMyCollectionsScreen.h"


class clsPurchaseScreen:protected clsScreen
{

private:

    enum enPurchaseMenueOptions
    {
        eNewOrder = 1, eCancelOrder = 2,
        eMyCollectionsOfBooks = 3, eMain = 4
    };

    static short _ReadPurchaseMenueOption()
    {
        cout << "\n" << setw(37) << left << "" << "  Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 4, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowPurchaseMenue();
    }

    static void _ShowNewOrderScreen()
    {
        clsNewOrderScreen::ShowNewOrder();
    }

    static void _ShowCancelOrderScreen()
    {
        clsCancelOrderScreen::ShowCancelOrder();
    }

    static void _ShowMyCollectionsOfBooksScreen()
    {
        clsMyCollectionsScreen::ShowMyCollections();
    }

    static void _PerfromPurchaseMenueOption(enPurchaseMenueOptions PurchaseMenueOption)
    {
        switch (PurchaseMenueOption)
        {

        case enPurchaseMenueOptions::eNewOrder: 
        {
            system("cls");
            _ShowNewOrderScreen();
            _GoBackToMainMenue();
            break;
        }

        case enPurchaseMenueOptions::eCancelOrder:
        {
            system("cls");
            _ShowCancelOrderScreen();
            _GoBackToMainMenue();
            break;
        }

        case enPurchaseMenueOptions::eMyCollectionsOfBooks:
        {
            system("cls");
            _ShowMyCollectionsOfBooksScreen();
            _GoBackToMainMenue();
            break;
        }

        case enPurchaseMenueOptions::eMain:
        {

        }

        }
    }

public:

	static void ShowPurchaseMenue()
	{
        system("cls");
        _DrawScreenHeader("\t  Purchase Menue Screen");

        cout << "\n\t     \033[0;37m________________________________________________________________________________________________\n";
        cout << "\t     ________________________________________________________________________________________________\n\n\n";

        cout << "\t\t  ******************               ******************               ******************\n";
        cout << "\t\t  *\033[0;36m 1- New Order   \033[0;37m*               *\033[0;36m2- Cancel Order\033[0;37m *               *\033[0;36m3-My Collections\033[0;37m*\n";
        cout << "\t\t  ******************               ******************               ******************\n\n";

        cout << "\t\t\t\t\t\t   ******************\n ";
        cout << "\t\t\t\t\t\t   *\033[0;36m  4 - Exit\033[0;37m      *\n ";
        cout << "\t\t\t\t\t\t   ******************\n ";

        _PerfromPurchaseMenueOption((enPurchaseMenueOptions)_ReadPurchaseMenueOption());
	}

};

