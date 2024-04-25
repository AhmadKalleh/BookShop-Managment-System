#pragma once

#include<iostream>
#include"clsSupplier.h"
#include "clsScreen.h"
#include <iomanip>
#include"clsInputValidate.h"


class clsDeleteSupplierScreen:protected clsScreen
{

private:

	static void _PrintSupplier(clsSupplier Supplier)
	{
		cout << "\n\033[0;36mSupplier Card:";
		cout << "\n\033[0;37m___________________";
		cout << "\nFirstName     : " << Supplier.FirstName;
		cout << "\nLastName      : " << Supplier.LastName;
		cout << "\nFull Name     : " << Supplier.FullName();
		cout << "\nEmail         : " << Supplier.Email;
		cout << "\nPhone         : " << Supplier.Phone;
		cout << "\nID            : " << Supplier.ID();
		cout << "\nAddress       : " << Supplier.Address;
		cout << "\nSuppliersType : " << Supplier.SuppliersType;
		cout << "\n___________________\n";

	}

public:

	static void ShowDeleteSupplierScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Delete Supplier Screen");

		string ID;

		cout << "\n\033[0;37mPlease Enter ID ? ";
		ID = clsInputValidate::ReadString();

		while (!clsSupplier::IsSupplierExist(ID))
		{
			cout << "\n\033[0;31mID is Not Found, Choose another one: ";
			cout << "\033[0;37m";
			ID = clsInputValidate::ReadString();
		}

		clsSupplier Supplier = clsSupplier::Find(ID);

		_PrintSupplier(Supplier);

		cout << "\n\n\033[0;37mAre you sure you want to delete this Supplier y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Supplier.Delete())
			{
				cout << "\n\n\t\t\t\t\033[0;31mSupplier Deleted Successfully :-)\n";

			}

			else
			{
				cout << "\nError Supplier Was not Deleted\n";
			}
		}



	}
};

