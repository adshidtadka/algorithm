#include<iostream>
using namespace std;

int main()
{
	string num_4;
	int num[5];

	cin >> num_4;

	for (int i = 0; i < 4; ++i)
	{
		num[i] = int(num_4[i] - int('0'));
	}

	if (num[0] + num[1] + num[2] + num[3] == 7 )
	{
		printf("%d+%d+%d+%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] - num[1] + num[2] + num[3] == 7 ){
		printf("%d-%d+%d+%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] + num[1] - num[2] + num[3] == 7 ){
		printf("%d+%d-%d+%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] + num[1] + num[2] - num[3] == 7 ){
		printf("%d+%d+%d-%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] - num[1] - num[2] + num[3] == 7 ){
		printf("%d-%d-%d+%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] + num[1] - num[2] - num[3] == 7 ){
		printf("%d+%d-%d-%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] - num[1] + num[2] - num[3] == 7 ){
		printf("%d-%d+%d-%d=7\n", num[0], num[1], num[2], num[3]);
	} else if (num[0] - num[1] - num[2] - num[3] == 7 ){
		printf("%d-%d-%d-%d=7\n", num[0], num[1], num[2], num[3]);
	}
	
	return 0;
}