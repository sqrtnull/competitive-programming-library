using lnt = long long;
/* <protoWaveletMatrix> */

struct protoWaveletMatrix
{
    static constexpr int H = 63;
    int n;
    std::vector<std::vector<int>> data;
    protoWaveletMatrix(std::vector<lnt> v) : n(v.size()), data(H,std::vector<int>(v.size()+1,0)) {
        std::vector<lnt> vv(n);
        for(int h=H-1;h>=0;--h) {
            int cnt=0;
            // count 0s
            for(int i=0;i<n;++i) {
                if(!(v[i]>>h&1)) {
                    vv[cnt]=v[i];
                    ++cnt;
                    data[h][i+1]=cnt;
                }
            }
            for(int i=0;i<n;++i) {
                if(v[i]>>h&1) {
                    vv[cnt]=v[i];
                    ++cnt;
                }
            }
            std::swap(v,vv);
        }
    }
    lnt quantile(int l, int r, int k) {
        lnt ans=0;
        for(int h=H-1;h>=0;--h) {
            int o = data[h][r]-data[h][l];
            if(k<=o) {
                r=data[h][r];
                l=data[h][l];
            } else {
                ans|=((lnt)1)<<h;
                r=data[h][n]+r-data[h][r];
                l=data[h][n]+l-data[h][l];
                k-=o;
            }
        }
        return ans;
    }
};

/* <protoWaveletMatrix> */