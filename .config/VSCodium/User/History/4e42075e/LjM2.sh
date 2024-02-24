#!/bin/sh

# create file
touch testShell00
# make the file 40 bytes long
echo "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" > testShell00
# change the date to Jun 1 2023 23:42
touch -a -m -t 202306012342 testShell00
#change permissions 
chmod 455 testShell00
# tar file
tar -cf testShell00.tar testShell00
