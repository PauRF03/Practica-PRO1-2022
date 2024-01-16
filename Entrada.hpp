#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include <string>
#include <iostream>
using namespace std;

class Entrada{
// Tipus de mòdul: dades
// Descripció del tipus: Conté un símbol a codificar, la seva freqüència d'aparició i
//                       el seu codi de Huffman.
	
private:

	char nom;
	double frequencia;
	string codificacio;

public:
	// Constructors
	
	// Pre: 
	// Post: Crea una entrada buida.
    	Entrada();
    
	// Pre:  f > 0
    	// Post: Crea una entrada de símbol c i freqüència f sense codi Huffman.
    	Entrada(char c, double f);
	
    	// Pre: 
    	// Post: Crea una entrada amb els valors de l'entrada e.
    	Entrada(const Entrada &e);
	
	// Pre: 
    	// Post: El resultat és una entrada amb els valors de l'entrada e.
    	Entrada& operator=(const Entrada &e);
    
    
    	// Destructor 
	
	// Post: Esborra automàticament els objectes locals en sortir d'un
	//       àmbit de visibilitat.
   	~Entrada();
    
	   
    	// Modificadors
	
	
    	// Pre:  f > 0 
    	// Post: La freqüència de l'entrada p.i. passa a ser f.
    	void setFrequencia(double f);
    
	// Pre: 
    	// Post: El codi Huffman de l'entrada p.i. passa a ser co.
    	void setCodificacio(string co);
    
       
    	// Consultors
	
	// Pre:
    	// Post: El resultat és el símbol de l'entrada p.i.
    	char getSimbol() const;
    
	// Pre:
    	// Post: El resultat és la freqüència de l'entrada p.i.
    	double getFrequencia() const;
   
    	// Pre:
    	// Post: El resultat és el codi Huffman de l'entrada p.i.
    	string getCodificacio() const;
   
    	// Pre: 
    	// Post: El resultat indica si la freqüència de l'entrada p.i. 
	//       és estrictament menor que la freqüència de l'entrada e.
    	bool operator<(const Entrada &e) const;
    
    	// Pre: 
    	// Post: El resultat indica si la freqüència de l'entrada p.i. 
	//       és	igual que la freqüència de l'entrada e.
    	bool operator==(const Entrada &e) const;
	
    	// Escriptura
	
	// Pre: 
    	// Post: S'han escrit els atributs de l'entrada e al canal 
	//       estàndard de sortida.
    	friend ostream& operator<<(ostream &os, const Entrada &e);

};

#endif
