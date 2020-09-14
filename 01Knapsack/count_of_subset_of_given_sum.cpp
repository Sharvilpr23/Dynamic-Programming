#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr = {2, 3, 5, 6, 8, 10};
	int sum = 10;

	vector<vector<int>> dp;
	dp.resize(arr.size() + 1);
	for(int i = 0; i < arr.size() + 1; i++)
		dp[i].resize(sum + 1, 0);

	for(int i = 0; i< arr.size() + 1; i++)
		dp[i][0] = 1;

	for(int i = 1; i < arr.size() + 1; i++)
	{
		for(int j = 1; j < sum + 1; j++)
		{
			if(arr[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
			}
			else if(arr[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << "Number of subsets present: " << dp[arr.size()][sum] << endl;
	return 0;
}
