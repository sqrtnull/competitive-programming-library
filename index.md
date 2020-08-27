---
layout: home
author: sqrtnull
---

<!-- <a>
    <object height="32em" data="{{'assets/sqrtnull_logo.svg'|relative_url}}"></object>
</a> -->
ライブラリ置き場 \
とりあえず日本語で書きます。$$\sqrt{0}$$

{% assign lib = site.libs | group_by: 'category' %} {% for cat in lib %}

<h2> {{ cat.name }} </h2>
  {% assign items = cat.items | sort: 'title' %} {% for item in items %}
 - [**{{item.title}}**]({{ item.url | relative_url }}) {% endfor %}
{% endfor %}