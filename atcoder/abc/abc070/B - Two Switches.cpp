#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	int t;

	cin >> a >> b >> c >> d;

	if (a < c)
	{
		if (b < d)
		{
			t = b - c;
		} else {
			t = d - c;
		}
	} else {
		if (b < d)
		{
			t = b - a;
		} else {
			t = d - a;
		}
	}

	if (t < 0)
	{
		cout << 0 << endl;
	} else {
		cout << t << endl;
	}

	return 0;
}