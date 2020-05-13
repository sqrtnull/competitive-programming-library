using lnt = long long;
/* <WeightedUnionFind> */

struct WeightedUnionFind
{
    std::vector<int> par,size;
    std::vector<lnt> weight;
    WeightedUnionFind(int n) : par(n),size(n,1),weight(n,0) {
        std::iota(par.begin(),par.end(),0);
    }
    int find(int i) {
        if(par[i]==i) return i;
        int x=find(par[i]);
        weight[i]+=weight[par[i]];
        return par[i]=x;
    }
    int unite(int i, int j, lnt w) {
        if(same(i,j)) {
            if(diff(i,j)!=w) {
                return 1;
            } return 0;
        }
        int x=find(i), y=find(j);
        if(size[x]<size[y]) {
            std::swap(x,y);
            std::swap(i,j);
            w=-w;
        }
        par[y]=x;
        weight[y]=w+weight[i]-weight[j];
        return 0;
    }
    lnt diff(int i, int j) {
        return weight[j]-weight[i];
    }
    bool same(int i, int j) {
        return find(i)==find(j);
    }
};

/* <WeightedUnionFind> */