#include "array_in_out.hpp"
#include <iostream>
using namespace std;


int main(void)
{
    int i, j, key, counter=0, tmp;
    vector<int> array = array_in_out();
    for (j = 1; j < array.size(); j++)
    {
        key = array[j];
        i = j - 1;
        while ((i >= 0) && (array[i] > key)){
            counter++;
            tmp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = tmp;
            i = i - 1;
        }
        array[i + 1] = key;
        py_output(array);
    }
    cout
        << "\n Алгоритму потребовалось: "
        << counter
        << " сдвигов!\n";
    system("Pause");
    return 0;
}