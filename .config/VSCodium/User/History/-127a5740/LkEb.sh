#!/bin/sh

rm -rf /home/mgr/.config/hosts.nix
touch /home/mgr/.config/hosts.nix

sudo docker run --pull always --rm -it -v /home/mgr/.config/hosts.nix:/etc/hosts ghcr.io/stevenblack/hosts:latest updateHostsFile.py --auto --replace --extensions gambling

# sed -i "1s/^/ 0.0.0.0 domain1.com \n  0.0.0.0 domain2.com \n/" .config/hosts.nix
sed -i -e '1i\
0.0.0.0 tiktok.com\
0.0.0.0 www.tiktok.com\
# 0.0.0.0 www.instagram.com\
' .config/hosts.nix

sed -i "1s/^/{\n networking.extraHosts = '' \n/" .config/hosts.nix
echo "'';}" >>.config/hosts.nix

sudo nixos-rebuild switch
