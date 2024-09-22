from django.urls import path
from . import views
from .views import InformationCreateView

urlpatterns = [
    path("", views.index, name="index"),
    path("chart/",views.chart, name="chart"),
    path("information/",views.InformationListCreate.as_view(), name="information-view-create"),
    path("create/",InformationCreateView.as_view(),name='information-create'),
]