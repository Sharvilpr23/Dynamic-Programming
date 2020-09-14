#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack_recursive(vector<int> &, vector<int> &, int, int, vector<vector<int>> &);

int main()
{
	vector<int> weight = {1, 3, 4, 5};
	vector<int> val = {1, 4, 5, 7};
	int w = 7;

	vector<vector<int>> dp;

	dp.resize(100);
	for(int i = 0; i < 100; i++)
		dp[i].resize(1000, -1);
	
	int ans = knapsack_recursive(weight, val, w, weight.size(), dp);

	cout << "Answer: " << ans << endl;

	return 0;
}

int knapsack_recursive(vector<int> &weight, vector<int> &val, int w, int n, vector<vector<int>> &dp)
{
	if(n ==0 || w == 0) return 0;

	if(dp[n][w] != -1) return dp[n][w];

	if(weight[n - 1] <= w) 
	{
		dp[n][w] = max(val[n - 1] + knapsack_recursive(weight, val, w - weight[n - 1], n - 1, dp),
						knapsack_recursive(weight, val, w, n - 1, dp));
		return dp[n][w];
	}
	else if (weight[n - 1] > w)
	{
		dp[n][w] = knapsack_recursive(weight, val, w, n - 1, dp);
		return dp[n][w];
	}
}
	
