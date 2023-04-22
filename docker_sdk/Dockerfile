# Use Python 3.10 as the base image
FROM python:3.10

# Set the working directory to /app
WORKDIR /app

# Set the QT_QPA_PLATFORM to be offscreen
ENV QT_QPA_PLATFORM=offscreen

# Update package lists and install required packages
RUN apt-get update && \
    apt-get install -y xvfb && \
    rm -rf /var/lib/apt/lists/*

# Create a new Python virtual environment
RUN python3 -m venv env

# Activate the virtual environment and install the required packages
RUN . env/bin/activate && \
    pip install pyqt-autotest

# Create two directories, one for searching and one for output files
RUN mkdir search && mkdir output

# Copy the .autotest config file into the container
COPY /config/.autotest /root/.autotest

# THIS SHOULD BE A VOLUME OR MOUNT IN THE DOCKER COMPOSE FILE
COPY /config/test.py /app/search/test.py
COPY /config/usercode.py /app/search/usercode.py
COPY /config/run_autotest.sh /app/run_autotest.sh

# This shell script will be executed upon running the container
ENTRYPOINT ["/app/run_autotest.sh"]
