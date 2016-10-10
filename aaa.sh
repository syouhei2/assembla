
	gcc asm.c -o generate_bit
	gcc btox.c -o binaly_to_sign -lm
	./generate_bit test.txt > bitfile.txt
	./binaly_to_sign bitfile.txt > signal.txt
