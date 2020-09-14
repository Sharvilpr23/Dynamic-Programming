#include<bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
	if(n == 0 || m == 0) return 0;
	
	if(dp[n][m] != -1) return dp[n][m];

	if(s1[n - 1] == s2[m - 1]) 
	{
		dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1, dp);
		return dp[n][m];
	}
	else
	{
		dp[n][m] = max(lcs(s1, s2, n - 1, m, dp), lcs(s1, s2, n, m - 1, dp));
		return dp[n][m];
	}
}

int main()
{
	string s1 = "abcdfh";
	string s2 = "abedgh";
 
	vector<vector<int>> dp;
	dp.resize(s1.length() + 1);
	for(int i = 0; i < s1.length() + 1; i++)
		dp[i].resize(s2.length() + 1, -1);

	for(int i = 0; i < s1.length() + 1; i++)
		dp[0][i] = 0;

	for(int i = 0; i < s2.length() + 1; i++)
		dp[i][0] = 0;


	cout << "Length of longest common subsequence: " 
		<< lcs(s1, s2, s1.length(), s2.length(), dp) << endl;

	return 0;
}
