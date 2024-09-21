# for templates
from django.shortcuts import render
from .models import Information

#django rest_framework
from rest_framework import generics, status
from rest_framework.response import Response
from .serializers import InformationSerializer
from rest_framework.views import APIView

# views for templates
def index(request):

    data = Information.objects.last()

    if data:
        data_time = str(data.time)
        temperature_data = data.temperature
        humidity_data = data.humidity
    else:
        data_time = None
        temperature_data = None
        humidity_data = None
        
    return render(request, "app/index.html",{
        'data_time': data_time,
        'temperature_data': temperature_data,
        'humidity_data':humidity_data
    })

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

# API POST
class InformationListCreate(generics.ListCreateAPIView):
    queryset = Information.objects.all()
    serializer_class = InformationSerializer

    def delete():
        Information.objects.all().delete()
        return Response(status.HTTP_204_NO_CONTENT)

class InformationRetrieveUpdateDestory(generics.RetrieveUpdateDestroyAPIView):
    queryset = Information.objects.all()
    serializer_class = InformationSerializer
    lookup_field = "pk"

    