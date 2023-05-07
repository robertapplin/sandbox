from celery import Celery
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication
from PyQt5.QtTest import QTest
from usercode import UserWidget

app = Celery("tasks")
app.config_from_object("celeryconfig")


class SpecialTask(Task):

    def on_success(self, retval, task_id, args, kwargs):
        # args are the original args provided to the task
        # kwargs are the original kwargs provided to the task
        # retval is the task return value
        pass

    def on_failure(self, exc, task_id, args, kwargs, einfo):
        # Do a failure
        print(self.name)  # Is the name of the task


@app.task
def add(x, y):
    return x + y


@app.task(base=SpecialTask, name="Run a Qt Widget")
def run_qt():
    app = QApplication(["app_name"])
    widget = UserWidget()
    widget.show()
    QTest.mouseClick(widget.success_button, Qt.LeftButton)
    QTest.qWait(5000)  # Wait 5 seconds
    widget.close()

