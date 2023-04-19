import docker

client = docker.from_env()
container = client.containers.run("autotest", ["1", "5", "100"], detach=True)

print(container.id)
print(container.logs())
