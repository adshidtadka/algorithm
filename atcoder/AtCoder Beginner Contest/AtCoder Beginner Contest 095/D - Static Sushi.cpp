#include<iostream>
using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;

	int x[100010], v[100010];
	int max = 0;


	for (int i = 0; i < N; ++i)
	{
		cin >> x[i] >> v[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int cal = 0;
			for (int k = 0; k < i; ++k)
			{
				cal += v[k];
			}
			if (j != 0)
			{
				for (int k = j+1; k < N-1; ++k)
				{
					cal += v[k];
				}
			}
			cal -= x[i]*2 + C - x[j];
			if (max < cal)
			{
				max = cal;
				cout << "i = " << i << ", j = " << j << ", cal = "  << cal << endl;
			}
		}
	}

	cout << max << endl;

	return 0;

}