from django.shortcuts import render

def index(request):
    return render(request, "app/index.html")

def chart(request):
    return render(request, "app/chart.html")