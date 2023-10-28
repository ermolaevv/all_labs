#include <iostream>
#include "MyStack.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	size_t size, op;
	int el;
	try {
		cout << "������� ������ �����: ";
		cin >> size;
		TStack<int> s(size);
		while (true) {
			cout << "���� ��������:\n"
				<< "1. �������� � ����\n"
				<< "2. ������� �������\n"
				<< "3. ������� �������\n"
				<< "4. ���������� ���������\n"
				<< "5. ������\n"
				<< "������ ��������: ";
			cin >> op;
			cout << endl;
			switch (op) {
			case 1:
				cout << "������� ������� (int): ";
				cin >> el;
				s.Push(el);
				break;
			case 2:
				s.Pop();
				break;
			case 3:
				cout << s.TopView() << endl;
				break;
			case 4:
				cout << s.GetTop() << endl;
				break;
			case 5:
				cout << s.GetSize() << endl;
				break;
			default:
				break;
			}

			cout << s << endl;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
}
