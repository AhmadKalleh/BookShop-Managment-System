#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBook.h"

class clsUpdateBookScreen:protected clsScreen
{
private:

	static void _ReadBookInfo(clsBook& Book, clsBook& book2, short Choice)
	{

		cout << "\nEnter an Author? ";
		Book.Author = clsInputValidate::ReadString();
		book2.Author = Book.Author;

		char Answer = 'n';
		cout << "\nDo you want To Change Book Of State From " << Book.State << " to ";
		if (Choice == 1) cout << "Premium"; else cout << "Free"; cout << " y / n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			
			book2.State = (Choice == 1) ? "Premium" : "Free";

			if (Choice == 1)
			{
				cout << "\nEnter A Price? ";
				book2.Price = clsInputValidate::ReadNumber<float>();
			}

			else
			{
				book2.Price = 0.0;
			}

			cout << "\nEnter a Quantity? ";
			book2.Quantity = clsInputValidate::ReadNumberBetween<short>(1, 100);


			
			Book.Delete();

			clsBook::enSaveResults SaveResult;
			SaveResult = book2.Save();

			switch (SaveResult)
			{
			case  clsBook::enSaveResults::svSucceeded:
			{
				cout << "\n\n\t\t\t\t\033[0;32m    Book Updated Successfully :-)\n";
				cout << "\t\t\t\t\033[0;37m    _____________________________\n";
				PrintBookRecord(book2);
				break;
			}
			case clsBook::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError Book was not saved because it's Empty";
				break;

			}

			}


		}

		else
		{
			if (Choice == 2)
			{
				cout << "\nEnter A Price? ";
				Book.Price = clsInputValidate::ReadNumber<float>();
			}

			cout << "\nEnter a Quantity? ";
			Book.Quantity = clsInputValidate::ReadNumberBetween<short>(1, 100);
			clsBook::enSaveResults SaveResult;


			SaveResult = Book.Save();

			switch (SaveResult)
			{
			case  clsBook::enSaveResults::svSucceeded:
			{
				cout << "\n\n\t\t\t\t\033[0;32m    Book Updated Successfully :-)\n";
				cout << "\t\t\t\t\033[0;37m    _____________________________\n";
				PrintBookRecord(Book);
				break;
			}
			case clsBook::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError Book was not saved because it's Empty";
				break;

			}

			}


		}
	}

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

	static void ShowUpdateBookScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Update Book Screen");

		short Choice = 0;

		cout << "\n\033[0;37mWhich book of State that you want to Update it [Free = 1] or [Premium = 2]? ";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 2);


		string Title = "";

		cout << "\nEnter A Book Title That You want to Update it ? ";

		Title = clsInputValidate::ReadString();
		if (Choice == 1)
		{
			while (!clsBook::IsFreeBookExist(Title))
			{
				cout << "\n\033[0;31mThis Free Book is not Found, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}

		}

		if (Choice == 2)
		{
			while (!clsBook::IsPremiumBookExist(Title))
			{
				cout << "\n\033[0;31mThis Premium Book is not Found, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}
		}

		clsBook book = (Choice == 1) ? clsBook::FindFreeBook(Title) : clsBook::FindPremiumBook(Title);
		PrintBookRecord(book);

		clsBook book2 = clsBook::GetAddNewBookObject(book.Title);
	

		cout << "\n\033[0;37mAre you sure you want to update this Book y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\n\033[0;37mUpdate Book Info:";
			cout << "\n____________________\n";

			_ReadBookInfo(book,book2,Choice);

			
		}


	}

	
	
};

