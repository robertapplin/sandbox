from celery import shared_task

from .models import Question


@shared_task()
def save_question(question_text):
    question = Question(question_text=question_text)
    question.save()

