nix-store -q --references /var/run/current-system/sw | cut -d'-' -f2- | fzf | (nohup ${SHELL:-"/bin/sh"} &) >/dev/null 2>&1
