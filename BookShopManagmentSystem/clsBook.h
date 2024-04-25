#pragma once
#include<iostream>
#include<vector>
#include"clsString.h"
#include <fstream>
#include <string>
#include"Global.h"

using namespace std;
class clsBook
{
private:

    
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _Title;
	string _Author;
    string _State;
	float _Price;
	short _Quantity;
	bool _MarkForDelete = false;

    struct stTotalSalesInfo;
    

    static vector <stTotalSalesInfo> _LoadUserBooksFromFile()
    {
        vector <stTotalSalesInfo> vTotalSalesRecord;

        fstream MyFile;
        MyFile.open("Sales.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTotalSalesInfo TotalSalesRecord;

            while (getline(MyFile, Line))
            {

                TotalSalesRecord = _ConvertTotalSalesLineToRecord(Line);

                if (TotalSalesRecord.UserName == CurrentUser.UserName)
                {
                    vTotalSalesRecord.push_back(TotalSalesRecord);
                }

            }

            MyFile.close();

        }

        return vTotalSalesRecord;
    }

    static stTotalSalesInfo _ConvertTotalSalesLineToRecord(string Line, string Seperator = "#//#")
    {
        stTotalSalesInfo TotalSalesRecord;

        vector <string> TotalSalesRecordDataLine = clsString::Split(Line, Seperator);

        TotalSalesRecord.UserName = TotalSalesRecordDataLine[0];
        TotalSalesRecord.BookName = TotalSalesRecordDataLine[1];
        TotalSalesRecord.Price = stof(TotalSalesRecordDataLine[2]);
        TotalSalesRecord.TotalAmount = stof(TotalSalesRecordDataLine[3]);
        TotalSalesRecord.Amount = stof(TotalSalesRecordDataLine[4]);
        TotalSalesRecord.Date = TotalSalesRecordDataLine[5];


        return TotalSalesRecord;

    }

    static string _ConvertTotalSalesToLine(stTotalSalesInfo Sales, string Seperator = "#//#")
    {
        string TotalSales = "";

        TotalSales += Sales.UserName + Seperator;
        TotalSales += Sales.BookName + Seperator;
        TotalSales += to_string(Sales.Price) + Seperator;
        TotalSales += to_string(Sales.TotalAmount) + Seperator;
        TotalSales += to_string(Sales.Amount) + Seperator;
        TotalSales += Sales.Date;

        return TotalSales;
    }

    static void RegisterTotalSales(vector <stTotalSalesInfo> vBooks)
    {

        fstream MyFile;
        MyFile.open("Sales.txt", ios::out | ios::app);

        string DataLine;

        if (MyFile.is_open())
        {

            for (stTotalSalesInfo P : vBooks)
            {

                DataLine = _ConvertTotalSalesToLine(P);
                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    static vector <stTotalSalesInfo> _LoadTotalSalesFromFile()
    {
        vector <stTotalSalesInfo> vTotalSalesRecord;

        fstream MyFile;
        MyFile.open("Sales.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTotalSalesInfo TotalSalesRecord;

            while (getline(MyFile, Line))
            {

                TotalSalesRecord = _ConvertTotalSalesLineToRecord(Line);

                vTotalSalesRecord.push_back(TotalSalesRecord);

            }

            MyFile.close();

        }

        return vTotalSalesRecord;
    }

    static void _SaveTotalSalesDataToFile(vector <stTotalSalesInfo> vBooks)
    {

        fstream MyFile;
        MyFile.open("Sales.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (stTotalSalesInfo B : vBooks)
            {
                if (B.MarkForDeleted == false)
                {
                    DataLine = _ConvertTotalSalesToLine(B);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    static void _UpdateBookQuantityDuringPurchase(vector <stTotalSalesInfo> vBooks)
    {
        for (stTotalSalesInfo B : vBooks)
        {

            clsBook book = FindPremiumBook(B.BookName);
            if (B.Amount == book.Quantity)
            {
                book.Delete();
            }
            else
            {
                book.Quantity -= B.Amount;
                book.Save();
            }
        }
    }



    static clsBook _ConvertLinetoBookObject(string Line, string Seperator = "#//#")
    {
        vector<string> vBookData;
        vBookData = clsString::Split(Line, Seperator);

        return clsBook(enMode::UpdateMode, vBookData[0], vBookData[1], vBookData[2],stof(vBookData[3]),
            stol(vBookData[4]));

    }


    static string _ConverBookObjectToLine(clsBook Book, string Seperator = "#//#")
    {

        string stBookRecord = "";
        stBookRecord += Book.Title + Seperator;
        stBookRecord += Book.Author + Seperator;
        stBookRecord += Book.State + Seperator;
        stBookRecord += to_string(Book.Price) + Seperator;
        stBookRecord += to_string(Book.Quantity);
       
        return stBookRecord;

    }

    static  vector <clsBook> _LoadFreeBooksDataFromFile()
    {

        vector <clsBook> vBooks;

        fstream MyFile;
        MyFile.open("FreeBooks.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBook Book = _ConvertLinetoBookObject(Line);

                vBooks.push_back(Book);
            }

            MyFile.close();

        }

        return vBooks;

    }

    static  vector <clsBook> _LoadPremiumBooksDataFromFile()
    {

        vector <clsBook> vBooks;

        fstream MyFile;
        MyFile.open("PremiumBooks.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBook Book = _ConvertLinetoBookObject(Line);

                vBooks.push_back(Book);
            }

            MyFile.close();

        }

        return vBooks;

    }

    static void _SaveFreeBooksDataToFile(vector <clsBook> vBooks)
    {

        fstream MyFile;
        MyFile.open("FreeBooks.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBook B : vBooks)
            {
                if (B.MarkForDeleted() == false)
                {
                    DataLine = _ConverBookObjectToLine(B);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    static void _SavePremiumBooksDataToFile(vector <clsBook> vBooks)
    {

        fstream MyFile;
        MyFile.open("PremiumBooks.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBook B : vBooks)
            {
                if (B.MarkForDeleted() == false)
                {
                    DataLine = _ConverBookObjectToLine(B);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    bool _WhichState()
    {
        return (_State == "Premium") ? true : false;
    }

    void _Update()
    {
        vector <clsBook> _vBooks;

        bool whichState = _WhichState();

        (whichState) ? _vBooks = _LoadPremiumBooksDataFromFile() : _vBooks = _LoadFreeBooksDataFromFile();
        
        for (clsBook& B : _vBooks)
        {
            if (B.Title == _Title)
            {
                B = *this;
                break;
            }

        }

        (whichState) ? _SavePremiumBooksDataToFile(_vBooks) : _SaveFreeBooksDataToFile(_vBooks);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverBookObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        bool whichState = _WhichState();

        string FileName = "";
        (whichState) ? FileName = "PremiumBooks.txt" : FileName = "FreeBooks.txt";

        fstream MyFile;

        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

	static clsBook _GetEmptyBookObject()
	{
		return clsBook(enMode::EmptyMode, "", "","", 0.0, 0);
	}

public:

	clsBook(enMode Mode,string Title, string Author,string State, float Price, short Quantity)
	{
		_Mode = Mode;
		_Title = Title;
		_Author = Author;
        _State = State;
		_Price = Price;
		_Quantity = Quantity;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

    bool MarkForDeleted()
    {
        return _MarkForDelete;
    }

	void SetTitle(string Title)
	{
		_Title = Title;
	}

	string GetTitle()
	{
		return _Title;
	}

	__declspec(property(get = GetTitle, put = SetTitle)) string Title;

	void SetAuthor(string Author)
	{
		_Author = Author;
	}

	string GetAuthor()
	{
		return _Author;
	}

	__declspec(property(get = GetAuthor, put = SetAuthor)) string Author;

    void SetState(string State)
    {
        _State = State;
    }

    string GetState()
    {
        return _State;
    }

    __declspec(property(get = GetState, put = SetState)) string State;

	void SetPrice(float Price)
	{
		_Price = Price;
	}

	float GetPrice()
	{
		return _Price;
	}

	__declspec(property(get = GetPrice, put = SetPrice)) float Price;

	void SetQuantity(short Quantity)
	{
		_Quantity = Quantity;
	}

	short GetQuantity()
	{
		return _Quantity;
	}

	__declspec(property(get = GetQuantity, put = SetQuantity)) short Quantity;


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildTitleExists = 2 };


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
            if (clsBook::IsFreeBookExist(_Title)|| clsBook::IsPremiumBookExist(_Title))
            {
                return enSaveResults::svFaildTitleExists;
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

    static clsBook FindFreeBook(string Title)
    {
        fstream MyFile;

        Title = clsString::UpperAllString(Title);

        MyFile.open("FreeBooks.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBook Book = _ConvertLinetoBookObject(Line);
                if (clsString::UpperAllString(Book.Title) == Title)
                {
                    MyFile.close();
                    return Book;
                }

            }

            MyFile.close();

        }
        return _GetEmptyBookObject();


    }

    static clsBook FindPremiumBook(string Title)
    {
        fstream MyFile;
        Title = clsString::UpperAllString(Title);

        MyFile.open("PremiumBooks.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBook Book = _ConvertLinetoBookObject(Line);
                if (clsString::UpperAllString(Book.Title) == Title)
                {
                    MyFile.close();
                    return Book;
                }

            }

            MyFile.close();

        }


        return _GetEmptyBookObject();
    }

    static bool IsFreeBookExist(string Title)
    {
        
        clsBook Book = clsBook::FindFreeBook(Title);
        return (!Book.IsEmpty());
    }

    static bool IsPremiumBookExist(string Title)
    {

        clsBook Book = clsBook::FindPremiumBook(Title);
        return (!Book.IsEmpty());
    }

    static clsBook GetAddNewBookObject(string Title)
    {
        return clsBook(enMode::AddNewMode, Title, "", "", 0.0, 0);
    }

    bool Delete()
    {

        vector<clsBook> _vBooks;

        bool whichState = _WhichState();

        (whichState) ? _vBooks = _LoadPremiumBooksDataFromFile() : _vBooks = _LoadFreeBooksDataFromFile();

        for (clsBook& B : _vBooks)
        {
            if (B.Title == _Title)
            {
                B._MarkForDelete = true;
                break;
            }
        }

        (whichState) ? _SavePremiumBooksDataToFile(_vBooks) : _SaveFreeBooksDataToFile(_vBooks);

        *this = _GetEmptyBookObject();

        return true;
    }

    static vector<clsBook> GetFreeBookList()
    {
        return _LoadFreeBooksDataFromFile();
    }

    static vector<clsBook> GetPremiumBookList()
    {
        return _LoadPremiumBooksDataFromFile();
    }

    
    struct stTotalSalesInfo
    {
        string BookName;
        short Amount;
        float Price;
        string Date;
        string UserName;
        short TotalAmount;
        bool MarkForDeleted = false;
    };

    

    static  vector <stTotalSalesInfo> GetUserBooksList()
    {
        return _LoadUserBooksFromFile();
    }

    static  vector <stTotalSalesInfo> GetTotalSalesList()
    {
        return _LoadTotalSalesFromFile();
    }
    

    static bool Purchase(float SumOfPrices, vector <stTotalSalesInfo> Sales)
    {
        if (!CurrentUser.Withdraw(SumOfPrices))
        {
            return false;
        }

        
        RegisterTotalSales(Sales);
        _UpdateBookQuantityDuringPurchase(Sales);
        return true;


    }

    void CancelOrder()
    {
        vector<clsBook> vBooks = _LoadPremiumBooksDataFromFile();
        vector<stTotalSalesInfo> vSales = _LoadTotalSalesFromFile();
       

        vector<stTotalSalesInfo> demo;
      
        short Amount = 0;

        for (stTotalSalesInfo& T : vSales)
        {
            if (T.BookName == _Title && CurrentUser.UserName==T.UserName)
            {
                T.MarkForDeleted = true;
                demo.push_back(T);
                
            }
        }

        _SaveTotalSalesDataToFile(vSales);

        for (stTotalSalesInfo T : demo)
        {
            Amount += T.Amount;
        }

        for (clsBook& B : vBooks)
        {
            if (B.Title == _Title)
            {
                B.Quantity += Amount;
           
                break;
            }
        }

        
        _SavePremiumBooksDataToFile(vBooks);
        
        CurrentUser.Deposit((demo.at(0).Price * Amount) / 2);
       


    }



};

