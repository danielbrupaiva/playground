
# Docker Dev Image

1. Create a image from Dockerfile
        
        $ docker build -f {DOCKERFILE} --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t {IMAGE}:{TAG} {DOCKERFILE_FOLDER}

2. Run a image with

        $ docker run -it --name {CONTAINER_NAME} --hostname {HOSTNAME} -v {PATH_TO_VOLUME}:{WORKDIR} {IMAGE}:{TAG}
        $ docker run -it --name {CONTAINER_NAME} --hostname {HOSTNAME} -v {VOLUME_NAME}:{WORKDIR} {IMAGE}:{TAG}

3. Create a volume
        
        $ docker volume create {VOLUME_NAME}
        $ docker volume create --name {VOLUME_NAME} --opt type=none --opt device=$(pwd)/{PATH_TO_VOLUME} --opt o=bind

[USAGE EXAMPLE]

    $ docker build -f Dockerfile.debian --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t dev-debian:v0.1 .

    $ docker volume create --name {VOLUME_NAME} --opt type=none --opt device=$(pwd)/{PATH_TO_VOLUME} --opt o=bind

    $ docker run -it --name dev-debian dev-debian:v0.1
    $ docker run -it --hostname dev-debian dev-debian:v0.1
    $ docker run -it --hostname dev-debian -v ./:/home/user/project dev-debian:v0.1
    $ docker run -it --name dev-debian --hostname dev-debian -v .:/home/user/project dev-debian:v0.1
    $ docker run -it --name dev-debian --hostname dev-debian -v $(pwd):/home/user/project/ dev-debian:v0.1



    $ docker build -f ./docker/Dockerfile.crosstool-ng --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t crosstool-ng:v0.1 .
    $ docker volume create --name crosstool-ng --opt type=none --opt device=$(pwd)/crosstool-ng --opt o=bind
    $ docker run -it --name crosstool-ng --hostname crosstool-ng --network=bridge -v crosstool-ng:/home/user/project crosstool-ng:v0.1