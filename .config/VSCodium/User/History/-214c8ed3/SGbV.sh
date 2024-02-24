#!/bin/sh

nix-shell -p gcc -run "
    nix-shell -p gcc && cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt 
    "
