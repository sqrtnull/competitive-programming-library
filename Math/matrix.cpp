using lnt = long long;
/* <matrix> */

template <typename T = lnt>
struct matrix // designed for int and modint(not yet validated)
{
    const int n,m;
    std::vector<std::vector<T> > data;
    matrix(int n, int m, T k=0) : n(n),m(m),data(n,std::vector<T>(m,k)) {}
    matrix& operator+=(const matrix& a) {
        for(int i=0;i<a.n;++i) for(int j=0;j<a.m;++j) data[i][j]+=a.data[i][j];
        return *this;
    }
    matrix& operator-=(const matrix& a) {
        for(int i=0;i<a.n;++i) for(int j=0;j<a.m;++j) data[i][j]-=a.data[i][j];
        return *this;
    }
    matrix& operator*=(const matrix& a) {
        assert(m==a.n); matrix product(n,a.m);
        for(int i=0;i<n;++i) for(int j=0;j<a.m;++j) for(int k=0;k<m;++k) {
            product.data[i][j]+=data[i][k]*a.data[k][j];
        }
        data=product.data; return *this;
    }
    matrix operator+(const matrix& a) const { return matrix(*this) += a; }
    matrix operator-(const matrix& a) const { return matrix(*this) -= a; }
    matrix operator*(const matrix& a) const { return matrix(*this) *= a; }
    bool operator==(const matrix& a) const { return data==a.data; }
    matrix transpose() const {
        matrix t(m,n);
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
            t.data[j][i]=data[i][j];
        }
    }
    // square matrix
    matrix pow(int k) const {
        assert(n==m);
        matrix r(n,n), t(*this);
        for(int i=0;i<n;++i) { r.data[i][i]=1; }
        while(k) { if(k&1) r*=t; t*=t; k>>=1; }
        return r;
    }
    matrix det() const {
        assert(n==m);
        matrix A(*this);
        T d = A.GaussianElimination();
        T o = 1;
        for(int i=0;i<n;++i) { o*=A.data[i][i]; }
        o/=d;
        return o;
    }
    // in-place
    void swap_rows(int a, int b) { std::swap(data[a],data[b]); }
    void multiply_row(int i, T v) { for(T& a:data[i]) a*=v; }
    void add_multiple_to_row(int i, int j, T v) {
        for(int k=0;k<m;++k) data[i][k]+=data[j][k]*v;
    }
    T GaussianElimination() {
        int i=0,j=0;T d=1;
        while(i<n && j<m) {
            int pivot = i;
            T max = data[i][j];
            for(int x=i+1;x<n;++x) {
                if(max<data[x][j]) {
                    pivot=x;
                    max=data[x][j];
                }
            }
            if(data[pivot][j]==0) {
                ++j;
            } else {
                if(i!=pivot) d*=-1;
                swap_rows(i, pivot);
                for(int x=i+1;x<n;++x) {
                    T o = data[x][j];
                    d*=data[i][j];
                    multiply_row(x,data[i][j]);
                    add_multiple_to_row(x,i,-o);
                }
                ++i; ++j;
            }
        }
		return d;
    }
};
template <typename T>
std::ostream& operator<<(std::ostream& o,const matrix<T>& a){
    for(int i=0;i<a.n;++i) { for(int j=0;j<a.m;++j) o<<a.data[i][j]<<' '; o<<'\n'; }
    return o;
}

/* <matrix> */
