#include<iostream>
using namespace std;

bool isprime(int p) {
	if (p == 1)
	{
		return false;
	}
	for (int i = 2; i < p; ++i)
	{
		if (p%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;

	cin >> n;

	int ans[55555];
	ans[0] = 11;

	for (int i = 1; i <= n; ++i)
	{
		int ans_can = ans[i-1] + 5;
		while(!isprime(ans_can)) {
		    ans_can += 5;
		}
		ans[i] = ans_can;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}