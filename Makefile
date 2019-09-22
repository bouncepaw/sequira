QARA = ~/bin/qara2c
QMK_DIR = ~/src/qmk_firmware

weave:
	@echo "Weaving literate source code..."
	$(QARA) < litsrc/config.h.md > config.h
	@echo "[1/3] Done config.h"
	$(QARA) < litsrc/keymap.c.md > keymaps/default/keymap.c
	@echo "[2/3] Done keymap.c"
	$(QARA) < litsrc/sequira.h.md > sequira.h
	@echo "[3/3] Done sequira.h"

clean:
	rm config.h
	rm keymaps/default/keymap.c
	rm sequira.h

get_qara:
	@echo "Installing Qaraidel for C to $(QARA)..."
	git clone "https://github.com/bouncepaw/qara2c.git"
	mv -T ./qara2c/qara2c.pl $(QARA)
	rm -rf qara2c

get_bonus:
	@echo "Installing QMK Bonus tools..."
	@echo "They will not be part of commit thanks to .gitignore"
	git clone "https://github.com/klavarog/qmk_bonus"
	mv ./qmk_bonus/chordgen.rb ./
	mv ./qmk_bonus/rusmap.h ./
	mv ./qmk_bonus/layermode.h ./
	rm -rf qmk_bonus

gen_chords:
	@echo "Chord count: `ruby chordgen.rb --count-chords`"
	ruby -Ku chordgen.rb > keymaps/default/chords.h
	@echo "Generated chords"

flash: weave gen_chords
	cd $(QMK_DIR)
	make sequira:default:avrdude

