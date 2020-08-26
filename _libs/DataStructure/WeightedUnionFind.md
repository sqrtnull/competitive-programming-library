---
layout: post
title: Weighted Union-Find
author: sqrtnull
date: 2020-08-26
category: Data Structures
---

## Info
グラフの連結性と同集合内の2頂点のポテンシャルの差を判定できるデータ構造
## Complexity
辺の追加 - $$O(\alpha(n))$$ ($$\alpha はアッカーマン関数の逆関数$$) \
頂点が所属してる集合の名前の取得 - $$O(\alpha(n))$$ \
頂点が所属してる集合の大きさの取得 - $$O(\alpha(n))$$ \
同集合内の2頂点のポテンシャルの差の取得 - $$O(\alpha(n))$$

{% assign path="DataStructure/WeightedUnionFind.cpp" %}
## [Code](https://raw.githubusercontent.com/sqrtnull/cp-library/master/{{path}})

{% include read.html code=path %}

## Examples

```cpp
WeightedUnionFind uf(10);
uf.unite(0,9,1);
uf.unite(1,2,1);
uf.unite(1,3,5);
uf.unite(4,2,-4);
std::cout << uf.diff(3,4) << '\n'; // 0
std::cout << uf.diff(1,4) << '\n'; // 5
```