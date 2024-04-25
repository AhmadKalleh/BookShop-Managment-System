#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBook.h"
#include"clsAddNewBookScreen.h"
#include"clsDeleteBookScreen.h"
#include"clsUpdateBookScreen.h"
#include"clsFindBookScreen.h"

class clsBooksScreen:protected clsScreen
{

private:

    enum enBookMenueOptions {
        eAddBook = 1, eDeleteBook = 2,
        eFindBook = 3, eUpdateBook = 4, eMain = 5
    };

    static short _ReadBookMenueOption()
    {
        cout << "\n" << setw(37) << left << "" << "  Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToBookMenue()
    {
        cout << setw(37) << left << "" << "\n\t\033[0;37mPress any key to go back to Book Menue...\n";

        system("pause>0");

        ShowBookMenue();

    }

    static void _ShowAddBookScreen()
    {
        clsAddNewBookScreen::ShowAddNewBookScreen();
    }

    static void _ShowDeleteBookScreen()
    {
        clsDeleteBookScreen::ShowDeleteBookScreen();
    }

    static void _ShowFindBookScreen()
    {
        clsFindBookScreen::ShowFindBookScreen();
    }

    static void _ShowUpdateBookScreen()
    {
        clsUpdateBookScreen::ShowUpdateBookScreen();
    }

    static void _PerfromBookMenueOption(enBookMenueOptions BookMenueOption)
    {
        switch (BookMenueOption)
        {
        case enBookMenueOptions::eAddBook:
        {
            system("cls");
            _ShowAddBookScreen();
            _GoBackToBookMenue();
            break;
        }

        case enBookMenueOptions::eDeleteBook:
        {
            system("cls");
            _ShowDeleteBookScreen();
            _GoBackToBookMenue();
            break;
        }

        case enBookMenueOptions::eFindBook:
        {
            system("cls");
            _ShowFindBookScreen();
            _GoBackToBookMenue();
            break;
        }

        case enBookMenueOptions::eUpdateBook:
        {
            system("cls");
            _ShowUpdateBookScreen();
            _GoBackToBookMenue();
            break;
        }

        case enBookMenueOptions::eMain:
        {

        }

        }
    }


public:
    static void ShowBookMenue()
    {
        system("cls");
        _DrawScreenHeader("\t    Books Screen");

        cout << "\n\t     \033[0;37m________________________________________________________________________________________________\n";
        cout << "\t     ________________________________________________________________________________________________\n\n\n";


        cout << "\t\t  ******************              ******************              ******************\n";
        cout << "\t\t  *\033[0;36m  1 - Add Book\033[0;37m  *              *\033[0;36m 2- Delete Book\033[0;37m *              *\033[0;36m  3 - Find\033[0;37m      *\n";
        cout << "\t\t  ******************              ******************              ******************\n\n";

        cout << "\t\t\t\t   ******************              ******************\n";
        cout << "\t\t\t\t   *\033[0;36m 4- Update Book\033[0;37m *              *\033[0;36m  5 - Main\033[0;37m     *\n";
        cout << "\t\t\t\t   ******************              ******************\n";

        _PerfromBookMenueOption((enBookMenueOptions)_ReadBookMenueOption());

    }
    
};

