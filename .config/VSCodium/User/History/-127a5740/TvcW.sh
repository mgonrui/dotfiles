#!/bin/sh

rm -rf /home/mgr/.config/hosts.nix
touch /home/mgr/.config/hosts.nix

sudo docker run --pull always --rm -it -v /home/mgr/.config/hosts.nix:/etc/hosts ghcr.io/stevenblack/hosts:latest updateHostsFile.py --auto --replace --extensions gambling porn

sed -i -e '1i\
#CUSTOM BLACKLIST\
0.0.0.0 tiktok.com\
0.0.0.0 www.tiktok.com\
0.0.0.0 www.instagram.com\
' .config/hosts.nix

sed -i "1s/^/{\nnetworking.extraHosts = '' \n/" .config/hosts.nix
echo "'';}" >>.config/hosts.nix

sed -i -e '1i\
# DONT EDIT THIS FILE, EDIT THE SCRIPT THAT CREATES THIS FILE IN $HOME/.scripts/hosts.sh\n' .config/hosts.nix

sudo nixos-rebuild switch
