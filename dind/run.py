import docker

client = docker.from_env()
container = client.containers.run("mini", auto_remove=True, detach=False)

container_id = container.decode("utf-8")

print(f"Done running! {container_id}")
