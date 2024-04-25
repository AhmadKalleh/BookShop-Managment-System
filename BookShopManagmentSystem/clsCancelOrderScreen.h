#pragma once
#include<iostream>
#include"clsBook.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsCancelOrderScreen:protected clsScreen
{

public:

	static void ShowCancelOrder()
	{
		system("cls");
		_DrawScreenHeader("\t  Cancel Order Screen");

		string Title = "";
		char Answer = 'n';

		cout << "\n\033[0;37mEnter A Title Of Book That you want To Delete it From Your Collection: ";
		Title = clsInputValidate::ReadString();


		while (!clsBook::IsPremiumBookExist(Title))
		{
			cout << "\n\033[0;31mThis Premium Book is not Found, choose another one: \033[0;37m";
			Title = clsInputValidate::ReadString();
		}

		
		clsBook book = clsBook::FindPremiumBook(Title);
		

		cout << "\n\033[0;37mAre you sure you want to Cancel this Book y/n ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			book.CancelOrder();
			cout << "\n\n\t\t\t\t\t\033[0;31mThe Canceld was Completed Successfully.\033[0;37m\n";
		}

	}
};

