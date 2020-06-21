using lnt = long long;
/* <ceil> */

inline lnt ceildiv(lnt a, lnt b) { return (a+b-1)/b; }

/* <ceil> */
/* <gcd> */

lnt gcd(lnt a, lnt b) {
  if (b==0) return a;
  return gcd(b,a%b);
}

/* <gcd> */
/* <pow> */

lnt ipow(lnt v,lnt k) { lnt r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }

/* <pow> */
/* <prime_factorize> */

void prime_factorize(lnt n, std::map<lnt,lnt>& prime_factors) {
	for(lnt i=2;i*i<=n;i++) {
		while(n%i==0) {
			prime_factors[i]++;
			n/=i;
		}
	}
	if(n!=1) prime_factors[n]++;
}

/* <prime_factorize> */
