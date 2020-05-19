using lnt = long long;
/* <SWAG> */

template <typename T = lnt>
struct SWAG
{
    std::stack<T> f,b,fa,ba;
    const std::function<T(T,T)> g;
    SWAG(std::function<T(T,T)> g)
        : g(g) {}
    bool empty() const { return f.empty()&&b.empty() }
    void push(T a) {
        b.emplace(a);
        if(ba.empty()) ba.emplace(a);
        else ba.emplace(g(ba.top(),a));
    }
    void pop() {
        assert(!empty());
        if(f.empty()) {
            while(!b.empty()) {
                f.emplace(b.top()); b.pop(); ba.pop();
                if(fa.empty()) fa.emplace(f.top());
                else fa.emplace(g(f.top(), fa.top()));
            }
        }
        f.pop(); fa.pop();
    }
    T fold_all() const {
        assert(!empty());
        if(fa.empty()) return ba.top();
        if(ba.empty()) return fa.top();
        return g(fa.top(),ba.top());
    }
};

/* <SWAG> */