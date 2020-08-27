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
## Interface
`LazySegmentTree<M,OM>(int n)` モノイド$$M$$、作用素$$OM$$、大きさ$$n$$で初期化する \
`[i]` $$i$$番目の要素への参照を返す(最初の`build()`の前に事前に初期化するときに使う) \
`build()` セグ木を構築する(すべての要素が単位元で初期化の場合も使う) \
`update(int l,int r,OM a)` $$[l,r)$$の区間に作用素$$a$$を適用する \
`fold(int l,int r)` 区間$$[l,r)$$をfoldした値を返す
### Interface(Monoid)
`I()` 単位元を返す \
`f(M lhs, M rhs)` モノイド間の演算$$f:(M,M)\rightarrow M$$
### Interface(Operator Monoid)
`I()` 単位元を返す \
`g(M m, OM om)` モノイドに作用素を適用するときの演算$$g:(M,OM)\rightarrow M$$ \
`h(OM first, OM second)` 作用素間の演算$$h:(OM,OM)\rightarrow OM$$

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