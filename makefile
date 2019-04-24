hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Rastgele.o -c ./src/Rastgele.c
	gcc -I ./include/ -o ./lib/RastgeleKarakter.o -c ./src/RastgeleKarakter.c
	gcc -I ./include/ -o ./bin/test ./lib/Random.o ./lib/RastgeleKarakter.o ./src/Test.c

calistir:
	./bin/test
