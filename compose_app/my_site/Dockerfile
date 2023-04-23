FROM python:3.10

ENV QT_QPA_PLATFORM=offscreen

RUN apt-get update && \
    apt-get install -y xvfb && \
    rm -rf /var/lib/apt/lists/*

COPY . /app

WORKDIR /app

RUN pip install -r requirements.txt

