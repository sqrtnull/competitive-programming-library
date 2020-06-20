using lnt = long long;
/* <modint> */

constexpr lnt MOD = 1e9+7;
constexpr lnt MOD = 998244353;
struct mint
{
    lnt v;
    mint():v(0){}
    mint(lnt v):v((v+MOD)%MOD){}
    mint operator-()const{ return mint(0) - *this; }
    mint& operator+=(const mint& a){ if((v+=a.v)>=MOD) v-=MOD; return *this; }
    mint& operator-=(const mint& a){ if((v+=MOD-a.v)>=MOD) v-=MOD; return *this; }
    mint& operator*=(const mint& a){ (v*=a.v)%=MOD; return *this; }
    mint& operator/=(const mint& a){ (*this) *= a.inv(); return *this; }
    mint operator+(const mint& a)const{ return mint(*this) += a; }
    mint operator-(const mint& a)const{ return mint(*this) -= a; }
    mint operator*(const mint& a)const{ return mint(*this) *= a; }
    mint operator/(const mint& a)const{ return mint(*this) /= a; }
    bool operator<(const mint& a)const{ return v < a.v; }
    bool operator==(const mint& a)const{ return v == a.v; }
    mint pow(lnt k)const{ mint r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }
    mint inv()const{ return pow(MOD-2); }
    static mint comb(lnt n, lnt k) { if(n-k<k) k=n-k; mint num(1), dom(1); for(int i=0;i<k;i++) { num*=n-i; dom*=i+1; } return num/dom; }
    static std::vector<mint> construct_comb(int n) {
        std::vector<mint> c(n+1); mint a = 1; c[0] = a; for(int i=1;i<=n;i++) { a = a*mint(n+1-i)/i; c[i] = a; } return c;
    }
    static std::vector<mint> construct_fact(int n) { std::vector<mint> f(n+1,1); for(int i=2;i<=n;i++) f[i]=f[i-1]*i; return f; }
};
std::istream& operator>>(std::istream&i,mint&a){ lnt t; i>>t; a=mint(t); return i; }
std::ostream& operator<<(std::ostream&o,const mint&a){ o<<a.v; return o; }

/* <modint> */
