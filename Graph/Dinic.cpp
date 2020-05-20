/* <Dinic> */

template <typename T = lnt, T INF = std::numeric_limits<T>::max()>
struct Dinic
{
	struct Edge
	{
		int a,b; T c,f;
		Edge(int a, int b, T c) : a(a),b(b),c(c),f(0) {}
	};
	int n,m;
	std::vector<Edge> E;
	std::vector<std::vector<int> > G,Gf;
	Dinic(int n) : n(n),m(0),G(n) {}
	void add_edge(int i, int j, int c) {
		E.emplace_back(i,j,c);
		E.emplace_back(j,i,0);
		G[i].emplace_back(m++);
		G[j].emplace_back(m++);
	}
	bool bfs(int s, int t) {
		Gf.assign(n,std::vector<int>());
		std::queue<int> que; que.emplace(s);
		std::vector<int> dist(n,-1); dist[s]=0;
		while(!que.empty()) {
			int i=que.front(); que.pop();
			for(int to:G[i]) {
				if(dist[E[to].b]!=-1 || E[to].c==E[to].f) continue;
				dist[E[to].b]=dist[E[to].a]+1;
				que.emplace(E[to].b);
			}
		}
		if(dist[t]==-1) return false;
		for(int i=0;i<m;i++) {
			if(dist[E[i].a]+1!=dist[E[i].b] || E[i].c==E[i].f) continue;
			if(dist[E[i].a]>=dist[t]) continue;
			Gf[E[i].a].emplace_back(i);
		}
		return true;
	}
	T dfs(int i, T a_f, const int& t) {
		if(i==t || a_f==0) {
			return a_f;
		}
		T v_f=0;
		for(int to:Gf[i]) {
			T f=dfs(E[to].b,std::min(a_f-v_f,E[to].c-E[to].f),t);
			if(f>0) {
				E[to].f+=f; E[to^1].f-=f;
				v_f+=f;
			}
			if(a_f==v_f) break;
		}
		return v_f;
	}
	T flow(int s, int t) {
		T max_flow=0;
		while(bfs(s,t)) {
			T f = dfs(s,INF,t);
			if(f==0) break;
			max_flow+=f;
		}
		return max_flow;
	}
};

/* <Dinic> */
