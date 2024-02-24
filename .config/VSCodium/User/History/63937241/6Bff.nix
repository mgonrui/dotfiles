with import <nixpkgs> {};
let mcc-env = (callPackage <this_repo> {}).wrap stdenv;
in (mkShell.override {stdenv = mcc-env;}) {
  buildInputs = [ cmake gtest ];
}