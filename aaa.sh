
	read FILENAME
	make
	./asm $FILENAME > bitfile.txt
	python ascii2bin.py bitfile.txt code

	rm bitfile.txt asm 
