#!/bin/sh
set -euo pipefail
git clone https://github.com/klavarog/qmk_bonus
mv ./qmk_bonus/chordgen.rb ./
mv ./qmk_bonus/rusmap.h ./
rm -rf qmk_bonus
echo Installed QMK Bonus tools successfully.
echo They will not be part of commit thanks to .gitignore.
