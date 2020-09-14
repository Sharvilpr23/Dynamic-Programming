#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

int main()
{
	vector<int> arr = {1, 6, 11, 5};
	int sum = 23; 
	vector<vector<bool>> dp;

	dp.resize(arr.size() + 1);
	for(int i = 0; i < arr.size() + 1; i++)
		dp[i].resize(sum + 1, false);

	for(int i = 0; i < arr.size() + 1; i++)
		dp[0][i] = true;

	for(int i = 1; i < arr.size() + 1; i++)
	{
		for(int j = 1; j < sum + 1; j++)
		{
			if(arr[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			}
			else if(arr[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	int m = 100000;

	for(int i = 0; i < sum + 1 && i <= sum / 2; i++)
	{
		if(dp[arr.size()][i])
			m = min(m, sum - (2 * i));
	}

	cout << "Minimum difference: " << m << endl;
	return 0;
}
