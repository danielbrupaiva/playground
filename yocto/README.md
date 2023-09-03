# Yocto POKY-CROPS

1. Create a image from Dockerfile
        
        $ docker build -f {DOCKERFILE} --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t {IMAGE}:{TAG} {DOCKERFILE_FOLDER}

2. Run a image with

        $ docker run -it --name {CONTAINER_NAME} --hostname {HOSTNAME} -v {PATH_TO_VOLUME}:{WORKDIR} {IMAGE}:{TAG}
        $ docker run -it --name {CONTAINER_NAME} --hostname {HOSTNAME} -v {VOLUME_NAME}:{WORKDIR} {IMAGE}:{TAG}

3. Create a volume
        
        $ docker volume create {VOLUME_NAME}
        $ docker volume create --name {VOLUME_NAME} --opt type=none --opt device=$(pwd)/{PATH_TO_VOLUME} --opt o=bind

[USAGE]

    $ docker build -f Dockerfile.yocto --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t poky-crops:v0.1 .
    
    $ docker volume create --name poky-crops --opt type=none --opt device=$(pwd)/poky-crops --opt o=bind

    $ docker run -it --name poky-crops --hostname poky-crops -v poky-crops:/home/user/project/ poky-crops:v0.1


# Yocto
https://docs.yoctoproject.org/

# With Docker
https://docs.yoctoproject.org/dev-manual/start.html#setting-up-to-use-cross-platforms-crops\

git clone git://git.yoctoproject.org/poky

        $ git clone git://git.yoctoproject.org/poky
        $ cd poky
        $ git checkout -t origin/mickledore
        $ git pull
        $ source oe-init-build-env
        $ touch conf/sanity.conf

Edit conf/local.conf according needs

Example:

> DISTRO ?= "poky"

> MACHINE ?= "raspberrypi4-64"

> BB_SIGNATURE_HANDLER = "OEEquivHash"

> BB_HASHSERVE = "auto"

> BB_HASHSERVE_UPSTREAM = "hashserv.yocto.io:8687"

> SSTATE_MIRRORS ?= "file://.* http://sstate.yoctoproject.org/all/PATH;downloadfilename=PATH"

> PACKAGE_CLASSES ?= "package_deb"

> LICENSE_FLAGS_ACCEPTED = "synaptics-killswitch"

Adding Layers

        $ git clone git://git.yoctoproject.org/meta-raspberrypi
        $ cd meta-raspberrypi
        $ git checkout -t remotes/origin/mickledore
        $ git pull
        $ cd ../build
        $ bitbake-layers add-layer ../meta-raspberrypi/
        $ bitbake core-image-full-cmdline
        $ bitbake core-image-sato


        $ git clone git://git.yoctoproject.org/meta-ti
        $ cd meta-ti
        $ git checkout -t
