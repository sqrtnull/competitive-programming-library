/* <UnionFind> */

struct UnionFind
{
  int n;
  std::vector<int> par,size;
  UnionFind(int sz) : n(sz), par(sz,0), size(sz,1) {
    std::iota(par.begin(),par.end(),0);
  }
  int find(int x) {
    if(par[x]==x) return x;
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x=find(x);y=find(y);
    if(x==y) return;
    if(size[x]<size[y]) std::swap(x,y);
    size[x]+=size[y];
    par[y]=x;
  }
};

/* <UnionFind> */