FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY simple_server.c run.sh /home/
RUN chmod +x ./run.sh
RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev
CMD ["./run.sh" ]