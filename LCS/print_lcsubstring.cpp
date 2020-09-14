#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1 = "abcdef";
	string s2 = "acbdef";

	vector<vector<int>> dp;
	dp.resize(s1.length() + 1);
	for(int i = 0; i < s1.length() + 1; i++)
		dp[i].resize(s2.length() + 1, -1);

	for(int i = 0; i < s1.length() + 1; i++)
		dp[i][0] = 0;

	for(int i = 0; i < s2.length() + 1; i++)
		dp[0][i] = 0;
	
	for(int i = 1; i < s1.length() + 1; i++)
		for(int j = 1; j < s1.length(); j++)
		{
			if(s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

	string output = "";

	int i = s1.length();
	int j = s2.length();

	while(i >= 0 && j >= 0)
	{
		if(s1[i - 1] == s2[j - 1])
		{
			output.insert(output.begin(), s1[i - 1]);
			i--;
			j--;
		}
		else
		{
			dp[i][j] = (dp[i - 1][j] > dp[i][j - 1])? (i--) : (j--);
		}
	}

	cout << "Longest common substring is " << output << endl;
	return 0;
}
