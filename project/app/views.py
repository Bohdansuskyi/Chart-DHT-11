from django.shortcuts import render
from .models import Information

def index(request):
    return render(request, "app/index.html")

def chart(request):
    data = Information.objects.all()

    # get data from model
    data_time = [str(entry.time) for entry in data]
    temperature_data = [entry.temperature for entry in data]
    humidity_data = [entry.humidity for entry in data]

    return render(request, "app/chart.html", {
        'data_time': data_time,
        'temperature_data': temperature_data,
        'humidity_data':humidity_data
    })