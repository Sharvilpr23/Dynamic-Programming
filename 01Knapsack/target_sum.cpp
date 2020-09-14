#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr = {1, 1, 2, 3,};
	int sum = 1;
	
	vector<vector<int>> dp;
	dp.resize(arr.size() + 1);
	for(int i = 0; i < arr.size() + 1; i++)
		dp[i].resize(sum + 1, 0);

	for(int i = 0; i < arr.size(); i++)
		dp[i][0] = 1;

	for(int i = 1; i < arr.size() + 1; i++)
	{
		for(int j = 1; j < sum + 1; j++)
		{
			if(arr[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - arr[i  - 1]] + dp[i - 1][j];
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << "Number of ways to reach the target sum are: " << dp[arr.size()][sum] << endl;
	return 0;
}
