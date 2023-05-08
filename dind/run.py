import docker

client = docker.from_env()
container = client.containers.run("mini", detach=False)

container.wait()

print("Done running!")
