/* <matrix> */

template <typename T = int>
struct matrix
{
    const int n,m;
    std::vector<std::vector<T> > x;
    matrix(int n, int m, T k=0) : n(n),m(m),x(n,std::vector<T>(m,k)) {}
    matrix& operator+=(const matrix& a) { for(int i=0;i<a.n;i++) for(int j=0;j<a.m;j++) x[i][j]+=a.x[i][j]; return *this; }
    matrix& operator-=(const matrix& a) { for(int i=0;i<a.n;i++) for(int j=0;j<a.m;j++) x[i][j]-=a.x[i][j]; return *this; }
    matrix& operator*=(const matrix& a) {
        assert(m==a.n); matrix product(n,a.m);
        for(int i=0;i<n;i++) for(int j=0;j<a.m;j++) for(int k=0;k<m;k++) product.x[i][j]+=x[i][k]*a.x[k][j];
        x=product.x; return *this;
    }
    matrix operator+(const matrix& a) const { return matrix(*this) += a; }
    matrix operator-(const matrix& a) const { return matrix(*this) -= a; }
    matrix operator*(const matrix& a) const { return matrix(*this) *= a; }
    bool operator==(const matrix& a) const { return x==a.x; }
    matrix pow(int k) const {
        assert(n==m);
        matrix r(n,n), t(*this);
        for(int i=0;i<n;i++) r.x[i][i]=1;
        while(k) { if(k&1) r*=t; t*=t; k>>=1; }
        return r;
    }
};
template <typename T>
std::ostream& operator<<(std::ostream& o,const matrix<T>& a){
    for(int i=0;i<a.n;i++) { for(int j=0;j<a.m;j++) o<<a.x[i][j]<<' '; o<<'\n'; } return o;
}

/* <matrix> */