#include<iostream>
using namespace std;

int main()
{
	int n;
	int a[2][110];
	int max_num = 0;

	cin >> n;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int num = 0;
		for (int j = 0; j <= i; ++j)
		{
			num += a[0][j];
		}
		for (int j = i; j < n; ++j)
		{
			num += a[1][j];
		}
		if (num > max_num)
		{
			max_num = num;
		}
	}

	cout << max_num << endl;

	return 0;
}