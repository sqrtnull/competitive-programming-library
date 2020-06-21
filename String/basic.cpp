/* <string> */

std::vector<std::string> split(const std::string& s, char c) {
	int n=s.size();
	std::vector<std::string> v;
	for(int i=0;i<n;i++) {
		int start = i;
		while(i<n && s[i]!=c) i++;
		v.emplace_back(s.substr(start,i-start));
	}
	return v;
}

std::string strip(const std::string& s, char c) {
	int n=s.size();
	int l=0,r=n;
	while(l<n && s[l]==c) l++;
	while(l<r && s[r-1]==c) r--;
	return s.substr(l,r-l);
}

std::string join(const std::vector<std::string> v, std::string c="") {
	std::string o;
	for(int i=0;i<v.size();i++) {
		o+=v[i];
		if(i<v.size()-1) o+=c;
	}
	return o;
}

/* <string> */