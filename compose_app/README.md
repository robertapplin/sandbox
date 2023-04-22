## Description

In this folder I use Docker compose to link together a basic web app, created using the Django framework, to a Postgres database,
and to a worker service which uses Celery and a Redis message broker. The objective is to create a very basic app which has a
good composition for scalability. It will help me learn how services link to each other.

## Troubleshooting

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

