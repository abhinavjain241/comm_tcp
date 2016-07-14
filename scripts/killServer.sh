PORT=$(netstat -ap | grep :1024 | grep -oE '[^ ]+$' | awk -F '/' '{print $1}')
kill $PORT