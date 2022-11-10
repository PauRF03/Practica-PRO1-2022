#include "Entrada.hpp"

//Totes les pres i post estan definides a l'arxiu "Entrada.hpp"

Entrada::Entrada(){
	nom='|';
	frequencia=0;
	codificacio='-';
}

Entrada::Entrada(char c, double f){
	nom=c;
	frequencia=f;
	codificacio='-';	
}

Entrada::Entrada(const Entrada &e){
	nom=e.nom;
	frequencia=e.frequencia;
	codificacio=e.codificacio;
}

Entrada& Entrada::operator=(const Entrada &e){
	nom=e.nom;
	frequencia=e.frequencia;
	codificacio=e.codificacio;
	return *this;
}

Entrada::~Entrada(){

}

void Entrada::setFrequencia(double f){
	frequencia=f;
}

void Entrada::setCodificacio(string co){
	codificacio=co;
}

char Entrada::getSimbol() const{
	return nom;
}

double Entrada::getFrequencia() const{
	return frequencia;
}

string Entrada::getCodificacio() const{
	return codificacio;
}

bool Entrada::operator<(const Entrada &e) const{
	if(frequencia<e.frequencia){
		return true;
	}else{
		return false;
	}
}

bool Entrada::operator==(const Entrada &e) const{
	if(frequencia==e.frequencia){
		return true;
	}else{
		return false;
	}
}

ostream& operator<<(ostream &os, const Entrada &e){
	os<<" Simbol: "<<e.getSimbol()<<", Frequencia: "<<e.getFrequencia()<<", Codificacio: "<<e.getCodificacio()<<endl;
	return os;
}
