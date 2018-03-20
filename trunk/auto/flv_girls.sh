#!/bin/sh
#for((;;)); do
       ../objs/ffmpeg/bin/ffmpeg -re -i ../doc/test.flv \
                                -vcodec copy -acodec copy \
                                -f flv -y rtmp://127.0.0.1:1935/live/girls; \
           sleep 1;
 #  done