#!/bin/bash

python manage.py makemigrations basic_app
python manage.py migrate

python manage.py createsuperuser
