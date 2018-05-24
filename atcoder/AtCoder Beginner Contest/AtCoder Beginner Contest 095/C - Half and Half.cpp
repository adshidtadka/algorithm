#include<iostream>
using namespace std;

int main()
{
	int a, b, c, x, y;
	int min;

	cin >> a >> b >> c >> x >> y;

	if (x >= y)
	{
		min = c*2*x;
		for (int i = 0; i <= x; ++i)
		{
			if (min > a*i + c*(x-i)*2 + b*max(0,y-(x-i)))
			{
				min = a*i + c*(x-i)*2 + b*max(0,y-(x-i));
			}
		}
	}else{
		min = c*2*y;
		for (int i = 0; i <= y; ++i)
		{
			if (min > b*i + c*(y-i)*2 + a*max(0,x-(y-i)))
			{
				min = b*i + c*(y-i)*2 + a*max(0,x-(y-i));
			}
		}
	}

	cout << min << endl;

	return 0;

}