#pragma once
#include<iostream>
#include"clsBook.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsDate.h"


class clsNewOrderScreen:protected clsScreen
{

private:

	static void PrintBookRecord(clsBook book)
	{
		string Color = (book.State == "Free") ? "\033[0;36m" : "\033[0;31m";

		cout << "\n\t\t\t\t\tBook Record:\n";
		cout << "\n\t\t\t\t\t-----------";
		cout << "\n\t\t\t\t\t" << Color << "=================\n";
		cout << "\t\t\t\t\t" << Color << "|\033[0;33m  " << setw(13) << left << book.Title << Color << "|        \n";



		cout << "\t\t\t\t\t" << Color << "=================\n";
		cout << "\t\t\t\t\t" << Color << "|               |\n";

		cout << "\t\t\t\t\t" << Color << "|\033[0;37m  " << setw(13) << left << book.Author << Color << "|        \n";

		cout << "\t\t\t\t\t" << Color << "|               |\n";


		cout << "\t\t\t\t\t" << Color << "|\033[0;32m  " << setw(13) << left << book.State << Color << "|        \n";



		cout << "\t\t\t\t\t" << Color << "|               |\n";
		cout << "\t\t\t\t\t" << Color << "|  \033[0;37mPrice.($)" << Color << "    | \n";


		cout << "\t\t\t\t\t" << Color << "|\033[0;37m  " << setw(13) << left << book.Price << Color << "|        \n";

		cout << "\t\t\t\t\t" << Color << "|               |\n";
		cout << "\t\t\t\t\t" << Color << "=================\n\n";

	}

	static void _PrepareOrder(short NumberOfOrders, vector <clsBook::stTotalSalesInfo>& vSales, float& SumOfPrices)
	{
		short Counter = 1;
		short Amount = 0;

		
		string Title = "";
		do
		{
			cout << "\nEnter A Tilte of Book [" << Counter << "] : ";
			Title = clsInputValidate::ReadString();

			while (!clsBook::IsPremiumBookExist(Title))
			{
				cout << "\n\033[0;31mThis Premium Book is not Found ,Choose another one : \033[0;37m";
				Title = clsInputValidate::ReadString();
			}

			clsBook book = clsBook::FindPremiumBook(Title);			
			clsBook::stTotalSalesInfo Sales;
			

			PrintBookRecord(book);

			cout << "\n\033[0;37mThere are \033[0;32m" << book.Quantity << " \033[0;37mQuantity of " << book.Title << " Book, how many books you want? ";
			Amount = clsInputValidate::ReadNumberBetween<short>(1, book.Quantity, "\n\033[0;31mNumber exceeds quantity,Enter Again: \033[0;37m");

			while (Amount > NumberOfOrders - (Counter-1))
			{
				cout << "\n\033[0;31mSorry,you want to buy [\033[0;36m" << NumberOfOrders - (Counter-1) << "\033[0;31m] books From Number Of Orders [\033[0;36m"<< NumberOfOrders <<"\033[0;31m]\033[0;37m: ";
				Amount = clsInputValidate::ReadNumberBetween<short>(1, book.Quantity, "\n\033[0;31mNumber exceeds quantity,Enter Again: ");
			}

			Sales.BookName = book.Title;
			Sales.Price = book.Price;
			Sales.Amount = Amount;
			Sales.Date = clsDate::GetSystemDateTimeString();			
			Sales.UserName = CurrentUser.UserName;
			Sales.TotalAmount = book.Quantity;
			

			if (Amount > 1)
			{
				Counter += Amount;
			}

			else
			{
				Counter++;
			}

			
			vSales.push_back(Sales);
			SumOfPrices += book.Price * Amount;
		
		} while (Counter <= NumberOfOrders);
		
	}

public:

	static void ShowNewOrder()
	{
		_DrawScreenHeader("\t  New Order Screen");

		
		short NumberOfOrders = 0;
		char Answer = 'n';

		float SumOfPrices = 0;

		
		vector <clsBook::stTotalSalesInfo> Sales;

		cout << "\n\033[0;37mHow many Books do you want to buy ? ";
		NumberOfOrders = clsInputValidate::ReadNumber<short>();


		_PrepareOrder(NumberOfOrders,Sales, SumOfPrices);

		cout << "\n\033[0;37mAre you sure you want to buy this Book y/n ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (clsBook::Purchase(SumOfPrices, Sales))
			{
				cout << "\n\n\t\t\t\t\t\033[0;32mThe Purchase was Completed Successfully\n";
				cout << "\t\t\tand you can find the purchased books in\033[0;36m [My Collections Screen]\033[0;37m.\n";				
			}
			else
			{
				cout << "\n\n\t\t\t\t\t\033[0;31mThe Purchase was Not Completed\n";
				cout << "\t\t\tbecuase your Account Balance is not enough to purchase all of these books\033[0;37m.\n";
			}
		}

		
	}

};

