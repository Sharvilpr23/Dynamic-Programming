#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> arr = {2, 3, 7, 8, 10};
	int sum = 10;

	vector<vector<bool>> dp;
	dp.resize(arr.size() + 1);
	for(int i = 0; i < arr.size() + 1; i++)
		dp[i].resize(sum + 1, false);
	
	for(int i = 0; i < arr.size() + 1; i++)
	{
		dp[i][0] = true;
	}
	
	for(int i = 1; i < arr.size() + 1; i++)
	{
		for(int j = 1; j < sum + 1; j++)
		{
			if(arr[i - 1] <= j)
			{
				dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j] );
			}
			else if(arr[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	if(dp[arr.size()][sum]) cout << "Subset Found" << endl;
	else cout << "Subset not found" << endl;
	
	return 0;
}
