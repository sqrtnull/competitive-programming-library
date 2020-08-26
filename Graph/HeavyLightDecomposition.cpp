/* <HLD> */

struct HLD
{
	using Graph = std::vector<std::vector<int> >;
	std::vector<int> sz, in, out, par, nxt;
	Graph g, u_g;
	HLD(int n, Graph& u_g, int root=0)
		: sz(n),in(n),out(n),par(n),nxt(n)
		,g(n,std::vector<int>()), u_g(u_g)
	{
		dfs_tree(root);
		dfs_sz(root);
		dfs_hld(root);
	}
	void dfs_tree(int v,int p=-1) {
		par[v]=p;
		for(int to:u_g[v]) {
			if(to==p) continue;
			g[v].emplace_back(to);
			dfs_tree(to,v);
		}
	}
	void dfs_sz(int v) {
		sz[v]=1;
		for(int& to:g[v]) {
			dfs_sz(to);
			sz[v]+=sz[to];
			if(sz[to]>sz[g[v][0]]) std::swap(to,g[v][0]);
		}
	}
	int t=0;
	void dfs_hld(int v) {
		in[v]=t++;
		for(int to:g[v]) {
			nxt[to] = (to==g[v][0]) ? nxt[v] : to;
			dfs_hld(to);
		}
		out[v]=t;
	}
	int LCA(int a, int b) {
		while(nxt[a]!=nxt[b]) {
			if(in[a]>in[b]) std::swap(a,b);
			b=par[nxt[b]];
		}
		if(in[a]>in[b]) std::swap(a,b);
		return a;
	}
	struct I { int l, r; I(int l, int r) : l(l),r(r) {} };
	I get_subtree(int v) {
		return I(in[v],out[v]);
	}
	std::vector<I> get_path(int a, int b) {
		std::vector<I> intervals;
		while(nxt[a]!=nxt[b]) {
			if(in[a]>in[b]) std::swap(a,b);
			intervals.emplace_back(in[nxt[b]],in[b]+1);
			b=par[nxt[b]];
		}
		if(in[a]>in[b]) std::swap(a,b);
		intervals.emplace_back(in[a],in[b]+1);
		return intervals;
	}
};

/* <HLD> */
