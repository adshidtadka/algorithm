#include<iostream>
using namespace std;

int main()
{
	int n, x;
	int m[110];
	int total = 0;
	int min = 1000;
	int ans;

	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i];
		total += m[i];
		if (m[i] < min)
		{
			min = m[i];
		}
	}

	ans =  n + (x-total)/min;

	cout << ans << endl;
}