import os

from celery import Celery
from django.conf import settings

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "my_site.settings")

app = Celery("basic_app")
app.config_from_object("django.conf:settings", namespace="CELERY")
app.autodiscover_tasks()

