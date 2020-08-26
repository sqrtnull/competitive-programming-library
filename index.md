---
layout: home
author: sqrtnull
---

Up and working! $$ \sqrt{0} $$

<!-- <object height="32em" data="{{'assets/sqrtnull_logo.svg'|relative_url}}"></object> -->

{% assign lib = site.libs | group_by: 'category' %} {% for cat in lib %}
## {{ cat.name }}
  {% assign items = cat.items | sort: 'title' %}
  {% for item in items %}
 - [{{item.title}}]({{ item.url | relative_url }})
  {% endfor %}
{% endfor %}
