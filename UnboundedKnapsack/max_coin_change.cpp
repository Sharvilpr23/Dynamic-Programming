#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> coins  = {1, 2, 3};
	int sum = 5;

	vector<vector<int>> dp;
	dp.resize(coins.size() + 1);
	for(int i = 0; i < coins.size() + 1; i++)
		dp[i].resize(sum + 1, 0);

	for(int i = 0; i < coins.size() + 1; i++)
		dp[i][0] = 1;

	for(int i = 1; i < coins.size() + 1; i++)
		for(int j = 1; j < sum + 1; j++)
		{
			if(coins[i - 1] <= j)
				dp[i][j] =  dp[i][j - coins[i - 1]] + dp[i - 1][j];
			else if(coins[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
		}

	cout << "Number of ways: " << dp[coins.size()][sum] << endl;
	return 0;
}
