from django.db import models

# models for creating database
class Information(models.Model):
    temperature = models.FloatField()
    humidity = models.FloatField()
    time = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return str(self.id)