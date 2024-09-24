from django.urls import path
from . import views
from .views import InformationCreateView

urlpatterns = [
    # templates
    path("", views.index, name="index"),
    path("chart/",views.chart, name="chart"),
    # rest framework
    path("information/",views.InformationListCreate.as_view(), name="information-view-create"),
    path("create/",InformationCreateView.as_view(),name='information-create'),
]