#!/bin/bash

gcc simple_server.c -o simple_server -lfcgi
spawn-fcgi -p 8080 ./simple_server
nginx -g "daemon off;" #start nginx in the foreground


