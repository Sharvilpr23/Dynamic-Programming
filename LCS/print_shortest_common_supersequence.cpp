#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a = "abcdaf";
	string b = "acbcf";

	vector<vector<int>> dp;
	dp.resize(a.length() + 1);
	for(int i = 0; i < a.length() + 1; i++)
		dp[i].resize(b.length() + 1, -1);

	for(int i = 0; i < a.length() + 1; i++)
		dp[i][0] = 0;

	for(int i = 0; i < b.length() + 1; i++)
		dp[0][i - 1] = 0;

	for(int i = 1; i < a.length() + 1; i++)
		for(int j = 1; j < b.length() + 1; j++)
		{
			if(a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	int i = a.length();
	int j = b.length();
	string output;

	while(i > 0 || j > 0)
	{
		if(a[i - 1] == b[j - 1])
		{
			output += a[i - 1];
			i--;
			j--;
		}
		else
		{
			if(dp[i][j - 1] > dp[i - 1][j])
			{
				output += b[--j];
			}
			else
				output += a[--i];
		}
	}

	while(i > 0)
	{
		output += a[--i];
	}

	while(j > 0)
		output += b[--j];

	reverse(output.begin(), output.end());
	cout << "Shortest common subsequence is: " << output << endl;
	return 0;
}

