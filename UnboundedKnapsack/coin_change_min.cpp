#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> coins = {1, 2, 3, 5};
	int sum = 10;

	vector<vector<int>> dp;
	dp.resize(coins.size() + 1);
	for(int i = 0; i < coins.size() + 1; i++)
		dp[i].resize(sum + 1);

	for(int i = 0; i < coins.size() + 1; i++)
		dp[i][0] = 0;

	for(int i = 0; i < sum + 1; i++)
		dp[0][i] = INT_MAX - 1;

	for(int i = 0; i < sum + 1; i++)
	{
		if(i % coins[0] == 0)
			dp[0][i] = 1;
		else dp[0][i] = INT_MAX - 1;
	}

	for(int i = 1; i < coins.size() + 1; i++)
		for(int j = 1; j < sum + 1; j++)
		{
			if(coins[i - 1] <= j)
			{
				dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
			}
			else if(coins[i - 1] > j)
				dp[i][j] = dp[i - 1] [j];
		}

	cout << "Minimum number of coins required: " << dp[coins.size()][sum] << endl;
	return 0;
}

