from celery import shared_task

from .models import Question

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication
from PyQt5.QtTest import QTest
from .userwidget import UserWidget


@shared_task()
def save_question(question_text):
    question = Question(question_text=question_text)
    question.save()


@shared_task()
def run_qt(question_text):
    app = QApplication(["app_name"])
    widget = UserWidget()
    widget.show()
    QTest.mouseClick(widget.success_button, Qt.LeftButton)
    QTest.qWait(5000)  # Wait 5 seconds
    widget.close()

    question = Question(question_text=question_text)
    question.save()

