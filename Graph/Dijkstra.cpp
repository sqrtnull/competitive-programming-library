/* <Dijkstra> */

template <typename T>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int,T> > > & G, int s) {
	const T INF = std::numeric_limits<T>::max();
	int n = G.size();
	using n_node = std::pair<T,int>;
	std::vector<T> dist(n,INF);
	std::priority_queue<n_node,std::vector<n_node>,std::greater<n_node> > next;
	next.emplace(0,s);
	while(!next.empty()) {
		n_node t = next.top(); next.pop();
		int i = t.second; T cost = t.first;
		if(dist[i]!=INF) continue;
		dist[i] = cost;
		for(auto e:G[i]) {
			next.emplace(cost+e.second,e.first);
		}
	}
	return dist;
}

/* <Dijkstra> */