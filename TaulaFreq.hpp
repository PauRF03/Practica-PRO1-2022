#ifndef TAULAFREQ_HPP
#define TAULAFREQ_HPP

#include "Entrada.hpp"
#include<vector>

class TaulaFreq {
// Tipus de mòdul: dades
// Descripció del tipus: Taula de símbols i freqüències per la codificació Huffman.

  private:
	int size;
    	vector<Entrada> v;

  public:

	// Constructors
	
	// Pre: 
	// Post: Crea una taula de freqüències buida.
	TaulaFreq();
	
	
	// Consultors
	
	// Pre:
	// Post: El resultat és el nombre d'elements de la taula p.i.
	int mida() const; 
	
	//Pre: i>=0
	//Post: Retorna l'entrada emmagatzemada a la casella i del vector de la taula de frequencies;
	Entrada consultarCasella(const int &i) const;

	//Pre: i és un enter i codi és una string de 1s i 0s
	//Post:	A la casella amb index i del vector de la TaulaFreq implicita hi haurà la string codi. 
	void modificarCodificacio(const int i, const string &codi);
	
	// Modificadors

	// Pre:
	// Post: Omple la taula p.i. a partir dels caràcters de text.
	void construirTaula(string text);
	
	// Pre:
	// Post: Afegeix l'entrada e al final de la taula p.i.
	void afegirEntrada(const Entrada &e);
	
	
	// Escriptura
	
	// Pre:
	// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
	//       de la taula p.i.
	void mostrarTaula() const;
};

#endif
