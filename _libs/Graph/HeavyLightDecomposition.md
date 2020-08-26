---
layout: post
title: Heavy Light Decomposition
author: sqrtnull
date: 2020-08-25
category: Graph
---

## Info
根付き木をうまく分解することでセグ木などのデータ構造と一緒に部分木クエリやパスに対するクエリが処理できる。ついでにLCA(Lowest Common Ancestor)を$$O(\log{n})$$で求められる。
## Complexity
構築 - $$O(n)$$ \
部分木に対応する区間取得 - $$O(1)$$ \
2頂点間のパスに対応する区間取得 - $$O(\log{n})$$ で $$O(\log{n})$$個の独立な区間を得る \
2頂点のLCA - $$O(\log{n})$$

{% assign path="Graph/HeavyLightDecomposition.cpp" %}
## [Code](https://raw.githubusercontent.com/sqrtnull/cp-library/master/{{path}})

{% include read.html code=path %}

## Examples

```cpp
int n=10;
std::vector<std::vector<int> > g(n);
rep(i,n-1) {
    g[i].emplace_back(i+1);
    g[i+1].emplace_back(i);
}
HLD hld(n,g,2);
auto ivs=hld.get_path(0,9);
for(auto e:ivs) std::cout << e.l << ' ' << e.r << EL; // 8 10, 0 8
auto iv=hld.get_subtree(0);
std::cout << iv.l << ' ' << iv.r << EL; // 9 10
iv=hld.get_subtree(2);
std::cout << iv.l << ' ' << iv.r << EL; // 0 10
```