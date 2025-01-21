# NoMachine

ssh into your machine:

```sh
ssh <username>@<address>
```

If the display is not working properly, you can restart it by:

1. Disabling Ubuntu's display manager:

```sh
sudo systemctl stop display-manager
```

2. Rebooting the NX (NoMachine) server and get a new virtual desktop:

```sh
sudo /etc/NX/nxserver --restart
```
