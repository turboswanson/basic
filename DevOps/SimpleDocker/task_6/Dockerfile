FROM nginx

WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY run.sh /home/
RUN chmod +x ./run.sh
CMD ["./run.sh"]