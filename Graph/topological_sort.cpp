/* <topological_sort> */

std::vector<int> topological_sort(const std::vector<std::vector<int> >& g) {
	std::stack<int> stack;
	int n=g.size();
	std::vector<int> in(n,0);
	for(int i=0;i<n;i++) for(int to:g[i]) in[to]++;
	for(int i=0;i<n;i++) if(in[i]==0) stack.emplace(i);
	std::vector<int> sorted;
	sorted.reserve(n);
	while(!stack.empty()) {
		int i=stack.top(); stack.pop();
		for(int to:g[i]) {
			in[to]--;
			if(in[to]==0) stack.emplace(to);
		}
		sorted.emplace_back(i);
	}
	return sorted;
}

/* <topological_sort> */
