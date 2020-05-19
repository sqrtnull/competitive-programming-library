using lnt = long long;
/* <SWAG> */

template <typename T = lnt>
struct SWAG
{
    int fs,bs;
    std::stack<T> f,b;
    std::vector<T> fa,ba;
    const std::function<T(T,T)> g;
    SWAG(int n, std::function<T(T,T)> g)
        : fs(0),bs(0),fa(n+1,0),ba(n+1,0),g(g) {}
    void push(int a) {
        b.emplace(a);
        ba[bs+1] = g(ba[bs], a);
        bs++;
    }
    void pop() {
        if(!f.empty()) {
            f.pop(); --fs;
        } else {
            while(!b.empty()) {
                f.emplace(b.top()); b.pop();
                fa[fs+1] = g(f.top(), fa[fs]);
                ++fs; --bs;
            }
            f.pop(); --fs;
        }
    }
    T fold_all() {
        return g(fa[fs],ba[bs]);
    }
};

/* <SWAG> */