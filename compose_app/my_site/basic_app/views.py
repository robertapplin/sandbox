from django.http import HttpResponse, HttpRequest
from django.shortcuts import redirect, render
from django.views import generic

from .models import Question


class IndexView(generic.TemplateView):
    """
    A view for the index page.
    """

    template_name = "basic_app/index.html"

    def get(self, request: HttpRequest) -> HttpResponse:
        """Handles a get request."""
        context = {
            "content": "This is some content",
        }
        return render(request, self.template_name, context)

    def post(self, request: HttpRequest) -> HttpResponse:
        question_text = request.POST["question"]

        question = Question(question_text=question_text)
        question.save()

        return redirect("basic_app:index")
