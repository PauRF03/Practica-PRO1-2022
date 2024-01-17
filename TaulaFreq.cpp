#include "TaulaFreq.hpp"
using namespace std;

//Totes les Pre i Post esten escrites a l'arxiu "TaulaFreq.hpp"

TaulaFreq::TaulaFreq(){
	size = 0;
	vector<Entrada> v;
}

int TaulaFreq::mida() const{
	return size;
}

Entrada TaulaFreq::consultarCasella(const int &i) const{
	return v[i];
}

void TaulaFreq::afegirEntrada(const Entrada &e){
	v.push_back(e);
	size++;
}

void TaulaFreq::modificarCodificacio(const int i, const string &codi){
	v[i].setCodificacio(codi);
}

void TaulaFreq::construirTaula(string text){
	for(int i = 0; i < text.size(); ++i){
		int n = 0;
		bool trobat = false;
		for(int j = 0; !trobat && j < v.size(); ++j) if(v[j].getSimbol() == text[i]) trobat = true;
		if(!trobat){
			for(int j = 0; j < text.size(); ++j) if(text[j] == text[i]) ++n;
			double fr = n/(double)text.size();
			Entrada e(text[i], fr);
			afegirEntrada(e);
		}
	}
}

void TaulaFreq::mostrarTaula() const{
	cout << "Bolcat taula frequencies ---->\n";
	cout << "Mida: " << size << " simbols\n\n";
	for(int i=0; i<v.size();++i) cout << "Entrada " << i << "." << v[i];
	cout << "\n----> Fi bolcat taula\n";
}
