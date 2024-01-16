#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "TaulaFreq.hpp"
#include "BinaryTree.hpp"
#include "Entrada.hpp"
#include "PriorityQueue.hpp"

class Huffman {

// Tipus de mòdul: dades
// Descripció del tipus: Taula de codis de símbols obtinguts a partir de la
//                       codificació Huffman. 

private:	
	TaulaFreq t;
    
public:
    // Constructors

	// Pre:  tf = TF
	// Post: Crea una codificació Huffman buida a partir de la taula de freqüències
    	//       TF on només hi ha els símbols i la seva freqüència.
    	Huffman(const TaulaFreq &tf);
	
 	// Consultors
	
	// Pre:
	// Post: El resultat és la traducció del text d'entrada a un text
	//       amb la codificació Huffman ((string de 0 i 1)
	string codificar(const string &textE);
    
    	// Modificadors	

	// Pre:
    	// Post: Calcula la codificació Huffman (els codis de Huffman per cada símbol
    	//       segons la freqüència de cadascun d'ells).
    	void inserirCodis();
	
	//Pre:	L'arbre t conté tots els caràcters del text d'entrada, c és el caràcter a codificar, 
	//		s la string que contindrà codificacio en codi binari i trobat indica true si ja s'ha
	//		d'acabar de codificar
	//Post:	s conté la codificació del caràcter c en codi binari 
    	void calcularCodi(const BinaryTree<Entrada> &t, const char c, string &s, bool &trobat);

	//Pre:	
	//Post: Comprimeix la cua fins que tingui un sol element(l'arbre amb tots els caràcters
	//		de l'string d'entrada a les seves fulles) 
	void comprimirCua(Queue<BinaryTree<Entrada>> &cua); 
	
	// Escriptura
	
	// Pre:
	// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
	//       de la TaulaFreq del p.i., amb els símbols, freqüències i 
	//       codis Huffman.
	void mostrarCodis() const;
};

#endif
