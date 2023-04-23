from django.urls import path

from .views import IndexView

app_name = 'basic_app'
urlpatterns = [
    path("", IndexView.as_view(), name="index"),
]
