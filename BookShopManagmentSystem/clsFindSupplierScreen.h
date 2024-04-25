#pragma once
#include<iostream>
#include"clsSupplier.h"
#include "clsScreen.h"
#include <iomanip>
#include"clsInputValidate.h"

class clsFindSupplierScreen:protected clsScreen
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

	static void ShowFindSupplierScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Find Supplier Screen");

		string ID;

		cout << "\n\033[0;37mPlease Enter ID ? ";
		ID = clsInputValidate::ReadString();

		while (!clsSupplier::IsSupplierExist(ID))
		{
			cout << "\n\033[0;31mID Is not Found , Choose another one: ";
			cout << "\033[0;37m";
			ID = clsInputValidate::ReadString();
		}

		clsSupplier Supplier = clsSupplier::Find(ID);

		if (!Supplier.IsEmpty())
		{
			cout << "\n\033[0;32mSupplier Found -)\n";
			_PrintSupplier(Supplier);
		}

		else
		{
			cout << "\n\033[0;31mSupplier is Not Found -)\n";
		}
	}
};

