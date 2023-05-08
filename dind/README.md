This directory is a test for trying to run a docker container using the python docker SDK from within a docker container.

Run the following:

```sh
docker run -it parent /bin/bash
```

and then try to run the docker SDK:

```sh
python run.py
```
