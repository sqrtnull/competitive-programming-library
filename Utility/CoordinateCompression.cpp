using lnt = long long;
/* <CoordinateCompression> */

template <typename T = lnt>
struct CoordinateCompression
{
	std::vector<T> data;
	CoordinateCompression(const std::vector<T>& coords, bool sorted=false) : data(coords) {
		if(!sorted) std::sort(data.begin(),data.end());
		data.erase(std::unique(data.begin(),data.end()),data.end());
	}
	int enc(T x) const {
		return (int)(std::lower_bound(data.begin(),data.end(),x)-data.begin());
	}
	T dec(int x) const {
		return data[x];
	}
};

/* <CoordinateCompression> */
