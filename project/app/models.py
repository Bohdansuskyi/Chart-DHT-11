from django.db import models

class Information(models.Model):
    temperature = models.FloatField(max_length=8)
    humidity = models.FloatField(max_length=8)
    time = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return str(self.id)