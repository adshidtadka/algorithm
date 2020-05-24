#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	int x[110], y[110];
	double ans = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			double distance;
			distance = sqrt(pow(double(x[i] - x[j]), 2.0) + pow(double(y[i] - y[j]), 2.0));
			if (distance > ans)
			{
				ans = distance;
			}
		}
	}

	cout << ans << endl;

	return 0;
}