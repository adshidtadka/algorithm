#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	int count = k;

	for (int i = 1; i < n; ++i)
	{
		count *= k - 1;
	}

	cout << count << endl;
	return 0;
}