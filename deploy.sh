#!/bin/sh
QMK_SRC=~/src/qmk_firmware
SQR_SRC=~/src/sequira

echo Clear older Sequira version.
rm -rf "$QMK_SRC/keyboards/sequira"
echo Copy newer Sequira version.
cp -r "$SQR_SRC" "$QMK_SRC/keyboards/sequira"
echo Finish.

cd $QMK_SRC
make sequira:default:avrdude
