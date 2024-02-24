let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-23.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in


pkgs.mkShell {
  packages = with pkgs; [
    vim
    clang
    gcc
    cowsay
  ];
GIT_EDITOR = "${pkgs.vim}/bin/vim";
DIRENV_WARN_TIMEOUT = "0";
shellHook = ''
echo "hello world"
'';
}
