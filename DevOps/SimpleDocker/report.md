# Simple Docker

## Part 1. Ready-made docker

### Take the official docker image from **nginx** and download it using `docker pull`.
![pull nginx](./img/1_1.png)

### Check for the docker image with `docker images`.
![images](./img/1_2.png)

### Run docker image with `docker run -d [image_id|repository]`.
### Check that the image is running with `docker ps`.
![run and ps](./img/1_3_4.png)

#### -d starts the container without occupying your terminal window(detached mode)

### View container information with `docker inspect [container_id|container_name]`.
![](./img/1_5_1.png)

### From the command output define and write in the report the container size, list of mapped ports and container ip.
![size](./img/1_5_2.png)
![ports](./img/1_5_3.png)
![ip](./img/1_5_4.png)

### Stop docker image with `docker stop [container_id|container_name]`.
### Check that the image has stopped with `docker ps`.
![stop and ps](./img/1_6.png)

### Run docker with ports 80 and 443 in container, mapped to the same ports on the local machine, with *run* command.
![map ports](./img/1_7.png)

### Check that the **nginx** start page is available in the browser at *localhost:80*.
![localhost](./img/1_8.png)

### Restart docker container with `docker restart [container_id|container_name]`.
### Check in any way that the container is running.

![restart](./img/1_9.png)

## Part 2. Operations with container


### Read the *nginx.conf* configuration file inside the docker container with the *exec* command.

![](./img/2_1.png)

### Create a *nginx.conf* file on a local machine.
### Configure it on the */status* path to return the **nginx** server status page.

![](./img/2_2_3.png)

`location` directive is used to define how Nginx should handle request

### Copy the created *nginx.conf* file inside the docker image using the `docker cp` command.
### Restart **nginx** inside the docker image with *exec*.

![](./img/2_4_5.png)

### Check that *localhost:80/status* returns the **nginx** server status page.

![](./img/2_6.png)

### Export the container to a *container.tar* file with the *export* command.
### Stop the container.

![](./img/2_7.png)

### Delete the image with `docker rmi [image_id|repository]`without removing the container first.
### Delete stopped container.

![](./img/2_8.png)

### Import the container back using the *import*command.
### Run the imported container.

![](./img/2_9.png)

### Check that *localhost:80/status* returns the **nginx** server status page.

![](./img/2_10.png)

## Part 3. Mini web server

### Write a mini server in **C** and **FastCgi** that will return a simple page saying `Hello World!`.

![](./img/3_1.png)

### Write your own *nginx.conf* that will proxy all requests from port 81 to *127.0.0.1:8080*.

![](./img/3_2.png)

### Create a container and put `simple_server.c` and `nginx.conf` to specific directories

![](./img/3_3.png)

### Installing dependencies for the server launching `gcc`, `spawn-fcgi`, `libfcgi-dev`

![](./img/3_4.png)

### Run the written mini server via `spawn-fcgi` on port 8080.

![](./img/3_5.png)

### Check that browser on *localhost:81* returns the page you wrote.

![](./img/3_6.png)

## Part 4. Your own docker

### Write your own docker image that:
#### 1) builds mini server sources on FastCgi from [Part 3];
#### 2) runs it on port 8080;
#### 3) copies inside the image written *./nginx/nginx.conf*;
#### 4) runs **nginx**.

![](./img/4_1.png)

![](./img/4_2.png)


### Build the written docker image with `docker build`, specifying the name.

![](./img/4_3.png)


### Check with `docker images` that everything is built correctly.

![](./img/4_4.png)

### Run the built docker image by mapping port 81 to 80 on the local machine and mapping the *./nginx* folder inside the container to the address where the **nginx** configuration files are located.

### Check that the page of the written mini server is available on localhost:80.

![](./img/4_5.png)

### Add proxying of */status* page in *./nginx/nginx.conf* to return the **nginx** server status.

![](./img/4_6.png)

### Restart docker image.

### Check that *localhost:80/status* now returns a page with **nginx** status.

![](./img/4_7.png)


## Part 5. **Dockle**

### Check the image from the previous task with `dockle [image_id|repository]`.

![](./img/5_1.png)

### Fix the image so that there are `no errors or warnings` when checking with **dockle**.

![](./img/5_2.png)

![](./img/5_3.png)

![](./img/5_4.png)

## Part 6. Basic **Docker Compose**

### Write a *docker-compose.yml* file, using which:
### 1) Start the docker container from [Part 5]
### 2) Start the docker container with **nginx** which will proxy all requests from port 8080 to port 81 of the first container.

### Map port 8080 of the second container to port 80 of the local machine.

![](./img/6_1.png)

![](./img/6_2.png)

![](./img/6_2_1.png)

run.sh contains only `nginx -g "daemon off;"`

### Build and run the project with the `docker-compose build` and `docker-compose up` commands.

![](./img/6_3.png)

![](./img/6_4.png)

### Check that the browser returns the page you wrote on *localhost:80* as before.

![](./img/6_5.png)

![](./img/6_6.png)





























