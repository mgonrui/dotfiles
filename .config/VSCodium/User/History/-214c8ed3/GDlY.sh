#!/bin/sh

nix-shell -p gcc --run "
    cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt 
    "
