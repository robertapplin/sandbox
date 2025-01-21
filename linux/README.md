# Linux

To mount a drive on Ubuntu, follow the steps in https://gist.github.com/DTasev/ee3de5a6de93d25e5f2d11b6ef3cc08e

In ``/etc/fstab``, you want to add:

```
//<address>/users-m$/mhb52947 /mnt/mdrive cifs credentials=/archive.creds,iocharset=utf8,sec=ntlmssp,uid=rob,gid=rob,file_mode=0700,dir_mode=0700 0 0
```
