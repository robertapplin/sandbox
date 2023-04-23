from django.http import HttpResponse, HttpRequest
from django.shortcuts import redirect, render
from django.views import generic

from .tasks import run_qt


class IndexView(generic.TemplateView):
    """
    A view for the index page.
    """

    template_name = "basic_app/index.html"

    def get(self, request: HttpRequest) -> HttpResponse:
        """Handles a get request."""
        session_key = request.session.session_key
        context = {
            "content": f"This is some content for session key: {session_key}",
        }
        return render(request, self.template_name, context)

    def post(self, request: HttpRequest) -> HttpResponse:
        question_text = request.POST["question"]

        run_qt.delay(question_text)

        return redirect("basic_app:index")
