#pragma once
#include<iostream>
#include"clsSupplier.h"
#include "clsScreen.h"
#include <iomanip>


class clsSuppliersListScreen:protected clsScreen
{
private:
    static void PrintSupplierRecordLine(clsSupplier Supplier)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Supplier.ID();
        cout << "| " << setw(20) << left << Supplier.FullName();
        cout << "| " << setw(12) << left << Supplier.Phone;
        cout << "| " << setw(20) << left << Supplier.Email;
        cout << "| " << setw(10) << left << Supplier.Address;
        cout << "| " << setw(15) << left << Supplier.SuppliersType;

    }


public:
	static void ShowSuppliersList()
	{
	
        vector <clsSupplier> vSuppliers = clsSupplier::GetSuppliersList();
        string Title = "\t  Supplier List Screen";
        string SubTitle = "\t    (" + to_string(vSuppliers.size()) + ") Supplier(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t\033[0;37m_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "\033[0;37m| " << left << setw(22) << "\033[0;31mID";
        cout << "\033[0;37m| " << left << setw(27) << "\033[0;36mSupplier Name";
        cout << "\033[0;37m| " << left << setw(19) << "\033[0;36mPhone";
        cout << "\033[0;37m| " << left << setw(27) << "\033[0;36mEmail";
        cout << "\033[0;37m| " << left << setw(17) << "\033[0;36mAddrss";
        cout << "\033[0;37m| " << left << setw(15) << "\033[0;36mSupplier Type";
        cout << setw(8) << left << "" << "\n\t\033[0;37m_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vSuppliers.size() == 0)
            cout << "\t\t\t\t\033[0;31mNo Suppliers Available In the System!\n";
        else

            for (clsSupplier Supplier : vSuppliers)
            {

                PrintSupplierRecordLine(Supplier);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\033[0;37m_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
	}
};

