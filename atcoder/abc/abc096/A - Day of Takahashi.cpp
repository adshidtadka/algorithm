#include<iostream>
using namespace std;

int main()
{
	int a, b;
	int count;

	cin >> a >> b;

	for (int i = 1; i <= a; ++i)
	{
		if (i == a)
		{
			for (int j = 1; j <= b; ++j)
			{
				if (i == j)
				{
					count++;
				}
			}			
		} else {
			for (int j = 1; j <= 31; ++j)
			{
				if (i == j)
				{
					count++;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}