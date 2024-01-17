#include "Huffman.hpp"

int main (){
	string s;
	// 1. Lectura del text d'entrada
	getline(cin, s);
	// 2. Creació de la taula de freqüències
	TaulaFreq t;
	t.construirTaula(s);
	// 3. Obtenció dels codis de Huffman
	Huffman h(t);
	// 4. Codificació Huffman d'un missatge de text
	h.inserirCodis();
	h.mostrarCodis();
	// 4.1 Mostrar el text d'entrada original
	cout << " Missatge d'entrada (com a string): " << s << "\n";
	// 4.2 Mostrar el text d'entrada amb la codificació Huffman
	cout << " Missatge codificat (com a string): " << h.codificar(s) << "\n";
}
