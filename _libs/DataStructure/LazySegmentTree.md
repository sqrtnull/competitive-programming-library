---
layout: post
title: Lazy Segment Tree
author: sqrtnull
date: 2020-08-25
category: Data Structures
---

## Info
Monoidの区間fold、区間更新が$$O(\log{n})$$でできるデータ構造
## Complexity
構築 - $$O(n)$$ \
区間更新 - $$O(\log{n})$$ \
区間fold - $$O(\log{n})$$

{% assign path="DataStructure/LazySegmentTree.cpp" %}
## [Code](https://raw.githubusercontent.com/sqrtnull/cp-library/master/{{path}})

{% include read.html code=path %}

## Examples

```cpp
using T=RangeAffineRangeSum<int>;
LazySegmentTree<T::M,T::OM> seg(10);

for(int i=0;i<10;i++) seg[i]=i;
seg.build();

std::cout << seg.fold(2,5) << '\n'; // 9

seg.update(2,4,T::OM(100,-50)); // x=x*100+(-50)

std::cout << seg.fold(2,5) << '\n'; // 404
```