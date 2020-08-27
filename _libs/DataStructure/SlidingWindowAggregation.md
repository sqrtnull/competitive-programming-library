---
layout: post
title: Sliding Window Aggregation
author: sqrtnull
date: 2020-08-26
category: Data Structures
---

## Info
末尾追加と先頭消去の操作が可能な半群の列のfoldができるデータ構造
## Complexity
末尾追加 - $$O(1)\ \text{amortized}$$ \
先頭消去 - $$O(1)\ \text{amortized}$$ \
全体fold - $$O(1)$$
## Interface
`SWAG<T>(func g)` 要素の型$$T$$と関数$$g:(T,T)\rightarrow T$$で初期化する \
`push(T a)` 末尾に$$a$$を追加する \
`pop()` 先頭から要素を一つ消去する \
`fold_all()` 全体をfoldした値を返す

{% assign path="DataStructure/SlidingWindowAggregation.cpp" %}
## [Code](https://raw.githubusercontent.com/sqrtnull/cp-library/master/{{path}})

{% include read.html code=path %}

## Examples

```cpp
SWAG<int> sw([](int a, int b){return std::gcd(a,b)});
sw.push(2);
sw.push(4);
sw.push(8);
sw.push(16);
std::cout << sw.fold_all() << '\n'; // 2
sw.pop();
std::cout << sw.fold_all() << '\n'; // 4
sw.push(6);
std::cout << sw.fold_all() << '\n'; // 2
```