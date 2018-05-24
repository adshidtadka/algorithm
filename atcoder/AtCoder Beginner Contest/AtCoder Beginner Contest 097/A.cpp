#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	bool can = false;

	cin >> a >> b >> c >> d;

	if (abs(a-c) <= d)
	{
		can = true;
	} else if (abs(a-b) <= d)
	{
		if (abs(b-c) <= d)
		{
			can = true;
		}
	}

	if (can)
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}