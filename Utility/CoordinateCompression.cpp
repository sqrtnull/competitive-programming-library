using lnt = long long;
/* <CoordinateCompression> */

template <typename T = lnt>
struct CoordinateCompression
{
	// add with .r.emplace_back(), T->int with [], int-> T with .r[]
	std::vector<T> r;
	CoordinateCompression() {}
	void build(bool sorted=false) {
		if(!sorted) std::sort(r.begin(),r.end());
		r.erase(std::unique(r.begin(),r.end()),r.end());
	}
	int operator[](const T& k) const {
		return (int)(std::lower_bound(r.begin(),r.end(),k)-r.begin());
	}
};

/* <CoordinateCompression> */
