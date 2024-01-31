#include <iostream>
#include <cassert>
using namespace std;

#include "MyTypes.h"
#include "Out of Class.h"


void main()
{
	Stock myst("~~~ My Perfect Stock ~~~");

	cout << "\nName : " << myst.Get_Name() << endl;
	cout << "\nProduct Count : " << myst.Get_Count() << endl;

	myst.Print();

	myst.Set_Name(">>> My Perfect Stock <<<");

	Product* p1 = new Product("Meat", "Fresh Berde Cow Meat", new double(14.5), new short int(5));
	Product* p2 = new Product("Rice", "Fresh Astara Rice", new double(8.5), new short int(15));
	Product* p3 = new Product("Tomato", "Fresh Khachmaz Tomato", new double(3.5), new short int(10));

	myst.Set_Products(*p1);
	myst.Set_Products(*p2);
	myst.Set_Products(*p3);

	cout << "\n\n=====================================\n\n";

	myst.Print();


}