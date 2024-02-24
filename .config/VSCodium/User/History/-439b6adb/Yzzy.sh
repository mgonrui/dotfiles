nix-store --query --requisites /run/current-system | cut -d- -f2- | sort | uniq | cut -d'-' -f2- | fzf | (nohup ${SHELL:-"/bin/sh"} &) >/dev/null 2>&1
