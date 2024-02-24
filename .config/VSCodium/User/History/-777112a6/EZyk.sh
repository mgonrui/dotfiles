#!/bin/sh
sudo rsync -aAXv --delete-missing-args --delete --exclude={/mgr/prueba,/mgr/.cache} /home/mgr /run/media/mgr/mnt