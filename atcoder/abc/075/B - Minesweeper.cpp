#include<iostream>
#include <string>
using namespace std;

int main()
{
	int H, W;
	string s[55];

	cin >> H >> W;
	for (int i = 0; i < H; ++i)
	{
		cin >> s[i];
	}

	const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (s[i][j] == '#')
			{
				continue;
			}
			int count = 0;
			for (int k = 0; k < 8; ++k)
			{
				int ni = i + dy[k];
				int nj = j + dx[k];

				if (ni < 0 || ni > H-1 || nj < 0 || nj > W-1)
				{
					continue;
				}
				if (s[ni][nj] == '#')
				{
					count++;
				}
			}
			s[i][j] = char(count + '0'); //どういうこと？
		}
	}

	for (int i = 0; i < H; ++i)
	{
		cout << s[i] << endl;
	}


	return 0;
}