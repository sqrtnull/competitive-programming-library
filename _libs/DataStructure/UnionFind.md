---
layout: post
title: Union-Find
author: sqrtnull
date: 2020-08-25
category: Data Structures
---

## Info
グラフの連結性を判定できるデータ構造
## Complexity
辺の追加 - $$O(\alpha(n))$$ ($$\alpha はアッカーマン関数の逆関数$$) \
頂点が所属してる集合の名前の取得 - $$O(\alpha(n))$$ \
頂点が所属してる集合の大きさの取得 - $$O(\alpha(n))$$

{% assign path="DataStructure/UnionFind.cpp" %}
## [Code](https://raw.githubusercontent.com/sqrtnull/cp-library/master/{{path}})

{% include read.html code=path %}

## Examples

```cpp
UnionFind uf(10);
uf.unite(1,5);
uf.unite(1,3);
uf.unite(4,3);
uf.unite(5,3);
uf.unite(0,7);
std::cout << (int)(uf.find(1)==uf.find(4)) << '\n'; // 1(true)
std::cout << (int)(uf.find(0)==uf.find(4)) << '\n'; // 0(false)
std::cout << uf.size[uf.find(0)] << '\n'; // 2
uf.unite(5,7);
std::cout << (int)(uf.find(0)==uf.find(4)) << '\n'; // 1(true)
std::cout << uf.size[uf.find(0)] << '\n'; // 6
```