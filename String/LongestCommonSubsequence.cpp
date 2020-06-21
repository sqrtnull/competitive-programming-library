/* <LCS> */

std::vector<std::vector<int> > LCS(std::string a, std::string b) {
	std::vector<std::vector<int> > dp(a.size()+1,std::vector<int>(b.size()+1));
	for(int i=0;i<a.size();i++) for(int j=0;j<b.size();j++) {
		if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
		else dp[i+1][j+1] = std::max(dp[i+1][j],dp[i][j+1]);
	}
	return dp;
}

/* <LCS> */