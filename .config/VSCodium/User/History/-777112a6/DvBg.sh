#!/bin/sh
rsync -aAXv --delete-missing-args --delete /etc/nixos /run/media/mgr/mnt
rsync -aAXv --delete-missing-args --delete --exclude={/mgr/prueba,/mgr/.cache} /home/mgr /run/media/mgr/mnt
