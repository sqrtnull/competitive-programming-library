using lnt = long long;
/* <LIS> */

int LIS(std::vector<lnt> a) {
    constexpr lnt INF = 2e18;
    std::vector<lnt> dp(a.size()+1,INF);
    for(auto i:a) {
        auto lb = std::lower_bound(all(dp),i);
        if(*lb>i) *lb = i;
    }
    int len = 0;
    while(dp[len]!=INF) len++;
    return len;
}

/* <LIS> */