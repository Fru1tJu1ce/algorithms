#include <iostream>
#include <vector>
using namespace std;


int py_output(vector<int>& a)
// ������� ���������� ������ � ������� ������ ������ �� ������
{
	cout << "[";
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i == a.size() - 1) {
			cout << "]\n";
		}
		else {
			cout << ", ";
		}
	}
	return 0;
}


vector<int> array_in_out()
// ���� ������� ������� � ����������� ������� ��� � ������� ������ ������
{
	setlocale(LC_ALL, "Russian");
	size_t size;
	cout << "������� ������ �������: ";
	cin >> size;
	vector<int> a(size);
	for (size_t i = 0; i < size; i++) {
		cout
			<< "������� "
			<< i + 1
			<< " ������� �������: ";
		cin >> a[i];
	}
	py_output(a);
	return a;
}