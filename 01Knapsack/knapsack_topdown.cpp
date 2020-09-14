#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> weight = {1, 3, 4, 5};
	vector<int> val = {1, 4, 5, 7};
	int w = 7;

	vector<vector<int>> dp;
	dp.resize(100);
	for(int i = 0; i < 100; i++)
		dp[i].resize(1000, -1);

	for(int i = 0; i < weight.size(); i++)
	{
		dp[i][0] = 0;
	}

	for(int i = 0; i < w + 1; i++)
	{
		dp[0][i] = 0;
	}

	for(int i = 1; i < weight.size() + 1; i++)
	{
		for(int j = 1; j < w + 1; j++)
		{
			if(weight[i - 1] <= j)
			{
				dp[i][j] = max(val[i-1] + dp[i - 1][j - weight[i  - 1]], dp[i - 1][j]);
			}
			else if(weight[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << "Answer: " << dp[weight.size()][w] << endl;
	return 0;
}
