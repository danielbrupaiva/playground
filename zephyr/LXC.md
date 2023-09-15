# https://linuxcontainers.org/lxc/getting-started/

# https://www.tecmint.com/install-lxc-ubuntu-debian/

$ sudo apt install lxc
$ sudo apt install snapd
$ snap install lxd
$ usermod -aG lxd [user-name]

$ sudo lxd init
$ sudo lxc list
$ sudo lxc profile show default
$ sudo lxc storage list
$ sudo lxc storage show [disk name]
$ sudo lxc network show [network name]
$ sudo lxc network list
$ sudo lxc image list images:
$ sudo lxc image list images: | grep -i ubuntu
$ sudo lxc launch images:[distro]/[version]/[arch] [container-name]
$ sudo lxc exec [container-name] bash
$ sudo lxc info [container-name]
$ sudo lxc stop container-name
$ sudo lxc list | grep -i STOPPED
$ sudo lxc list | grep -i RUNNING

$ sudo lxc start container1 container2
$ sudo lxc restart container-name
$ sudo lxc stop container-name
$ sudo lxc delete container-name

Firewall
$ sudo ufw allow in on lxdbr0 comment 'lxdbr0 for LXD'
$ sudo ufw route allow in on lxdbr0 comment 'lxdbr0 for LXD'
$ sudo ufw route allow out on lxdbr0 comment 'lxdbr0 for LXD'



