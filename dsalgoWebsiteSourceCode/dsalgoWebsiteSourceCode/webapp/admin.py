from django.contrib import admin
from webapp.models import Docs, DocsCategory, Hero, Author, Component, ComponentItem, SampleCode
# Register your models here.
class ComponentItemConfiguration(admin.TabularInline):
    model = ComponentItem

class ComponentConfiguration(admin.ModelAdmin):
    inlines = [ComponentItemConfiguration]

class SampleCodeCongiguration(admin.ModelAdmin):
    class Media:
        js = ('webapp/js/tinymce.js',)
        
class DocsConfiguration(admin.ModelAdmin):
    class Media:
        js = ('webapp/js/tinymce.js',)


admin.site.register(Docs,DocsConfiguration)
admin.site.register(DocsCategory)
admin.site.register(Hero)
admin.site.register(Author)
admin.site.register(Component, ComponentConfiguration)
admin.site.register(SampleCode,SampleCodeCongiguration)