using lnt=long long;
/* <LazySegmentTree> */

template<typename M, typename OM>
struct LazySegmentTree
{
	int n,h;
	std::vector<M> data; std::vector<OM> lazy;
	LazySegmentTree(int N) : n(1),h(0) { while(n<N) n<<=1,h++; data.assign(n<<1,M::I()); lazy.assign(n,OM::I()); }
	M& operator[](int i) { return data[i+n]; } // unsafe. use only with build
	void build() { for(int i=n-1;i>0;i--) data[i]=M::f(data[i<<1],data[i<<1|1]); }
	void apply(int i, const OM& o) { if(i<n) lazy[i]=OM::h(lazy[i],o); data[i]=OM::g(data[i],o); }
	void propagate(int i) { if(lazy[i].alive) { apply(i<<1,lazy[i]); apply(i<<1|1,lazy[i]); lazy[i]=OM::I(); } }
	void thrust(int i) { for(int j=h;j>0;j--) propagate(i>>j); }
	void recalc(int i) { for(;i>1;i>>=1) data[i>>1]=M::f(data[i],data[i^1]); }
	void update(int l, int r, const OM& o) {
		l+=n;r+=n; int l0=l/(l&-l),r0=r/(r&-r); thrust(l0); thrust(r0-1);
		for(;l<r;l>>=1,r>>=1) { if(l&1) apply(l++,o); if(r&1) apply(--r,o); }
		recalc(l0); recalc(r0-1);
	}
	M fold(int l, int r) {
		l+=n;r+=n; int l0=l/(l&-l),r0=r/(r&-r); thrust(l0); thrust(r0-1); recalc(l0); recalc(r0-1);
		M L=M::I(),R=M::I();
		for(;l<r;l>>=1,r>>=1) { if(l&1) L=M::f(L,data[l++]); if(r&1) R=M::f(data[--r],R); }
		return M::f(L,R);
	}
	M get(int i) { return fold(i,i+1); }
};

/* <LazySegmentTree> */

/* <LazySegmentTree::RangeAffineRangeSum> */
template<typename T=lnt>
struct RangeAffineRangeSum
{
	struct M
	{
		T v; int n;
		static M I() { return M(0,1); }
		M(T v, int n=1) : v(v),n(n) {}
		static M f(const M& lhs, const M& rhs) { return M(lhs.v+rhs.v,lhs.n+rhs.n); }
		operator T() const { return v; }
	};

	struct OM
	{
		T a, b; bool alive;
		static OM I() { return OM(); }
		OM() : alive(false) {}
		OM(T a, T b) : a(a),b(b),alive(true) {}
		static M g(const M& m, const OM& om) { if(om.alive) return M(m.v*om.a+T(m.n)*om.b,m.n); else return m; }
		static OM h(const OM& first, const OM& second) {
			if(first.alive&&second.alive) return OM(first.a*second.a, first.b*second.a+second.b);
			return (first.alive)?first:second;
		}
	};
};
/* <LazySegmentTree::RangeAffineRangeSum> */
