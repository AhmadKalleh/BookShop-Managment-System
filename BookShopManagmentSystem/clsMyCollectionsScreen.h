#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsBook.h"

class clsMyCollectionsScreen:protected clsScreen
{
private:
    static void PrintCollectionRecordLine(clsBook::stTotalSalesInfo Collection)
    {

        cout << setw(5) << left << "" << "| " << setw(15) << left << Collection.UserName;
        cout << "| " << setw(20) << left << Collection.BookName;
        cout << "| " << setw(12) << left << Collection.Price;
        cout << "| " << setw(16) << left << Collection.TotalAmount;
        cout << "| " << setw(16) << left << Collection.Amount;
        cout << "| " << setw(15) << left << Collection.Date;

    }
public:

	static void ShowMyCollections()
	{
        vector <clsBook::stTotalSalesInfo> vTotalSales = clsBook::GetUserBooksList();
        string Title = "\tMy Collections List Screen";
        string SubTitle = "\t    (" + to_string(vTotalSales.size()) + ") Books(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(5) << left << "" << "\n     \033[0;37m_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

        cout << setw(5) << left << "" << "\033[0;37m| " << left << setw(22) << "\033[0;31mUser Name";
        cout << "\033[0;37m| " << left << setw(27) << "\033[0;36mBook Name";
        cout << "\033[0;37m| " << left << setw(19) << "\033[0;36mPrice($)";
        cout << "\033[0;37m| " << left << setw(23) << "\033[0;36mTotal Amount";
        cout << "\033[0;37m| " << left << setw(17) << "\033[0;36mPurchased Amount";
        cout << "\033[0;37m| " << left << setw(15) << "\033[0;36mDate";
        cout << setw(5) << left << "" << "\n     \033[0;37m_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

        if (vTotalSales.size() == 0)
            cout << "\t\t\t\t\033[0;31mNo there arn 't any Collections for you  In the System!\n";
        else

            for (clsBook::stTotalSalesInfo T : vTotalSales)
            {

                PrintCollectionRecordLine(T);
                cout << endl;
            }

        cout <<  "     \033[0;37m_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;
	}
};

