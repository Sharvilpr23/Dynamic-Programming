#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> rod = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = 8;

	vector<vector<int>> dp;
	dp.resize(rod.size() + 1);
	for(int i = 0; i < rod.size() + 1; i++)
		dp[i].resize(n + 1, 0);

	for(int i = 1; i < rod.size() + 1; i++)
	{
		for(int j = 1; j < n + 1; j++)
		{
			if(rod[i - 1] <= j)
				dp[i][j] = max(price[i - 1] + dp[i][j - rod[i - 1]], dp[i - 1][j]);
			else if(rod[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << "Maximum Profit: " << dp[rod.size()][n] << endl;
	return 0;
}
