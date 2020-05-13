/* <ZAlgorithm> */

std::vector<int> z_algorithm(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n,0);
    int l=0,r=0;
    z[0] = n;
    for(int i=1;i<n;i++) {
        z[i] = std::max((int)0, std::min(z[i-l], r-i+1));
        while(i+z[i]<n && s[z[i]] == s[i+z[i]]) {
            l=i; r=i+z[i]; z[i]++;
        }
    }
    return z;
}

/* <ZAlgorithm> */