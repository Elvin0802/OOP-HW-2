#pragma once

class Product
{
private:

	static int* _ID;
	int _sID = 0; // s -> special
	char* _Name = nullptr;
	char* _Description = nullptr;
	double* _Price = nullptr;
	short int* _Discount = nullptr; // 0 - 100 %

public:

	Product();
	Product(const char* name);
	Product(const char* name, const char* description, const double* price);
	Product(const char* name, const char* description, const double* price, const short int* discount);

	void Set_sID(int id);
	void Set_Name(const char* name);
	void Set_Description(const char* description);
	void Set_Price(const double price);
	void Set_Discount(const short int discount);

	const int Get_sID();
	const char* Get_Name();
	const char* Get_Description();
	const double* Get_Price();
	const short int* Get_Discount();

	double Get_DiscountPrice();

	void Print();

	~Product();

};

class Stock
{
private:

	char* _Name = nullptr;
	Product** _Products = nullptr;
	size_t _Count = 0;


public:

	Stock(const char* name);
	Stock(const char* name, const Product& product);

	void Set_Name(const char* name);
	void Set_Products(const Product& newOneProduct);
	void Set_Count(const size_t count);

	const char* Get_Name();
	Product** Get_Products();
	const size_t Get_Count();

	void Print();

	const Product* GetProductByID(int id);

	~Stock();

};