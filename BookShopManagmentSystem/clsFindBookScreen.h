#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBook.h"

class clsFindBookScreen:protected clsScreen
{

private:

	static void PrintBookRecord(clsBook book)
	{
		string Color = (book.State == "Free") ? "\033[0;36m" : "\033[0;31m";

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

public:

	static void ShowFindBookScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Find Book Screen");

		short Answer = 0;

		cout << "\n\033[0;37mWhich book of State that you want to Find it [Free = 1] or [Premium = 2]? ";
		Answer = clsInputValidate::ReadNumberBetween<short>(1, 2);

		string Title = "";
		cout << "\nEnter A Book Title ? ";
		Title = clsInputValidate::ReadString();

		if (Answer == 1)
		{
			while (!clsBook::IsFreeBookExist(Title))
			{
				cout << "\n\033[0;31mThis Free Book Is Already Exists, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}

		}

		if (Answer == 2)
		{
			while (!clsBook::IsPremiumBookExist(Title))
			{
				cout << "\n\033[0;31mThis Premium Book Is Already Exists, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}
		}

		clsBook book = (Answer == 1) ? clsBook::FindFreeBook(Title) : clsBook::FindPremiumBook(Title);

		if (!book.IsEmpty())
		{
			cout << "\n\n\t\t\t\t\033[0;32m        Book Found :-)\n";
			cout << "\t\t\t\t\033[0;37m        ____________________\n";
			PrintBookRecord(book);
		}
		else
		{
			cout << "\n\n\t\t\t\t\033[0;31m    Book NoT Found :-)\n";
			cout << "\t\t\t\t\033[0;37m    ____________________\n";
		}
		
	}
};

