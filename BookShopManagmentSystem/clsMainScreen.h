#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"Global.h"
#include <iomanip>
#include"clsBook.h"
#include"clsBooksScreen.h"
#include"clsSuppliersScreen.h"
#include"clsPurchaseScreen.h"
#include"clsSalesScreen.h"
#include"clsMyProfileScreen.h"


class clsMainScreen:protected clsScreen
{

private:

    enum enMainMenueOptions {
        eBooks = 1, eSuppliers = 2,
        ePurchase = 3, eSales = 4,
        eProfile = 5,eExit = 6
    };

    static short _ReadMainMenueOption()
    {
        cout <<"\n"<< setw(37) << left << "" << "  Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowBooksScreen()
    {
        clsBooksScreen::ShowBookMenue();
    }

    static void _ShowSuppliersScreen()
    {
        clsSuppliersScreen::ShowSuppliersMenue();
    }

    static void _ShowPurchaseScreen()
    {
        clsPurchaseScreen::ShowPurchaseMenue();
    }

    static void _ShowSalesScreen()
    {
        clsSalesScreen::ShowTotalSales();
    }

    static void _ShowMyProfileScreen()
    {
        clsMyProfileScreen::ShowMyProfile();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eBooks:
        {
            system("cls");
            _ShowBooksScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eSuppliers:
            system("cls");
            _ShowSuppliersScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::ePurchase:
            system("cls");
            _ShowPurchaseScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eSales:
            system("cls");
            _ShowSalesScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eProfile:
            system("cls");
            _ShowMyProfileScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;

        }
    }


    static void _DrawBook(short& Counter, vector<clsBook> vBooks,string Color,short D)
    {
        if (D == 3)
        {
            cout << "\t\t" << Color << "=================       =================       =================\n";
            cout << "\t\t" << Color << "|\033[0;33m  " << setw(13) << left << vBooks.at(Counter++).Title << Color << "|       |  ";
            cout << "\033[0;33m" << setw(13) << left << vBooks.at(Counter++).Title << Color << "|       |  ";
            cout << "\033[0;33m" << setw(13) << left << vBooks.at(Counter++).Title << Color << "|        \n";

            Counter -= 3;

            cout << "\t\t" << Color << "=================       =================       =================\n";
            cout << "\t\t" << Color << "|               |       |               |       |               |\n";


            cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Author << Color << "|       |  ";
            cout << "\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Author << Color << "|       |  ";
            cout <<"\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Author << Color << "|        \n";

            Counter -= 3;

            cout << "\t\t" << Color << "|               |       |               |       |               |\n";


            cout << "\t\t" << Color << "|\033[0;32m  " << setw(13) << left << vBooks.at(Counter++).State << Color << "|       |  ";
            cout << "\033[0;32m" << setw(13) << left << vBooks.at(Counter++).State << Color << "|       |  ";
            cout <<"\033[0;32m" << setw(13) << left << vBooks.at(Counter++).State << Color << "|        \n";

            cout << "\t\t" << Color << "|               |       |               |       |               |\n";

            cout << "\t\t" << Color << "|  \033[0;37mPrice.($)" << Color << "    |       |  \033[0;37mPrice.($)" << Color << "    |       |  \033[0;37mPrice.($)" << Color << "    | \n";

            Counter -= 3;

            cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Price << Color <<  "|       |  ";
            cout << "\033[0;37m"  << setw(13) << left<< vBooks.at(Counter++).Price << Color  << "|       |  ";
            cout << "\033[0;37m"  << setw(13) << left << vBooks.at(Counter++).Price << Color  << "|        \n";

            cout << "\t\t" << Color << "|               |       |               |       |               |\n";
            cout << "\t\t" << Color << "=================       =================       =================\n\n";
        }

        if (D == 2)
        {
            cout << "\t\t" << Color << "=================       =================\n";
            cout << "\t\t" << Color << "|\033[0;33m  " << setw(13) << left << vBooks.at(Counter++).Title << Color << "|       |  ";
                                        
            cout << "\033[0;33m" << setw(13) << left << vBooks.at(Counter++).Title << Color << "|        \n";

            Counter -= 2;

            cout << "\t\t" << Color << "=================       =================\n";
            cout << "\t\t" << Color << "|               |       |               |\n";


            cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Author << Color << "|       |  ";
                                         
            cout << "\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Author << Color << "|        \n";

            Counter -= 2;

            cout << "\t\t" << Color << "|               |       |               |\n";


            cout << "\t\t" << Color << "|\033[0;32m  " << setw(13) << left << vBooks.at(Counter++).State << Color << "|       |  ";
                                                                               
            cout << "\033[0;32m" << setw(13) << left << vBooks.at(Counter++).State << Color << "|        \n";

            cout << "\t\t" << Color << "|               |       |               |\n";

            cout << "\t\t" << Color << "|  \033[0;37mPrice.($)" << Color << "    |       |  \033[0;37mPrice.($)" << Color << "    | \n";

            Counter -= 2;

            cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Price <<  Color << "|       |  ";
                                              
            cout << "\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Price <<  Color << "| \n";

            cout << "\t\t" << Color << "|               |       |               |\n";
            cout << "\t\t" << Color << "=================       =================\n\n";


        }

        if (D == 1)
        {
            cout << "\t\t" << Color << "=================\n";
            cout << "\t\t" << Color << "|\033[0;33m  " << setw(13) << left << vBooks.at(Counter++).Title << Color << "|        \n";

            Counter -= 1;

            cout << "\t\t" << Color << "=================\n";
            cout << "\t\t" << Color << "|               |\n";


            cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Author << Color << "|        \n";

            Counter -= 1;

            cout << "\t\t" << Color << "|               |\n";


            cout << "\t\t" << Color << "|\033[0;32m  " << setw(13) << left << vBooks.at(Counter++).State << Color << "|        \n";

            cout << "\t\t" << Color << "|               |\n";

            cout << "\t\t" << Color << "|  \033[0;37mPrice.($)" << Color << "    | \n";


            Counter -= 1;

            cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Price <<  Color << "|        \n";

            cout << "\t\t" << Color << "|               |\n";
            cout << "\t\t" << Color << "=================\n\n";
        }
    }
    

    static void _DrawBooksBorder(vector<clsBook> vBooks,string Color)
    {
        
        short Counter = 0;
        short D = vBooks.size();

        if (vBooks.size() == 0)
        {
            cout << "\n\n\t\t\t\033[0;31mThere aren't any Book Here -(\n\n";
        }

        while(Counter<vBooks.size())
        {
            if (D >= 4)
            {
                cout << "\t\t" << Color << "=================       =================       =================       =================\n";
                cout << "\t\t" << Color << "|\033[0;33m  " << setw(13) << left << vBooks.at(Counter++).Title << Color << "|       |  ";
                cout << "\033[0;33m" << setw(13) << left << vBooks.at(Counter++).Title << Color << "|       |  ";
                cout << "\033[0;33m" << setw(13) << left << vBooks.at(Counter++).Title << Color << "|       |  ";
                cout << "\033[0;33m" << setw(13) << left << vBooks.at(Counter++).Title << Color << "|      \n";

                Counter -= 4;

                cout << "\t\t" << Color << "=================       =================       =================       =================\n";
                cout << "\t\t" << Color << "|               |       |               |       |               |       |               |\n";


                cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Author << Color << "|       |  ";
                cout << "\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Author << Color << "|       |  ";
                cout << "\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Author << Color << "|       |  ";
                cout << "\033[0;37m" << setw(13) << left << vBooks.at(Counter++).Author << Color << "|        \n";


                Counter -= 4;

                cout << "\t\t" << Color << "|               |       |               |       |               |       |               |\n";


                cout << "\t\t" << Color << "|\033[0;32m  " << setw(13) << left << vBooks.at(Counter++).State << Color << "|       |  ";
                cout << "\033[0;32m" << setw(13) << left << vBooks.at(Counter++).State << Color << "|       |  ";
                cout << "\033[0;32m" << setw(13) << left << vBooks.at(Counter++).State << Color << "|       |  ";
                cout << "\033[0;32m" << setw(13) << left << vBooks.at(Counter++).State << Color << "|        \n";

                cout << "\t\t" << Color << "|               |       |               |       |               |       |               |\n";

                cout << "\t\t" << Color << "|  \033[0;37mPrice.($)" << Color << "    |       |  \033[0;37mPrice.($)" << Color << "    |       |  \033[0;37mPrice.($)" << Color << "    |       |  \033[0;37mPrice.($)" << Color << "    | \n";

                Counter -= 4;

                cout << "\t\t" << Color << "|\033[0;37m  " << setw(13) << left << vBooks.at(Counter++).Price<< Color << "|       |  ";
                cout << "\033[0;37m"  << setw(13) << left << vBooks.at(Counter++).Price <<  Color << "|       |  ";
                cout << "\033[0;37m"  << setw(13) << left << vBooks.at(Counter++).Price << Color << "|       |  ";
                cout << "\033[0;37m"  << setw(13) << left << vBooks.at(Counter++).Price << Color << "|        \n";

                cout << "\t\t" << Color << "|               |       |               |       |               |       |               |\n";
                cout << "\t\t" << Color << "=================       =================       =================       =================\n\n";

                D -= 4;

            }


           
            if (D < 4)
            {
                _DrawBook(Counter, vBooks,Color,D);
                return;
            }
            

        }

    }

    static void _DrawHeader(string Name,short Size,string Color)
    {
        cout << "\n\t\033[0;37m     ________________________________________________________________________________________________\n\n";
        cout << "\t     |\t\t\t\t\t" << Color <<"  <<  "<< Name <<" ( "<< Size << " )  >>\t\t\t\t\033[0;37m    |\n";
        cout << "\t\033[0;37m     ________________________________________________________________________________________________\n\n";

    }

public:



	static void ShowMainMenue()
	{
        

        vector<clsBook> vFreeBooks = clsBook::GetFreeBookList();
        vector<clsBook> vPremiumBooks = clsBook::GetPremiumBookList();

        system("cls");
        _DrawScreenHeader("\t    Main Screen\n","\t   All Books : "+to_string(vFreeBooks.size()+vPremiumBooks.size()));
        
        _DrawHeader(vPremiumBooks.at(0).State + " Books", vPremiumBooks.size(), "\033[0;31m");
        _DrawBooksBorder(vPremiumBooks, "\033[0;31m");

        _DrawHeader(vFreeBooks.at(0).State+" Books", vFreeBooks.size(), "\033[0;36m");
        _DrawBooksBorder(vFreeBooks, "\033[0;36m");
        
        cout << "\n\t     \033[0;37m________________________________________________________________________________________________\n";
        cout << "\t     ________________________________________________________________________________________________\n\n\n";

        
        cout << "\t\t  ******************              ******************              ******************\n";
        cout << "\t\t  *\033[0;33m  1 - BOOKS\033[0;37m     *              *\033[0;33m  2 - Suppliers\033[0;37m *              *\033[0;33m  3 - Purchase\033[0;37m  *\n";
        cout << "\t\t  ******************              ******************              ******************\n\n";

        cout << "\t\t\t\t   ******************              ******************\n";
        cout << "\t\t\t\t   *\033[0;33m  4 - Sales\033[0;37m     *              *\033[0;33m  5 - Profile\033[0;37m  *\n";
        cout << "\t\t\t\t   ******************              ******************\n\n";

        cout << "\t\t\t\t\t\t   ******************\n ";
        cout << "\t\t\t\t\t\t   *\033[0;31m  6 - Exit\033[0;37m      *\n ";
        cout << "\t\t\t\t\t\t   ******************\n ";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

	}

};

