#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a = "agbcba";
	string b = string(a.rbegin(), a.rend());

	vector<vector<int>> dp;
	dp.resize(a.length() + 1);
	for(int i = 0; i < a.length() + 1; i++)
		dp[i].resize(b.length() + 1, -1);

	for(int i = 0; i < a.length() + 1; i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	
	for(int i = 1; i < a.length() + 1; i++)
		for(int j = 1; j < b.length() + 1; j++)
		{
			if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}

	cout << "Minimum number of deletions to make a palindrome: " << a.length() - dp[a.length()][b.length()] << endl;

	return 0;
}
