all: unzip ed2exe3
unzip:
	unzip -fo documentos
ed2exe3: main.c lista.c Hash.c  ExtraiPalavra.c
	gcc -o ed2exe3 main.c lista.c Hash.c ExtraiPalavra.c
run:
	./ed2exe3 documentos/m01.txt alfabeto.txt
clean:
	rm ed2exe3 -rf documentos
