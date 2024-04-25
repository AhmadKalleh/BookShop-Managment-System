#include<iostream>
#include"clsSupplier.h"
#include "clsScreen.h"
#include <iomanip>
#include"clsInputValidate.h"

class clsUpdateSupplierScreen:protected clsScreen
{

private:

	static void _ReadSupplierInfo(clsSupplier& Supplier)
	{

		cout << "\nEnter FirstName: ";
		Supplier.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Supplier.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Supplier.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Supplier.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Address: ";
		Supplier.Address = clsInputValidate::ReadString();

		cout << "\nEnter SuppliersType [Person = 1] or [Company = 2] : ";
		short Choice = clsInputValidate::ReadNumber<short>();

		Supplier.SuppliersType = (Choice == 1) ? "Person" : "Company";


	}

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

	static void ShowUpdateSupplier()
	{
		_DrawScreenHeader("\t  Update Supplier Screen");

		string ID;

		cout << "\n\033[0;37mPlease Enter ID ? ";
		ID = clsInputValidate::ReadString();


		while (!clsSupplier::IsSupplierExist(ID))
		{
			cout << "\n\033[0;31mID is Not Found , Choose another one: ";
			cout << "\033[0;37m";
			ID = clsInputValidate::ReadString();
		}

		clsSupplier Supplier = clsSupplier::Find(ID);

		_PrintSupplier(Supplier);

		cout << "\n\033[0;37mAre you sure you want to update this Supplier y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\n\033[0;37mUpdate Supplier Info:";
			cout << "\n______________________\n";

			_ReadSupplierInfo(Supplier);

			clsSupplier::enSaveResults SaveResult;

			SaveResult = Supplier.Save();

			switch (SaveResult)
			{
			case  clsSupplier::enSaveResults::svSucceeded:
			{
				cout << "\n\n\033[0;32mSupplier Updated Successfully :-)\n";
				
				_PrintSupplier(Supplier);
				break;
			}
			case clsSupplier::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError Supplier was not saved because it's Empty";
				break;

			}
			}

		}



	}

};
