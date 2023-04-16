from celery import Celery

app = Celery("tasks")
app.config_from_object("celeryconfig")

@app.task(ignore_result=False)
def add(x, y):
    return x + y

