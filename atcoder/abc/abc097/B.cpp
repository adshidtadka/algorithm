#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	double ans;

	cin >> x;

	for (double i = 2; i <= 10; ++i)
	{
		for (double j = 1; j <= sqrt(x); ++j)
		{
			if (pow(j, i) <= x && pow(j, i) > ans )
			{
				ans = pow(j, i);
			}
		}
	}
	cout << ans << endl;
	return 0;

}