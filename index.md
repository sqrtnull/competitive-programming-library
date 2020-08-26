---
layout: home
author: sqrtnull
---

Up and working! $$ \sqrt{0} $$

{% assign lib = site.libs | group_by: 'category' %} {% for cat in lib %}
## {{ cat.name }}
  {% assign items = cat.items | sort: 'title' %}
  {% for item in items %}
 - [{{item.title}}]({{ item.url | relative_url }})
  {% endfor %}
{% endfor %}
