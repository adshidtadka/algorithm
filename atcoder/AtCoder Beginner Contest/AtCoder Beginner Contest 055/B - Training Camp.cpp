#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	long power = 1;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		power *= i;
		power %= 1000000007;
	}

	cout << power << endl;

	return 0;
}