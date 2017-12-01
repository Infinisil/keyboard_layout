#! /usr/bin/env bash
set -x

out=$(nix-build --argstr PW1 "$(pass main | tail -1)" --argstr layout new)

sudo teensy-loader-cli -mmcu=atmega32u4 -v -w $out/hex/*

rm result
drv=$(nix-store -q --deriver $out)
nix-store --delete $drv $out

