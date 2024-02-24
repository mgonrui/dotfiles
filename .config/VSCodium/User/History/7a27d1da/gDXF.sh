#!/bin/sh
# always make shure to test your rsync commands with --dry-run to test everything works as expected
# before doing the real thing
rsync -aAXvz --delete-missing-args --delete /etc/nixos /run/media/mgr/mnt
rsync -aAXvz --delete-missing-args --delete --exclude={/mgr/prueba,/mgr/.cache} /home/mgr /run/media/mgr/mnt
