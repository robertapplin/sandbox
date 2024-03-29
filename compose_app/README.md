## Description

In this folder I use Docker compose to link together a basic web app, created using the Django framework, to a Postgres database,
and to a worker service which uses Celery and a Redis message broker. The objective is to create a very basic app which has a
good composition for scalability. It will help me learn how services link to each other.

![alt text](app-structure.png)

## Troubleshooting

### Check if ports are accessible

To check if you can connect to a specific port on a service (A), from another service (B), enter service B:

```sh
docker exec -it <container_id> /bin/bash
```

Install the `netcat` package:

```sh
apt-get update && apt-get install -y netcat
```

Run this command:

```sh
nc -vz <name-of-service-A> <port-on-service-A>
```

### ProgrammingError: relation "django_session" does not exist

This indicates the initial migrate from the database has not been run. Exec into the web app container and run:

```sh
python manage.py migrate
```

You will then need to make the migrations for your own app, and perform the migration:

```sh
python manage.py makemigrations basic_app
python manage.py migrate
```

And finally, you probably haven't created a superuser yet:

```sh
python manage.py createsuperuser
```

