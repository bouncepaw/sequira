QMK_SRC=~/src/qmk_firmware/keyboards
SQR_SRC=~/src/sequira

echo Clear older Sequira version.
rm -rf "$QMK_SRC/sequira"
echo Copy newer Sequira version.
cp -r "$SQR_SRC" "$QMK_SRC/sequira"
echo Finish.
