I first needed to install RabbitMQ:

```
sudo apt-get install rabbitmq-server
```

Then I installed Celery inside my python environment:

```
pip install celery
```

To run a Celery worker server use this command:

```
celery -A tasks worker --loglevel=INFO
```

You can then run a task from python:

```
>>> from tasks import add
>>> add.delay(4, 4)
>>> add.ready()
True
>>> add.get(timeout=1)
8
>>> add.traceback
```

