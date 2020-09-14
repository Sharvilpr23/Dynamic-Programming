#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
	vector<int> arr = {1, 5, 11, 5};
	int sum = accumulate(arr.begin(), arr.end(), 0);
	
	if(sum % 2 == 1) 
	{
		cout << "Partition not possible" << endl;
	}
	else
	{	
		sum /= 2;
		vector<vector<bool>> dp;
		dp.resize(arr.size() + 1);
		for(int i = 0; i < arr.size() + 1; i++)
			dp[i].resize(sum + 1, false);
		
		for(int i = 0; i < arr.size(); i++)
			dp[i][0] = true;

		for(int i = 1; i < arr.size() + 1; i++)
		{
			for(int j = 1; j < sum + 1; j++)
			{
				if(arr[i - 1] <= j)
					dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
				else if(arr[i - 1] > j)
					dp[i][j] = dp[i - 1][j];
			}
		}

		for(int i = 0; i < arr.size() + 1; i++)
		{
			if(dp[i][sum])
			{
				cout << "Partition found" << endl;
				return 0;
			}
		}

		cout << "Partition not found" << endl;
	}

	return 0;
}
