
# Docker Dev Image

[Link]https://docs.zephyrproject.org/latest/develop/getting_started/index.html

1. Create a image from Dockerfile
        
        $ docker build -f {DOCKERFILE} --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t {IMAGE}:{TAG} {DOCKERFILE_FOLDER}

2. Run a image with

        $ docker run -it --name {CONTAINER_NAME} --hostname {HOSTNAME} -v {PATH_TO_VOLUME}:{WORKDIR} {IMAGE}:{TAG}
        $ docker run -it --name {CONTAINER_NAME} --hostname {HOSTNAME} -v {VOLUME_NAME}:{WORKDIR} {IMAGE}:{TAG}

3. Create a volume
        
        $ docker volume create {VOLUME_NAME}
        $ docker volume create --name {VOLUME_NAME} --opt type=none --opt device={PATH_TO_VOLUME} --opt o=bind

[USAGE EXAMPLE]

    $ docker build -f Dockerfile.zephyr --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t dev-zephyr:v0.1 .
    
    $ docker volume create --name dev-zephyr --opt type=none --opt device=$(pwd)/dev-zephyr --opt o=bind

    $ docker run -it --name dev-zephyr dev-zephyr:v0.1
    $ docker run -it --hostname dev-zephyr dev-zephyr:v0.1
    $ docker run -it --hostname dev-zephyr -v ./:/home/user/project dev-zephyr:v0.1
    $ docker run -it --name dev-zephyr --hostname dev-zephyr -v .:/home/user/project dev-zephyr:v0.1
    $ docker run -it --name dev-zephyr --hostname dev-zephyr -v dev-zephyr:/home/user/project dev-zephyr:v0.1
