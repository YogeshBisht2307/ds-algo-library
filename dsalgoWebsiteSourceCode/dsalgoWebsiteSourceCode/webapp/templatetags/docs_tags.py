from django import template
from webapp.models import Component, ComponentItem,DocsCategory,Docs

register = template.Library()


@register.simple_tag
def components_items(comp):
    compItem =  ComponentItem.objects.filter(component = comp);
    print(compItem)
    return compItem


@register.simple_tag
def docs_category(components):
    components_categories = DocsCategory.objects.filter(component =  components)

    return components_categories


@register.simple_tag
def docs_content(cc):
    docs = Docs.objects.filter(category = cc)
    return docs


@register.simple_tag
def topics_content():
    topics =DocsCategory.objects.all();
    return topics