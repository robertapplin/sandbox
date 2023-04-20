import docker
import os

client = docker.from_env()
container = client.containers.run("autotest", ["1", "5", "100"],
                                  volumes={os.path.join(os.getcwd(), "output"): {"bind": "/app/output/", "mode": "rw"}},
                                  detach=True)

print(container.id)
print(container.logs())
