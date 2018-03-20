#!/bin/sh
#for((;;)); do
       ../objs/ffmpeg/bin/ffmpeg -re -i ../doc/source.200kbps.768x320.flv \
                                -vcodec copy -acodec copy \
                                -f flv -y rtmp://127.0.0.1:1935/live/avatar; \
           sleep 1;
 #  done