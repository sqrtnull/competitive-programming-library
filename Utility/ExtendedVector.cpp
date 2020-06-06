/* <ExtendedVector> */

// extends vector to negative indices
template <typename T = lnt>
struct Evec
{
	int n;
	std::vector<T> data;
	Evec(int n, T init) : n(n),data(2*n+1, init) {}
	T& operator[](const int& i) {
		return data[i+n];
	}
};

/* <ExtendedVector> */
