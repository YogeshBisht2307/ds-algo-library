from django.db import models
from django.core.validators import FileExtensionValidator

# Create your models here.
class Hero(models.Model):
    heading = models.CharField(max_length = 50)
    paragraph = models.TextField()
    docs_file = models.FileField(upload_to="upload/files/",default="",validators=[FileExtensionValidator(['zip', 'rar'])])

    def __str__(self):
        return self.heading
 
class Component(models.Model):
    heading = models.CharField(max_length = 50)
    slug = models.CharField(max_length = 50, default ="")
    image = models.FileField(upload_to="upload/",default="",validators=[FileExtensionValidator(['png','jpg','jpeg', 'svg'])])
    description = models.CharField(max_length = 200)

    def __str__(self):
        return self.heading


class ComponentItem(models.Model):
    title = models.CharField(max_length = 100)
    component = models.ForeignKey(Component, on_delete=models.CASCADE)

    def __str__(self):
        return self.title


class SampleCode(models.Model):
    title = models.CharField(max_length = 200)
    code = models.TextField();

    def __str__(self):
        return self.title


class Author(models.Model):
    name = models.CharField(max_length = 50)
    designation = models.CharField(max_length = 50)
    description = models.CharField(max_length = 150)
    image = models.ImageField(upload_to="upload/",default="")

    def __str__(self):
        return self.name


class DocsCategory(models.Model):
    title = models.CharField(max_length= 50)
    slug = models.CharField(max_length = 100)
    description = models.CharField(max_length=200)
    component = models.ForeignKey(Component, on_delete=models.CASCADE,default ="")

    def __str__(self):
        return self.title


class Docs(models.Model):
    title = models.CharField(max_length = 100)
    permalink = models.CharField(max_length = 200)
    content = models.TextField()
    description = models.CharField(max_length = 300)
    date = models.DateTimeField(auto_now_add=True)
    author = models.ForeignKey(Author ,on_delete=models.CASCADE)
    category = models.ForeignKey(DocsCategory , on_delete=models.CASCADE)


    def __str__(self):
        return self.title
