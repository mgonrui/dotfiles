let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-23.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in

pkgs.mkShell {
  packages = with pkgs; [
    
    python311Packages.pandas
    python311Packages.requests
    python311Packages.requests-futures
    python311Packages.certifi
    python311Packages.colorama
    python311Packages.pysocks
    python311Packages.stem
    python311Packages.torrequest
    python311Packages.openpyxl
    python311Packages.exrex
  ];
GIT_EDITOR = "${pkgs.vim}/bin/vim";
DIRENV_WARN_TIMEOUT="100m";
shellHook = ''
'';
}
