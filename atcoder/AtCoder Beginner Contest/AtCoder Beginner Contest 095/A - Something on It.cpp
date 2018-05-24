#include<iostream>
using namespace std;

int main()
{
	string s;
	int total = 700;
	int topping = 0;

	cin >> s;

	for (int i = 0; i < 3; ++i)
	{
		if (s[i] == 'o')
		{
			topping += 100;
		}
	}

	cout << total + topping << endl;
}