/* <Int> */

struct uInt
{
    using uint64 = unsigned long long;
    static constexpr int N=2000;
    static constexpr uint64 mask=~(1ll<<63);
    int size=0;
    std::vector<uint64> data; // each unit is 63 bits
    uInt() : data(N,0) {}
    uInt(const uInt& a) {
        data = a.data;
        size = a.size;
    }
    uInt(std::string s) : data(N,0) {
        constexpr uint64 M = 1e18;
        uint64 tmp=0; int i=0;
        for(char c:s) {
            i++; int x=c-'0';
            tmp*=10; tmp+=x;
            if(i>=18) {
                this->mul(M);
                this->add(tmp);
                tmp=0; i=0;
            }
        }
        int m=1; for(int j=0;j<i;j++) { m*=10; }
        this->mul(m); this->add(tmp);
    }
    uInt(uint64 x) : data(N,0) {
        if(x==0) return;
        data[0]=x&mask;
        data[1]=x>>63;
        if(data[1]!=0) size=2;
        else size=1;
    }
    uInt assign(const uInt& rhs) {
        data = rhs.data;
        size = rhs.size;
        return *this;
    }
    uInt add(const uInt& rhs) {
        int M=std::max(size,rhs.size)+1;
        uint64 carry=0; // 0 or 1
        for(int i=0;i<M;i++) {
            data[i]+=rhs.data[i]+carry;
            carry=data[i]>>63;
            data[i]&=mask;
        }
        while(M>0 && data[M-1]==0) M--;
        size=M;
        return *this;
    }
    int compare(const uInt& rhs) const {
        if(size!=rhs.size) return (size<rhs.size)?-1:1;
        for(int i=size-1;i>=0;i--) {
            if(data[i]!=rhs.data[i]) {
                return (data[i]<rhs.data[i])?-1:1;
            }
        }
        return 0;
    }
    uInt sub(const uInt& rhs) {
        if(this->compare(rhs)<0) {
            std::cerr << "Underflow of Int" << '\n';
            exit(1);
        }
        uint64 borrow=0; // 0 or 1
        for(int i=0;i<size;i++) {
            if(data[i]>=rhs.data[i]+borrow) {
                data[i]-=rhs.data[i]+borrow;
                borrow=0;
            } else {
                data[i]+=1ll<<63;
                data[i]-=rhs.data[i]+borrow;
                borrow=1;
            }
        }
        return *this;
    }
    void clear() {
        size=0;
        data.assign(N,0);
    }
    uInt basic_mul(const uInt rhs) {
        uInt tmp;
        for(int i=0;i<rhs.size*63;i++) {
            if(rhs.bit(i)) {
                tmp.add(*this);
            }
            this->bitwiseshift(1);
        }
        return this->assign(tmp);
    }
    uInt mul(const uInt rhs) {
        if(std::max(rhs.size,size)<10) {
            return this->basic_mul(rhs);
        }
        int m=(std::max(rhs.size,size)*63+1)/2;
        uInt x0=*this; uInt x1=*this;
        uInt y0=rhs; uInt y1=rhs;
        x1.bitwiseshift(-m); y1.bitwiseshift(-m);
        uInt mask = uInt(1).bitwiseshift(m).sub(1);
        x0.bitwiseand(mask); y0.bitwiseand(mask);
        uInt z2 = x1; z2.mul(y1);
        uInt z0 = x0; z0.mul(y0);
        uInt z1 = z0; z1.add(z2);
        int xx = x0.compare(x1);
        int yy = y1.compare(y0);
        int sign = xx*yy;
        uInt ox,oy;
        if(xx>0) {
            ox=x0; ox.sub(x1);
        } else if(xx<0) {
            ox=x1; ox.sub(x0);
        }
        if(yy>0) {
            oy=y1; oy.sub(y0);
        } else if(yy<0) {
            oy=y0; oy.sub(y1);
        }
        ox.mul(oy);
        if(sign>0) z1.add(ox);
        else if(sign<0) z1.sub(ox);
        z2.bitwiseshift(2*m);
        z1.bitwiseshift(m);
        z0.add(z1); z0.add(z2);
        return this->assign(z0);
    }
    uInt div(const uInt& rhs) {
        if(rhs.size==0) {
            std::cerr << "Division by zero" << '\n';
            exit(1);
        }
        uInt r,d;
        for(int i=size*63;i>=0;i--) {
            r.bitwiseshift(1);
            d.bitwiseshift(1);
            r.bitwiseor(this->bit(i));
            if(r.compare(rhs)>=0) {
                r.sub(rhs);
                d.bitwiseor(1);
            }
        }
        return this->assign(d);
    }
    uInt mod(const uInt& rhs) const {
        if(rhs.size==0) {
            std::cerr << "Division by zero" << '\n';
            exit(1);
        }
        uInt r,d;
        for(int i=size*63;i>=0;i--) {
            r.bitwiseshift(1);
            d.bitwiseshift(1);
            r.bitwiseor(this->bit(i));
            if(r.compare(rhs)>=0) {
                r.sub(rhs);
                d.bitwiseor(1);
            }
        }
        return r;
    }
    uint64 modull(const uint64 rhs) const {
        if(rhs==0) {
            std::cerr << "Division by zero" << '\n';
            exit(1);
        }
        uint64 r=0;
        for(int i=size*63;i>=0;i--) {
            r<<=1;
            r|=this->bit(i);
            if(r>=rhs) r-=rhs;
        }
        return r;
    }
    uInt pow(uint64 k) {
        uInt A(1), B(*this);
        while(k) {
            if(k&1) A.mul(B);
            B.mul(B); k>>=1;
        }
        return A;
    }
    uInt bitwiseshift(const int k) {
        if(k==0) return *this;
        if(size==0) return *this;
        if(k>0) {
            int blocks = k/63; int bits = k%63;
            for(int i=size;i>=0;i--) {
                data[i+1+blocks]|=data[i]>>(63-bits);
                data[i+blocks]=(data[i]<<bits)&mask;
            }
            for(int i=blocks-1;i>=0;i--) { data[i]=0; }
            size+=blocks+1;
            while(size>0 && data[size-1]==0) size--;
        } else {
            int blocks = -k/63; int bits = -k%63;
            for(int i=0;i<size;i++) {
                data[i]=data[i+blocks]>>bits;
                data[i]|=(data[i+1+blocks]<<(63-bits))&mask;
            }
            for(int i=size-blocks;i<size;i++) { data[i]=0; }
            size-=blocks;
            while(size>0 && data[size-1]==0) size--;
        }
        return *this;
    }
    uInt bitwiseor(const uInt& rhs) {
        for(int i=0;i<rhs.size;i++) {
            data[i]|=rhs.data[i];
        }
        size=std::max(size,rhs.size);
        return *this;
    }
    uInt bitwiseand(const uInt& rhs) {
        for(int i=0;i<size;i++) {
            data[i]&=rhs.data[i];
        }
        size=std::min(size,rhs.size);
        while(size>0 && data[size-1]==0) size--;
        return *this;
    }
    uInt bitwisexor(const uInt& rhs) {
        for(int i=0;i<std::max(size,rhs.size);i++) {
            data[i]^=rhs.data[i];
        }
        size=std::max(size,rhs.size);
        while(size>0 && data[size-1]==0) size--;
        return *this;
    }
    bool bit(const int i) const {
        int blocks = i/63;
        int bits = i%63;
        return data[blocks]>>bits&1;
    }
};
std::istream& operator>>(std::istream&i,uInt&a) {
    unsigned long long t; i>>t; a=uInt(t); return i;
}
std::ostream& operator<<(std::ostream&o,const uInt&a) {
    using uint64 = unsigned long long;
    if(a.size==0) {o<<0; return o; }
    uInt b = a;
    constexpr uint64 MOD = 1e18;
    std::stack<uint64> stk;
    while(b.size) {
        stk.emplace(b.modull(MOD));
        b.div(MOD);
    }
    o<<stk.top(); stk.pop();
    while(!stk.empty()) {
        uint64 x = stk.top(); stk.pop();
        o<<std::setfill('0')<<std::setw(18)<<x;
    }
    return o;
}

/* <Int> */