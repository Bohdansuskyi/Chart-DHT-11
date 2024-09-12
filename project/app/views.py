from django.shortcuts import render

def index(request):
    return render(request, "app/index.html")

def records(request):
    return render(request, "app/records.html")