#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	int start;
	bool can_choose = false;

	cin >> a >> b >> c;

	start = a%b;

	int a_sum = a;

	while(a_sum%b != start || a_sum == a) {
	    if (a_sum%b == c)
	    {
	    	can_choose = true;
	    	break;	
	    }
	    a_sum += a;
	}

	if (can_choose == true)
	{
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}