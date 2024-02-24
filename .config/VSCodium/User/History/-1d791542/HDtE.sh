#!/bin/sh
mkdir test{0,2} 
touch test{1,4,5} 
#create a symlink of test0 named test6
ln -s test0 test6
#create a hard link of test5 named test3
ln test5 test3
