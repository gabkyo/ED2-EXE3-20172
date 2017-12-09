all: unzip ed2exe3
unzip:
	@ unzip -o documentos.zip
ed2exe3: main.c lista.c Hash.c  ExtraiPalavra.c
	@ gcc -o ed2exe3 main.c lista.c Hash.c ExtraiPalavra.c
run:
	@ ./ed2exe3 alfabeto.txt >> arquivosaida.txt
clean:
	rm ed2exe3 arquivosaida.txt -rf documentos
