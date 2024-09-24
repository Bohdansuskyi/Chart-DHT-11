from rest_framework import serializers
from .models import Information

# convert  data from json to float
class InformationSerializer(serializers.ModelSerializer):
    class Meta:
        model = Information
        fields = ["temperature","humidity"]