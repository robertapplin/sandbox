from celery import Celery
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication
from PyQt5.QtTest import QTest
from usercode import UserWidget

app = Celery("tasks")
app.config_from_object("celeryconfig")


@app.task
def add(x, y):
    return x + y


@app.task
def run_qt():
    app = QApplication(["app_name"])
    widget = UserWidget()
    widget.show()
    QTest.mouseClick(widget.success_button, Qt.LeftButton)
    QTest.qWait(5000)  # Wait 5 seconds
    widget.close()

