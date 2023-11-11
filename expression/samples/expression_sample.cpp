#include <iostream>
#include "MyExpression.h"
using namespace std;

int main()
{
	try {
		string input;
		cout << "Enter expression: ";
		cin >> input;

		TArithmeticExpression expression(input);
		cout << expression.GetInfix() << endl;
		cout << expression.GetPostfix() << endl;
		vector<string> operands = expression.GetOperands();

		map<string, double> values;
		double value;
		for (const auto& op : operands)
		{
			cout << "Enter value of " << op << ": ";
			cin >> value;
			values[op] = value;
		}
		cout << expression.Calculate(values) << endl;
	}
	catch (exception e) {
		cerr << e.what();
	}
}
