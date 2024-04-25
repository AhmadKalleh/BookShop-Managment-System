#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBook.h"

class clsAddNewBookScreen:protected clsScreen
{

private:

	static void ReadBookInfo(clsBook &book,short Answer)
	{

		book.State = (Answer == 1) ? "Free" : "Premium";

		cout << "\n\033[0;37mEnter an Author ? ";
		book.Author = clsInputValidate::ReadString();

		if (Answer == 1)
		{
			book.Price = 0.0;
		}
		else if (Answer == 2)
		{
			cout << "\n\033[0;37mEnter A Price ? ";
			book.Price = clsInputValidate::ReadNumber<float>();
		}

		cout << "\n\033[0;37mEnter A Quantity ? ";
		book.Quantity = clsInputValidate::ReadNumberBetween<short>(1,100);

		if (book.Quantity <= 0)
		{
			cout << "\n\033[0;31mPlease Enter A Number More Than 0 ? ";
			cout << "\033[0;37m";
			book.Quantity = clsInputValidate::ReadNumber<short>();
		}

	}

	static void PrintBookRecord(clsBook book)
	{
		string Color = (book.State == "Free") ? "\033[0;36m" : "\033[0;31m";

		cout << "\t\t\t\t\t" << Color << "=================\n";
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

	static void ShowAddNewBookScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Add Book Screen");

		short Answer = 0;

		cout << "\n\033[0;37mWhich book of State that you want to add it [Free = 1] or [Premium = 2]? ";
		Answer = clsInputValidate::ReadNumberBetween<short>(1, 2);

		string Title = "";
		cout << "\nEnter A Book Title ? ";
		Title = clsInputValidate::ReadString();

		if (Answer == 1)
		{
			while (clsBook::IsFreeBookExist(Title))
			{
				cout << "\n\033[0;31mThis Free Book Is Already Exists, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}

		}

		if (Answer == 2)
		{
			while (clsBook::IsPremiumBookExist(Title))
			{
				cout << "\n\033[0;31mThis Premium Book Is Already Exists, Choose another one: ";
				cout << "\033[0;37m";
				Title = clsInputValidate::ReadString();
			}
		}

		clsBook book = clsBook::GetAddNewBookObject(Title);

		ReadBookInfo(book, Answer);

		clsBook::enSaveResults SaveResult;

		SaveResult = book.Save();

		switch (SaveResult)
		{
		case  clsBook::enSaveResults::svSucceeded:
		{
			cout << "\n\n\n\t\t\t\t\t\033[0;32mBook Added Successfully :-)\n";
			cout << "\t\t\t\t\t\033[0;37m_____________________________\n";
			PrintBookRecord(book);
			break;
		}
		case clsBook::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError Book was not saved because it's Empty";
			break;

		}
		case clsBook::enSaveResults::svFaildTitleExists:
		{
			cout << "\nError Book was not saved because Book is used!\n";
			break;

		}
		}


		
	}
};

