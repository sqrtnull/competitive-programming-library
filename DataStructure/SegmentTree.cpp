/* <SegmentTree> */

template <typename M>
struct SegmentTree
{
	const int n;
	const M I;
	const std::function<M(M,M)> f;
	std::vector<M> data;
	SegmentTree(int n, M I, std::function<M(M,M)> f)
		: n(n), I(I), f(f), data(2*n,I) {}
	void set(int i, const M& v) {
		data[n+i]=v;
	}
	void build() {
		for(int i=n-1;i>0;i--) {
			data[i]=f(data[i<<1],data[i<<1|1]);
		}
	}
	void update(int i, const M& v) {
		i+=n; data[i]=v;
		for(i>>=1;i>0;i>>=1) {
			data[i]=f(data[i<<1],data[i<<1|1]);
		}
	}
	M get(int i) {
		return data[n+i];
	}
	M query(int l, int r) {
		M L=I, R=I;
		l+=n; r+=n;
		while(r>l) {
			if(l&1) L=f(L,data[l++]);
			if(r&1) R=f(data[--r],R);
			l>>=1; r>>=1;
		}
		return f(L,R);
	}
};

/* <SegmentTree> */