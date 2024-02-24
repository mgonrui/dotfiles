#!/bin/sh
rsync -aAXvz --delete-missing-args --delete /etc/nixos /run/media/mgr/mnt
rsync -aAXvz --delete-missing-args --delete --exclude={/mgr/prueba,/mgr/.cache} /home/mgr /run/media/mgr/mnt
