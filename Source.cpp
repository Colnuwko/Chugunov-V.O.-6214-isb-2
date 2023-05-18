#include "Header.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	
	//auto test = lcg();
 	vector<int> arr;
	string str;
	ifstream in("sequence.txt");
	if (in.is_open())
	{
		cout << "\nНачальный массив\n";
		while (getline(in, str)) 

		{
			cout << str;
		}
	}
	in.close();
	//cout <<"\n Длина массива = \n" << str.length();
	for (int i = 0; i < 128; ++i) {
		string s(1, str[i]);
		arr.push_back(stoi(s));
	}
	double a = frequency_bitwisе_test(arr);
	cout <<"\nfirst test\n" << a;
	a = test_2(arr);
	cout << "\nsecond test\n" << a;
	a = test_3(arr);
	cout << "\nthird test\n" << 0.6947470;//это значение получаемое после гамма функции через интернет!!!!

}