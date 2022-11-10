CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
TEST=tests

main.exe: main.o Huffman.o TaulaFreq.o Entrada.o  
	$(LINK.cc) -o $@ $^

main.o: main.cpp Huffman.hpp TaulaFreq.hpp


Huffman.o: Huffman.cpp TaulaFreq.hpp BinaryTree.hpp PriorityQueue.hpp


TaulaFreq.o: TaulaFreq.cpp Entrada.hpp


Entrada.o: Entrada.cpp Entrada.hpp

# Utilitats:
#
# L'opcio seguent serveix per generar el zip que heu de lliurar; 
# s'executa amb l'ordre "make empaquetar"
#
.PHONY: empaquetar
empaquetar: main.cpp Huffman.hpp Huffman.cpp TaulaFreq.hpp TaulaFreq.cpp Entrada.hpp Entrada.cpp BinaryTree.hpp PriorityQueue.hpp
	tar -czvf Pr_dni1_dni2.tar.gz Entrada.hpp Entrada.cpp TaulaFreq.hpp TaulaFreq.cpp Huffman.hpp Huffman.cpp BinaryTree.hpp PriorityQueue.hpp main.cpp
	

# Aquesta opcio serveix per netejar el directori de fitxers 
# innecessaris; s'executa amb l'ordre "make clean"
#
.PHONY: clean
clean:
	rm -vf *.o
	rm -vf *.exe
	
# Aquesta opcio serveix per executar els jocs de prova publics(*.inp)
# i comprovar si generen els resultats esperats (*.cor); s'executa
# amb l'ordre "make test"
#
.PHONY: test
test:
	@echo "======================================================================="
	./main.exe < $(TEST)/jpub1.inp | diff -b - $(TEST)/jpub1.cor; 
	./main.exe < $(TEST)/jpub2.inp | diff -b - $(TEST)/jpub2.cor;
	./main.exe < $(TEST)/jpub3.inp | diff -b - $(TEST)/jpub3.cor;
	./main.exe < $(TEST)/jpub4.inp | diff -b - $(TEST)/jpub4.cor;
