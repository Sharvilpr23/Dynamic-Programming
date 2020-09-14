#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1 = "abcdfh";
	string s2 = "abedgh";

	vector<vector<int>> dp;
	dp.resize(s1.length() + 1);
	for(int i = 0; i < s1.length() + 1; i++)
		dp[i].resize(s2.length() + 1, -1);

	for(int i = 0; i < s1.length(); i++)
		dp[0][i] = 0;

	for(int i = 0; i < s2.length(); i++)
		dp[i][0] = 0;

	for(int i = 1; i < s1.length() + 1; i++)
		for(int j = 1; j < s2.length() + 1; j++)
		{
			if(s1[i - 1] == s2[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	cout << "Length of longest common subsequence: " << dp[s1.length()][s2.length()] << endl;
	return 0;
}
