using lnt = long long;
/* <Kruskal> */
/* requires <UnionFind> */

struct Edge
{
	int a,b; lnt c;
	Edge(int a, int b, lnt c) : a(a), b(b), c(c) {}
};

std::vector<Edge> kruskal(int n,std::vector<Edge>&edges) {
	std::sort(edges.begin(), edges.end(),
		[] (Edge a, Edge b) { return a.c < b.c; } );
	UnionFind uf(n);
	std::vector<Edge> min_tree;
	for(Edge e:edges) {
		if(uf.find(e.a)==uf.find(e.b)) continue;
		min_tree.push_back(e);
		uf.unite(e.a,e.b);
	}
	return min_tree;
}

/* <Kruskal> */