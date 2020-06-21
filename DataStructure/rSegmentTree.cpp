/* <rSegmentTree> */
// deprecated

template <typename G>
struct rSegmentTree
{
	const int n;
	const G I;
	const std::function<G(G,G)> f, g;
	std::vector<G> data;
	rSegmentTree(int n, G I, std::function<G(G,G)> f, std::function<G(G,G)> g) : n(n), I(I), f(f), g(g), data(2*n,I) {}
	void set(int i, const G& v) {
		data[n+i] = v;
	}
	void update(int l, int r, const G& v) {
		l+=n; r+=n;
		while(r>l) {
			if(l&1) {
				if(l>=n) data[l] = f(data[l], v);
				else data[l] = g(data[l], v);
				l++;
			}
			if(r&1) {
				r--;
				if(r>=n) data[r] = f(data[r], v);
				else data[r] = g(data[r], v);
			}
			l>>=1; r>>=1;
		}
	}
	G get(int i) {
		G v = I;
		for(i+=n;i>0;i>>=1) v = f(v,data[i]);
		return v;
	}
};

/* <rSegmentTree> */
