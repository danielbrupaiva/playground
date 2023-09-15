# Playground

This repository contains general setup and tools for software and hardware development

* Host PC setup
* Linux references
* Git references
* Docker reference
* Docker template

## Host PC setup
General purpose setup using linux OS - Debian12:bookworm


1. Installation as usual and according to user preferences [Link] https://www.debian.org/index.pt.html
2. Configurations after instalation [Link] https://www.learnlinux.tv/debian-12-12/
 
    2.1 - Add user to sudo group 
    [Link] https://phoenixnap.com/kb/how-to-create-sudo-user-on-ubuntu

        $ usermod -aG sudo [user-name] 
        $ su -
        $ echo "[user-name]  ALL=(ALL) ALL" >> /etc/sudoers.d/[user-name]
        
        (not recommended)
        $ echo "[user-name]  ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers.d/[user-name]


        Change the mode of each FILE to MODE 
        $ chmod ugo+x [file_name]

        Configure wi-fi via command line
        [Link] https://wiki.archlinux.org/title/Network_configuration/Wireless)

        wpa_cli [references]
        $ sudo wpa_cli

        > scan
        > scan_results
        > add_network
        > set_network 0 ssid "MYSSID"
        > set_network 0 psk "passphrase"
        > enable_network 0
        > save_config
        > quit

        $ vi /etc/wpa_supplicant/wpa_supplicant-wlan0.conf

        First packages
        $ sudo apt install build-essential cmake ninja-build automake autotools-dev autoconf gawk debianutils git wget rsync python-is-python3 unzip
        
    2.2 - Install FlatPak 
    
    [Link] https://flathub.org/

    [Link] https://flatpak.org/setup/Debian

        $ apt install flatpak
        $ apt install gnome-software-plugin-flatpak
        $ flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
        $ sudo reboot now

    2.3 - Manage GUI Desktop Enviroment [optional]

        $ sudo tasksel

    2.4 - NVIDIA driver 
        
        $ sudo apt install nvidia-driver

    2.5 - Multimidia packages
      
        $ sudo apt install libavcodec-extra vlc

    2.6 - Back port repositories [optional]

        $ sudo touch /etc/apt/sources.list.d/backports.list
        $ sudo echo "deb http://deb.debian.org/debian bookworm-backports main" >> /etc/apt/sources.list.d/backports.list
        $ sudo apt install -t bookworm-backports [package-name]

    2.7 - Synaptic package manager
        
        $ sudo apt install synaptic

    2.8 - Update Firefox-esr [Link] https://flathub.org/apps/org.mozilla.firefox
      
      * Remove firefox-esr (system default)
          
            $ sudo apt remove firefox-esr
      
      * Instal current version of firefox version via Flatpak
        
            $ flatpak install flathub org.mozilla.firefox

    2.9 - Update LibreOffice [Link] https://flathub.org/apps/org.libreoffice.LibreOffice

      * Remove libreoffice suite (system default)
      
            $ sudo apt remove libreoffice*
      
      * Install LibreOffice suite via Flatpak
            
            $ flatpak install flathub org.libreoffice.LibreOffice

    2.10 - VSCode
    
      Install via flatpak  
      
        $ flatpak install flathub com.visualstudio.code

      or direct from microsoft

      [Link] https://code.visualstudio.com/download
        
        $ sudo apt install ./code_1.81.1-1691620686_amd64.deb
    
    * Pluggins

      [TODO]

    * Settings

      [TODO]

    2.11 - Install Gnome Boxes - VM [Link] https://flathub.org/apps/org.gnome.Boxes
    
        $ flatpak install flathub org.gnome.Boxes

    2.11 - Insync [Link] https://cdn.insynchq.com/builds/linux/insync_3.8.6.50504-bookworm_amd64.deb
        
        $ sudo apt install ./insync_3.8.6.50504-bookworm_amd64.deb
    
    2.12 - Install Docker [Link] https://docs.docker.com/desktop/install/debian/

        $ sudo apt-get update
        $ sudo apt-get install ca-certificates curl gnupg

        $ sudo install -m 0755 -d /etc/apt/keyrings
        $ curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
        $ sudo chmod a+r /etc/apt/keyrings/docker.gpg

        $ echo \ 
          "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian \
          "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
          sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

        $ sudo apt-get update
        $ sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
        $ sudo docker run hello-world

    Docker desktop
        
        $ sudo apt install ./docker-desktop-4.22.0-amd64.deb

    [Link] https://docs.docker.com/desktop/get-started/#credentials-management-for-linux-users

        $ gpg --generate-key
        $ pass init [PUB ID]
    

      2.13 - Install Qt Creator

        $ sudo chmod +x qt-unified-linux-x64-4.6.0-online.run
        $ ./qt-unified-linux-x64-4.6.0-online.run


      2.14 - Install LXC 
      [Link] https://linuxcontainers.org/lxc/getting-started/
      [Link] https://wiki.archlinux.org/title/LXD
      [Link] https://snapcraft.io/docs/service-management
      [Link] https://documentation.ubuntu.com/lxd/en/latest/tutorial/first_steps/
      [Link] https://www.cyberciti.biz/faq/install-lxd-on-ubuntu-22-04-lts-using-apt-snap/
      [Link] https://documentation.ubuntu.com/lxd/en/latest/howto/images_manage/

      $ sudo apt install lxc
      $ sudo apt install snapd
      $ snap install lxd
      $ usermod -aG lxd [user-name]
      $ sudo lxd init
      $ sudo lxc launch images:{de'bian}/{12} {container_name}





      lxc exec mycontainer -- sudo --user daniel --login



## Linux references 

* Install DEB packages

      $ sudo dpkg -i [package-name].deb
      $ sudo apt install ./[package-name].deb
      Add user to dialout group - use to handle serial ports
      $ sudo adduser $USER dialout
      Add /new/directory to PATH
      $ export PATH=$PATH:/place/with/the/file
      $ export PATH="/new/directory:$PATH"
      $ source ~/.bashrc
      

## Git references

1. Global configuration

        $ git config --global user.name "Full username"
        $ git config --global user.email user@email.com
        $ git config --global core.editor "code --wait"
        $ git config --global --edit
        $ git config --global core.autocrlf
        $ git config --global diff.tool vscode
        $ git config --global difftool.vscode.cmd "code --wait --diff $LOCAL $REMOTE"
        $ git config --global --add merge.ff false
        $ git config --global merge.tool p4merge
        $ git config --global mergetool.p4merge.path "full path"
        $ ls /usr/share/doc/git/contrib/credential/
        $ git config --global credential.helper cache
        $ git config --global credential.helper osxkeychain
        
