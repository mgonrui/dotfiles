#!/bin/sh

rm -rf test*

mkdir test{0,2} 
touch test{1,4,5} 
#create a symlink of test0 named test6
ln -s test0 test6
#create a hard link of test5 named test3
ln test5 test3
# make test1 4 bytes long
echo "123" > test1
# make test3 1 byte long
echo "" > test3
# make test4 2 bytes long
echo "1" > test4
#change date   YYYYmmddhhmm
touch -a -m -t 202306012047 test0
touch -a -m -t 202306012146 test1
touch -a -m -t 202306012245 test2
touch -a -m -t 202306012344 test3
touch -a -m -t 202306012343 test4
touch -a -m -t 202306012344 test5
# touch -a -m -t 202306012220 test6