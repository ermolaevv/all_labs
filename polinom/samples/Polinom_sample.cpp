#include "Polinom.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "Зададим трехпеременные мономы,в ходе работы с которыми создадим полиномы:\n";


		int d1[] = { 7, 3, 4 };
		int d2[] = { 5, 1, 1 };
		int d3[] = { 1, 1, 0 };
		int d4[] = { 23, 7, 645 };
		int d5[] = { 3, 5, 0 };

		TMonom m1(5, 3, d1);
		TMonom m2(3, 3, d2);
		TMonom m3(1, 3, d3);
		TMonom m4(9, 3, d1);
		TMonom m5(0, 3, d4);
		TMonom m6(3, 3, d5);

		cout << "m1: " << m1 << endl;
		cout << "m2: " << m2 << endl;
		cout << "m3: " << m3 << endl;
		cout << "m4: " << m4 << endl;
		cout << "m5: " << m5 << endl;
		cout << "m6: " << m6 << endl;

		TPolinom p1;
		p1.AddMonom(m1);
		p1.AddMonom(m2);
		p1.AddMonom(m3);
		cout << "\np1(m1, m2, m3): " << p1 << endl;

		TPolinom p2;
		p2.AddMonom(m4);
		p2.AddMonom(m5);
		p2.AddMonom(m6);
		cout << "p2(m4, m5, m6): " << p2 << endl;

		TPolinom res;

		res = p1 + p2;
		cout << "\np1 + p2: " << res << endl;

		res = p1 - p2;
		cout << "\np1 - p2: " << res << endl;

		res = p1 * p2;
		cout << "\np1 * p2: " << res << endl;

		res = p1 * m3;
		cout << "\np1 * m3: " << res << endl;
		
		res = p1 * 4;
		cout << "\np1 * 4: " << res << endl;

		cout << "\nres:\n";

		cout << "Length: " << res.GetLength() << endl << endl;

		cout << "res == p1? ";
		if (res == p1)
			cout << "res == p1";
		else
			cout << "res != p1";
		cout << endl;

		res = p2;
		cout << "res = p2: " << res << endl << endl;
	
		TPolinom P, Q;

		int deg11[] = { 5, 2, 5 };
		int deg12[] = { 4, 3, 3 };
		int deg13[] = { 7, 5, 1 };

		P.AddMonom(TMonom(3, 3, deg11));
		P.AddMonom(TMonom(-5, 3, deg12));
		P.AddMonom(TMonom(7, 3, deg13));

		Q.AddMonom(TMonom(-3, 3, deg11));
		Q.AddMonom(TMonom(5, 3, deg12));
		Q.AddMonom(TMonom(-7, 3, deg13));

		cout << "P: " << P << endl;
		cout << "Q: " << Q << endl;

		TPolinom pol = P + Q;
		cout << "P + Q: " << pol << endl;
	}

	catch (std::exception e)
	{
		cerr << e.what();
	}

	return 0;
}
