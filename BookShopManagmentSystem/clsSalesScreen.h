#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsBook.h"
#include<map>

class clsSalesScreen:protected clsScreen
{
private:
    static void PrintSalesRecordLine(clsBook::stTotalSalesInfo Collection)
    {

        cout << setw(5) << left << "" << "| " << setw(15) << left << Collection.UserName;
        cout << "| " << setw(20) << left << Collection.BookName;
        cout << "| " << setw(12) << left << Collection.Price;
        cout << "| " << setw(16) << left << Collection.TotalAmount;
        cout << "| " << setw(16) << left << Collection.Amount;
        cout << "| " << setw(15) << left << Collection.Date;

    }

    static void PrintTotalSales(vector <clsBook::stTotalSalesInfo> vTotalSales)
    {
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

                PrintSalesRecordLine(T);
                cout << endl;
            }

        cout << "     \033[0;37m_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;
    }

    static void PrintStatistics(vector <clsBook::stTotalSalesInfo> vTotalSales)
    {

        vector<clsBook> vPremiumBooks = clsBook::GetPremiumBookList();
        map<string, short> vBooks; //short هي الكمية الماخوذة من الكمية الكلية
        short Amount = 0;
        for (clsBook B : vPremiumBooks)
        {
            Amount = 0;
            for (clsBook::stTotalSalesInfo T : vTotalSales)
            {
                if (T.BookName == B.Title)
                {
                    Amount += T.Amount;
                }
            }

            vBooks[B.Title] = Amount;
        }

        cout << "\n" << setw(15) << left << "" << "\033[0;36m___________________________________________________________________________________________\n\n";
        cout << setw(55) << left << "" << "\033[0;36mStatistics\n";
        cout << setw(15) << left << "" << "\033[0;36m___________________________________________________________________________________________\n\n\n\n";


        for (const auto &pair:vBooks)
        {
            cout << setw(15) << left << "" << "\033[0;37m___________________________________________________________________________________________\n\n\t\t";
            cout << setw(18) << pair.first << pair.second  << " %" << " |  ";

            for (int j = 1; j <= pair.second * 0.6; j++)
            {
                cout << "\033[0;32m|";
            }


            cout << "\n" << setw(15) << left << "" << "\033[0;37m___________________________________________________________________________________________\n\n";


        }
    }

public:

    static void ShowTotalSales()
    {
        vector <clsBook::stTotalSalesInfo> vTotalSales = clsBook::GetTotalSalesList();
        string Title = "\t Total Sales List Screen";
        

        _DrawScreenHeader(Title);
        PrintTotalSales(vTotalSales);
        PrintStatistics(vTotalSales);
        
    }

};

