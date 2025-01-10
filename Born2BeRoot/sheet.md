test for graphical interface:  
`echo $DISPLAY` or `echo $DESKTOP_SESSION`  

Add a user `useradd username`  
change its password `sudo passwd username` `NewUser123456789`
* create a new group `sudo groupadd groupname`
add user to group  `sudo usermod -aG groupname username`

hostname
`hostnamectl set-hostname new-hostname`
or change it here:
`sudo nano /etc/hostname`

firewall
```
sudo firewall-cmd --list-service
sudo firewall-cmd --list-port
sudo firewall-cmd --state
sudo firewall-cmd --zone=public --add-port=3306/tcp --permanent # add a new port
sudo firewall-cmd --zone=public --remove-port=8080/tcp --permanent # to delete it
then sudo firewall-cmd --reload 
```

`/etc/login.defs`
PASS_MAX_DAYS   30

`/etc/security/pwquality.conf`
minlen = 10
minclass = 3
maxrepeat = 3
usercheck = 1

`/etc/pam.d/system-auth` handles system authentication
`/etc/pam.d/password-auth` handles password management

`/etc/sudoers

ssh config: `sudo vim /etc/ssh/sshd_config`
