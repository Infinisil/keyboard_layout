let
  rev = "17.03";
  nixpkgs = (import <nixpkgs>{}).fetchFromGitHub {
    owner = "NixOS";
    repo = "nixpkgs";
    inherit rev;
    sha256 = "1fw9ryrz1qzbaxnjqqf91yxk1pb9hgci0z0pzw53f675almmv9q2";
  };

in

{ pkgs ? import nixpkgs {}
, layout ? "custom"
, PW1 }:

with if pkgs == null then import <nixpkgs> {} else pkgs;

stdenv.mkDerivation rec {
  name = "qmk_firmware";
  version = "0.5.178";
  src = fetchFromGitHub {
    owner = "qmk";
    repo = "qmk_firmware";
    rev = version;
    sha256 = "1si6an9wy6qb0xqsi0vbx4x4fx02hvzrbbwp6kkhkbvihybdncn2";
  };

  prePatch = ''
    orig=${./keymaps}/${layout}.c
    dest=keyboards/ergodox_ez/keymaps/${layout}/keymap.c
    pwd
    if [ -f "$orig" ]; then
      mkdir $(dirname "$dest")
      substitute "$orig" "$dest" --subst-var-by PW1 ${PW1}
    fi
  '';

  nativeBuildInputs = [
    dfu-programmer
    avrgcclibc
  ];

  buildPhase = ''
    make ergodox_ez:${layout}
  '';

  installPhase = ''
    mkdir -p $out/hex
    cp .build/*.hex $out/hex
  '';
}
