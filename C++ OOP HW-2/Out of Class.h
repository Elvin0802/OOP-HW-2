#pragma once

Product::Product()
{
	((*_ID)++);
	_sID = *_ID;
}

Product::Product(const char* name) : Product()
{
	Set_Name(name);
}

Product::Product(const char* name, const char* description, const double* price) : Product(name)
{
	Set_Description(description);
	Set_Price(*price);
}

Product::Product(const char* name, const char* description, const double* price, const short int* discount) : Product(name, description, price)
{
	Set_Discount(*discount);
}

void Product::Set_sID(int id)
{
	if (id > 0 && id > (*_ID))
	{
		this->_sID = id;
	}
	else assert(!"Daxil Edilmish id ID-den ferqli olmalidir.");
}
void Product::Set_Name(const char* name)
{
	if (name != nullptr)
	{
		int nameLen = strlen(name);

		if (nameLen > 3)
		{
			if (_Name != nullptr) delete[] _Name;

			_Name = new char[nameLen + 1];

			for (short int h = 0; h < nameLen; h++)
				_Name[h] = name[h];
			_Name[nameLen] = '\0';
		}
		else assert(!"Ad-in Uzunluqu 3 simvoldan chox olmalidir.");
	}
	else assert(!"Ad nullptr-dir.");

}
void Product::Set_Description(const char* description)
{
	if (description != nullptr)
	{
		int desLen = strlen(description);

		if (desLen > 5)
		{
			if (_Description != nullptr) delete[] _Description;

			_Description = new char[desLen + 1];

			for (short int h = 0; h < desLen; h++)
				_Description[h] = description[h];
			_Description[desLen] = '\0';
		}
		else assert(!"Izah-in Uzunluqu 5 simvoldan chox olmalidir.");
	}
	else assert(!"Izah nullptr-dir.");
}
void Product::Set_Price(const double price)
{
	if (price > 0)
	{
		if (_Price != nullptr) delete _Price;

		_Price = new double(price);
	}
	else assert(!"Qiymet 0-dan Boyuk olmalidir.");

}
void Product::Set_Discount(const short int discount)
{
	if (discount > 0 && discount < 101)
	{
		if (_Discount != nullptr) delete _Discount;

		_Discount = new short int(discount);
	}
	else assert(!"Endirim faizi 0 ile 100 arasinda olmalidir.");
}

const int Product::Get_sID() { return _sID; }
const char* Product::Get_Name() { return _Name; }
const char* Product::Get_Description() { return _Description; }
const double* Product::Get_Price() { return _Price; }
const short int* Product::Get_Discount() { return _Discount; }

double Product::Get_DiscountPrice()
{
	double newPrice = 0;

	if (_Price != nullptr && _Discount != nullptr)
		newPrice = (*_Price - ((*_Price * (*_Discount)) / 100.0));

	return newPrice;
}

void Product::Print()
{
	cout << "\n\tProduct Special ID : " << _sID << endl;
	cout << "\n\tProduct Name : " << ((_Name != nullptr) ? _Name : "nullptr") << endl;
	cout << "\n\tProduct Description : " << ((_Description != nullptr) ? _Description : "nullptr") << endl;
	cout << "\n\tProduct Price : " << ((_Price != nullptr) ? *_Price : 0.0) << " AZN " << endl;
	cout << "\n\tProduct Discount : " << ((_Discount != nullptr) ? *_Discount : 0) << " % " << endl;
}

Product::~Product()
{
	delete[] _Name;
	delete[] _Description;
	delete _Price;
	delete  _Discount;

	_Name = nullptr;
	_Description = nullptr;
	_Price = nullptr;
	_Discount = nullptr;
}

//---------------------------------

int* Product::_ID = new int(0);

//---------------------------------


Stock::Stock(const char* name)
{
	Set_Name(name);
	_Count++;
}

Stock::Stock(const char* name, const Product& product) : Stock(name)
{
	Set_Products(product);
}


void Stock::Set_Name(const char* name)
{
	if (name != nullptr)
	{
		int nameLen = strlen(name);

		if (nameLen > 3)
		{
			if (_Name != nullptr) delete[] _Name;

			_Name = new char[nameLen + 1];

			for (short int h = 0; h < nameLen; h++)
				_Name[h] = name[h];
			_Name[nameLen] = '\0';
		}
		else assert(!"Ad-in Uzunluqu 3 simvoldan chox olmalidir.");
	}
	else assert(!"Ad nullptr-dir.");
}
void Stock::Set_Products(const Product& newOneProduct)
{
	Product** ChangedProducts = new Product * [_Count + 1];

	if (_Products != nullptr)
	{
		for (int p = 0; p < _Count; p++)
		{
			ChangedProducts[p] = _Products[p];
		}
	}
	if (_Products == nullptr)
		ChangedProducts[0] = new Product(newOneProduct);
	else
		ChangedProducts[_Count++] = new Product(newOneProduct);

	delete[] _Products;
	_Products = ChangedProducts;

}
void Stock::Set_Count(const size_t count)
{
	if (count > 0)
	{
		_Count = count;
	}
	else assert(!"Say 0-dan Boyuk olmalidir.");
}

const char* Stock::Get_Name() { return _Name; }
Product** Stock::Get_Products() { return _Products; }
const size_t Stock::Get_Count() { return _Count; }

void Stock::Print()
{
	if (_Products != nullptr)
	{
		for (int prod = 0; prod < _Count; prod++)
		{
			cout << "\n\t>>>>>  Product - " << (prod + 1) << " <<<<<\n";
			_Products[prod]->Print();
			cout << "\n--------------------------------------------\n";
		}
	}
	else cout << "\nMehsul Yoxdur.\n";
}

const Product* Stock::GetProductByID(int id)
{
	for (int pr = 0; pr < _Count; pr++)
	{
		if (_Products[pr]->Get_sID() == id)
			return _Products[pr];
	}
	return nullptr;
}

Stock::~Stock()
{
	delete[] _Name;

	for (int p = 0; p < _Count; p++)
		delete _Products[p];
	delete[] _Products;
}