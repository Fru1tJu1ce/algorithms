#include <iostream>
#include <vector>
using namespace std;


int py_output(vector<int>& a)
// Выводит переданный массив в формате вывода списка на питоне
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
// Ввод массива вручную с последующим выводом его в формате списка питона
{
	setlocale(LC_ALL, "Russian");
	size_t size;
	cout << "Введите размер массива: ";
	cin >> size;
	vector<int> a(size);
	for (size_t i = 0; i < size; i++) {
		cout
			<< "Введите "
			<< i + 1
			<< " элемент массива: ";
		cin >> a[i];
	}
	py_output(a);
	return a;
}