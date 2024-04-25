#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBook.h"



class clsDeleteBookScreen:protected clsScreen
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

	static void ShowDeleteBookScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Delete Book Screen");

		short Chocie = 0;

		cout << "\n\033[0;37mWhich book of State that you want to Delete it [Free = 1] or [Premium = 2]? ";
		Chocie = clsInputValidate::ReadNumberBetween<short>(1, 2);


		string Title = "";

		cout << "\nEnter A Book Title That You want to Delete it ? ";

		Title = clsInputValidate::ReadString();
		if (Chocie == 1)
		{
			while (!clsBook::IsFreeBookExist(Title))
			{
				cout << "\n\033[0;31mThis Free Book is not Found, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}

		}

		if (Chocie == 2)
		{
			while (!clsBook::IsPremiumBookExist(Title))
			{
				cout << "\n\033[0;31mThis Premium Book is not Found, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}
		}

		clsBook book = (Chocie == 1) ? clsBook::FindFreeBook(Title) : clsBook::FindPremiumBook(Title);

		PrintBookRecord(book);

		cout << "\n\n\033[0;37mAre you sure you want to delete this Book y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (book.Delete())
			{
				cout << "\n\n\t\t\t\t\033[0;31mBook Deleted Successfully :-)\n";

				
			}

			else
			{
				cout << "\nError Book Was not Deleted\n";
			}
		}
		
	}
};

