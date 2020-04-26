#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	long a, b, x;
	long ans;

	cin >> a >> b >> x;

	if (a != 0)
	{
		ans = b/x - (a-1)/x;
	} else {
		ans = b/x + 1;
	}
	
	cout << ans << endl;

	return 0;
}