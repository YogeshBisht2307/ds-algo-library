from django.shortcuts import render
from webapp.models import Docs,DocsCategory,Hero,Author,Component,SampleCode

# Create your views here.
def index(request):
    hero = Hero.objects.first();
    components = Component.objects.all();
    sample_code = SampleCode.objects.all();
    print(hero)
    context = {
        'hero':hero,
        'components':components,
        'samplecodes':sample_code,
    }
    return render(request, template_name="webapp/index.html", context= context)

def docs(request):
    components = Component.objects.all();
    component = Component.objects.first()
    context = {
        'components':components,
        'component':component,
    }
    return render(request, template_name='webapp/docs.html', context=context)

def docs_detail(request, docs_slug):
    components = Component.objects.all();
    component = Component.objects.filter(slug = docs_slug).first()
    print("component", component)
    print("components",components)
    docs_category = DocsCategory.objects.filter(slug = docs_slug).first()
    print(docs_category)
    allDocs = Docs.objects.filter(category = docs_category)
    print(allDocs)
    context = {
        'allDocs':allDocs,
        'components':components,
        'component':component,
    }
    return render(request, template_name='webapp/docs.html',context = context)