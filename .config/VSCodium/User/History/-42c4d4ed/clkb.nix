let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-23.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in


pkgs.mkShell {
  packages = with pkgs; [
    clang_17
    gcc

  ];
GIT_EDITOR = "${pkgs.vim}/bin/vim";
DIRENV_WARN_TIMEOUT="100m";
shellHook = ''
'';
}
