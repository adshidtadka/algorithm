#include<iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int a[100000];
	int count = 0;
	int light = 1;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		light = a[light];
		count++;
		if (light == 2)
		{
			break;
		}
	}

	if (count != n)
	{
		cout << count << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}