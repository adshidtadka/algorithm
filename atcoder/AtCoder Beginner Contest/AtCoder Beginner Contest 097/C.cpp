#include<iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string S;
	int K, N;

	cin >> S >> K;

	N = S.length();

	vector<string> s;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j < 6; ++j)
		{
			s.push_back(S.substr(i,j));
		}
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	cout << s[K - 1] << endl;

	return 0;
}