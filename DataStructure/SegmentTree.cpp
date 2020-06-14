/* <SegmentTree> */

template<typename M>
struct SegmentTree
{
	const int n;
	std::vector<M> data;
	SegmentTree(int n) : n(n),data(n<<1,M::I()) {}
	M& operator[](int i) { return data[i+n]; }
	void update(int i) { for(i+=n;i>1;i>>=1) data[i>>1]=M::f(data[i],data[i^1]); }
	void build() { for(int i=n-1;i>0;i--) data[i]=M::f(data[i<<1],data[i<<1|1]); }
	M query(int l, int r) const {
		M L=M::I(), R=M::I();
		for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
			if(l&1) L=M::f(data[l++],L);
			if(r&1) R=M::f(R,data[--r]);
		}
		return M::f(L,R);
	}
};

/* <SegmentTree> */

/* <SegmentTree::Template> */
template<typename T=lnt>
struct Template
{
	T v;
	static Template I() { return Template(0); }
	Template(T v) : v(v) {}
	static Template f(const Template& lhs, const Template& rhs) { return lhs+rhs; }
	operator T() const { return v; }
};
/* <SegmentTree::Template> */

/* <SegmentTree::RangeSum> */
template<typename T=lnt>
struct RangeSum
{
	T v;
	static RangeSum I() { return RangeSum(0); }
	RangeSum(T v) : v(v) {}
	static RangeSum f(const RangeSum& lhs, const RangeSum& rhs) { return lhs+rhs; }
	operator T() const { return v; }
};
/* <SegmentTree::RangeSum> */

/* <SegmentTree::RangeMin> */
template<typename T=lnt>
struct RangeMin
{
	T v;
	static RangeMin I() { return RangeMin(std::numeric_limits<T>::max()); }
	RangeMin(T v) : v(v) {}
	static RangeMin f(const RangeMin& lhs, const RangeMin& rhs) { return std::min(lhs,rhs); }
	operator T() const { return v; }
};
/* <SegmentTree::RangeMin> */

/* <SegmentTree::RangeMax> */
template<typename T=lnt>
struct RangeMax
{
	T v;
	static RangeMax I() { return RangeMax(std::numeric_limits<T>::min()); }
	RangeMax(T v) : v(v) {}
	static RangeMax f(const RangeMax& lhs, const RangeMax& rhs) { return std::max(lhs,rhs); }
	operator T() const { return v; }
};
/* <SegmentTree::RangeMax> */

/* <SegmentTree::RangeMinIndex> */
template<typename T=lnt>
struct RangeMinIndex
{
	T v; int i;
	static RangeMinIndex I() { return RangeMinIndex(std::numeric_limits<T>::max(),-1); }
	RangeMinIndex(T v, int i) : v(v),i(i) {}
	static RangeMinIndex f(const RangeMinIndex& lhs, const RangeMinIndex& rhs) { if(lhs.v<rhs.v) return lhs; else return rhs; }
	operator T() const { return v; }
};
/* <SegmentTree::RangeMinIndex> */

