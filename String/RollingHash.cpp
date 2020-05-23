/* <RollingHash> */

struct RollingHash
{
	static constexpr int MAXLENGTH = 3e5;
	using ulnt = unsigned long long;
	static constexpr ulnt MOD = (1ull<<61)-1;
	static constexpr ulnt MASK30 = (1ull<<30)-1;
	static constexpr ulnt MASK31 = (1ull<<31)-1;
	static constexpr ulnt POSITIVIZER = MOD*((1ull<<3)-1);
	ulnt base;
	std::vector<ulnt> basepow;
	RollingHash() : basepow(MAXLENGTH) {
		std::random_device rd; std::mt19937 gen(rd());
		std::uniform_int_distribution<ulnt> dis(2,MOD-2);
		base = dis(gen); basepow[0]=1;
		for(int i=1;i<MAXLENGTH;i++) {
			basepow[i]=mod(modmul(basepow[i-1],base));
		}
	}
	std::vector<ulnt> hash(const std::string& s) {
		std::vector<ulnt> h(s.size()+1,0);
		for(int i=0;i<s.size();i++) {
			h[i+1]=mod(modmul(base,h[i])+(ulnt)s[i]);
		}
		return h;
	}
	ulnt splice(std::vector<ulnt>& h, int i, int l) {
		return mod(POSITIVIZER+h[i+l]-modmul(h[i],basepow[l]));
	}
	static ulnt modmul(ulnt a, ulnt b) {
		ulnt au,ad,bu,bd,mid,midu,midd;
		ad=a&MASK31; bd=b&MASK31; au=a>>31; bu=b>>31;
		mid=au*bd+ad*bu; midd=mid&MASK30; midu=mid>>30;
		return ad*bd + ((au*bu)<<1) + (midd<<31) + midu;
	}
	static ulnt mod(ulnt a) {
		ulnt x,xu,xd; xu=a>>61; xd=a&MOD; x=xu+xd;
		if(x>=MOD) x-=MOD;
		return x;
	}
};

/* <RollingHash> */
