#include<iostream>
#include <sstream>
using namespace std;

int main()
{
	int n, y;
	bool ok = false;
	stringstream ss;
	string s;

	cin >> n >> y;

	for (int i = y/10000; i >= 0; --i)
	{
		for (int j = 0; j <= n-i; ++j)
		{
			if (10000*i + 5000*j + 1000*(n-i-j) == y)
			{
				ok = true;
				ss << i << " " << j << " " << n-i-j;
				s = ss.str();
				break;
			}
		}
		if (ok)
		{
			break;
		}
	}

	if (ok)
	{
		cout << s << endl;
	} else {
		cout << -1 << " " << -1 << " " << -1 << endl;
	}

	return 0;
}