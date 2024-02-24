pkgs.mkShell {
  packages = with pkgs; [
    python311Packages.pandas
    python311Packages.requests


  ];
GIT_EDITOR = "${pkgs.vim}/bin/vim";
DIRENV_WARN_TIMEOUT="100m";
shellHook = ''
'';
}
