#include "TaulaFreq.hpp"
using namespace std;

//Totes les Pre i Post esten escrites a l'arxiu "TaulaFreq.hpp"

TaulaFreq::TaulaFreq(){
	size=0;
	vector<Entrada>v;
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
	for(int i=0; i<text.size(); ++i){
		char c=text[i];
		int n=0;
		bool trobat=false;
		for(int j=0;j<v.size() and not trobat;++j){
			if(v[j].getSimbol()==c){
				trobat=true;
			}
		}
		if(not trobat){
			for(int j=0;j<text.size();++j){
				if(text[j]==c){
					++n;
				}
			}
			double fr=n/(double)text.size();
			Entrada e(c,fr);
			/*
			if(e.getSimbol()=='a'){
				e.setCodificacio("1");
			}else if(e.getSimbol()=='b'){
				e.setCodificacio("00");
			}else{
				e.setCodificacio("01");
			}*/
			afegirEntrada(e);
		}
	}
}

void TaulaFreq::mostrarTaula() const{
	cout<<" Bolcat taula frequencies ---->";
	cout<<endl<<" Mida: "<<size<<" simbols"<<endl;
	for(int i=0; i<v.size();++i){
		cout<<"Entrada "<<i<<".";
		cout<<v[i];
	}
	cout<<"----> Fi bolcat taula"<<endl;
}