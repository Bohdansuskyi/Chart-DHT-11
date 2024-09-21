from django.urls import path
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("chart/",views.chart, name="chart"),
    path("information/",views.InformationListCreate.as_view(), name="information-view-create"),
    path("information/<int:pk>/", views.InformationRetrieveUpdateDestory.as_view(),name ="update"),
]