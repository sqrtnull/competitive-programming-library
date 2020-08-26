---
layout: post
title: Segment Tree
author: sqrtnull
date: 2020-08-25
category: Data Structures
---

## Info
Monoidの区間fold、一点更新が$$O(\log{n})$$でできるデータ構造
## Complexity
構築 - $$O(n)$$ \
1点更新 - $$O(\log{n})$$ \
1点取得 - $$O(1)$$ \
区間fold - $$O(\log{n})$$

{% assign path="DataStructure/SegmentTree.cpp" %}
## [Code](https://raw.githubusercontent.com/sqrtnull/cp-library/master/{{path}})

{% include read.html code=path %}

## Examples

```cpp
using M=RangeMax<int>;
SegmentTree<M> seg(10);

for(int i=0;i<10;i++) seg[i]=i;
seg.build();

std::cout << seg.fold(2,5) << '\n'; // 4

seg.update(2,seg[2]*100);

std::cout << seg.fold(2,5) << '\n'; // 200
```