#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include"clsString.h"
#include"clsUtil.h"

class clsSupplier:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
    string _ID;
	string _Address;
	string _SuppliersType;

    bool _MarkForDelete = false;

	static clsSupplier _ConvertLinetoSupplierObject(string Line, string Seperator = "#//#")
	{
		vector<string> vSuppliersData;
		vSuppliersData = clsString::Split(Line, Seperator);

		return clsSupplier(enMode::UpdateMode, vSuppliersData[0], vSuppliersData[1],
            vSuppliersData[2], vSuppliersData[3], clsUtil::DecryptText(vSuppliersData[4]), vSuppliersData[5], vSuppliersData[6]);

	}

    static string _ConverSupplierObjectToLine(clsSupplier Supplier, string Seperator = "#//#")
    {

        string stSupplierRecord = "";
        stSupplierRecord += Supplier.FirstName + Seperator;
        stSupplierRecord += Supplier.LastName + Seperator;
        stSupplierRecord += Supplier.Email + Seperator;
        stSupplierRecord += Supplier.Phone + Seperator;
        stSupplierRecord += clsUtil::EncryptText(Supplier.ID()) + Seperator;
        stSupplierRecord += Supplier.Address + Seperator;
        stSupplierRecord += Supplier.SuppliersType ;
       

        return stSupplierRecord;

    }

    static  vector <clsSupplier> _LoadSuppliersDataFromFile()
    {

        vector <clsSupplier> vSuppliers;

        fstream MyFile;
        MyFile.open("Suppliers.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsSupplier Supplier = _ConvertLinetoSupplierObject(Line);

                vSuppliers.push_back(Supplier);
            }

            MyFile.close();

        }

        return vSuppliers;

    }

    static void _SaveSuppliersDataToFile(vector <clsSupplier> vSuppliers)
    {

        fstream MyFile;
        MyFile.open("Suppliers.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsSupplier S : vSuppliers)
            {
                if (S.MarkForDeleted() == false)
                {
                    DataLine = _ConverSupplierObjectToLine(S);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsSupplier> _vSuppliers;
        _vSuppliers = _LoadSuppliersDataFromFile();

        for (clsSupplier& S : _vSuppliers)
        {
            if (S.ID() == ID())
            {
                S = *this;
                break;
            }

        }

        _SaveSuppliersDataToFile(_vSuppliers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverSupplierObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Suppliers.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsSupplier _GetEmptySupplierObject()
    {
        return clsSupplier(enMode::EmptyMode, "","","","","","","");
    }

public:

	clsSupplier(enMode Mode,string FirstName, string LastName,string Email,string Phone,
        string ID,string Address, string SuppliersType):
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
        _ID = ID;
		_Address = Address;
		_SuppliersType = SuppliersType;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

    bool MarkForDeleted()
    {
        return _MarkForDelete;
    }

    string ID()
    {
        return _ID;
    }

	void SetAddress(string Address)
	{
		_Address = Address;
	}

	string GetAddress()
	{
		return _Address;
	}
		
	__declspec(property(get = GetAddress, put = SetAddress)) string Address;

	void SetSuppliersType(string SuppliersType)
	{
		_SuppliersType = SuppliersType;
	}

	string GetSuppliersType()
	{
		return _SuppliersType;
	}

	__declspec(property(get = GetSuppliersType, put = SetSuppliersType)) string SuppliersType;

    static vector<clsSupplier> GetSuppliersList()
    {
        return _LoadSuppliersDataFromFile();
    }

    static   clsSupplier Find(string ID)
    {

        ID = clsString::UpperAllString(ID);
       

        fstream MyFile;
        MyFile.open("Suppliers.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsSupplier Supplier = _ConvertLinetoSupplierObject(Line);

                if (clsString::UpperAllString(Supplier.ID()) == ID)                  
                {
                    MyFile.close();
                    return Supplier;
                }
            }

            MyFile.close();

        }

        return _GetEmptySupplierObject();

    }

    static bool IsSupplierExist(string ID)
    {
        clsSupplier Supplier = clsSupplier::Find(ID);
        return (!Supplier.IsEmpty());

    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildFullNameExists = 2 };


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsSupplier::IsSupplierExist(ID()))
            {
                return enSaveResults::svFaildFullNameExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }



        }
    }

    static clsSupplier GetAddNewSupplierObject(string ID)
    {
        return clsSupplier(enMode::AddNewMode, "","","", "", ID, "","");
    }

    bool Delete()
    {

        vector<clsSupplier> _vSuppliers;
        _vSuppliers = _LoadSuppliersDataFromFile();


        for (clsSupplier& S : _vSuppliers)
        {
            if (S.FullName() == FullName())
            {
                S._MarkForDelete = true;
                break;
            }
        }

        _SaveSuppliersDataToFile(_vSuppliers);
        *this = _GetEmptySupplierObject();

        return true;
    }

};

