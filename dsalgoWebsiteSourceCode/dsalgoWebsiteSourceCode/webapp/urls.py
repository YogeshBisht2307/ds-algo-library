from django.urls import path
from webapp import views


urlpatterns = [
    path('', views.index, name="Home"),
    path('docs/',views.docs, name="Docs"),
    path('docs/<str:docs_slug>', views.docs_detail, name="DocsDetail")
] 