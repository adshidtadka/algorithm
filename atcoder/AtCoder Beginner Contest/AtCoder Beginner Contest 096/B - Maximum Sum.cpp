#include<iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, C;
	int K;
	int max;
	int ans;

	cin >> A >> B >> C;
	cin >> K;

	vector<int> v;

	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	sort(v.begin(), v.end());
	max = v[2];
	ans = max;
	for (int i = 0; i < K; ++i)
	{
		ans *= 2;
	}

	ans += v[0] + v[1];

	cout << ans << endl;

	return 0;

}