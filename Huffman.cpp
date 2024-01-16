#include "Huffman.hpp"

//Totes les Pre i Post estan indicades a l'arxiu "Huffman.hpp"

Huffman::Huffman(const TaulaFreq &tf){
	t = tf;

}

string Huffman::codificar(const string &textE){
	string s;
	for(int i = 0; i < textE.size(); i++){
		string aux = "";
		bool trobat = false;
		for(int j = 0; !trobat && j < t.mida(); ++j){
			Entrada e = t.consultarCasella(j);
			if(textE[i] == e.getSimbol()){
				aux = e.getCodificacio();
				break;
			}
		}
		s += aux;
	}
	return s;
}

void Huffman::comprimirCua(Queue<BinaryTree<Entrada>> &cua){
	if(cua.size() > 1){
		BinaryTree<Entrada>esquerre = cua.front();
		cua.pop();
		BinaryTree<Entrada>dreta = cua.front();
		cua.pop();
		double fresq = esquerre.getRoot().getFrequencia();
		double frdre = dreta.getRoot().getFrequencia();
		Entrada arrel;
		arrel.setFrequencia(fresq + frdre);
		BinaryTree<Entrada> t(arrel, esquerre, dreta);
		cua.push(t);
		comprimirCua(cua);
		//Fita: Cada cop la mida de la cua es va reduint.
		//H.I.:	La cua contindrà un sol arbre amb tots els caràcters a les fulles.
	}
}

void Huffman::calcularCodi(const BinaryTree<Entrada> &t, const char c, string &s, bool &trobat){
	if(!t.isEmpty()){
		if(t.getRoot().getSimbol() == c) trobat = true;
		else{
			s.push_back('0');	
			calcularCodi(t.getLeft(),c,s,trobat);
			//Fita:	Cada cop l'arbre a tractar és més petit, fins a arribar a la fulla.
			//H.I.:	Trobat indicarà si ja s'ha arribat a la fulla que conté el caràcter 
			//		c i s la codificació en binari del camí pres.
			if(!trobat){
				s.pop_back();
				s.push_back('1');
				calcularCodi(t.getRight(), c, s, trobat);
				//Fita:	Cada cop l'arbre a tractar és més petit, fins a arribar a la fulla.
				//H.I.:	Trobat indicarà si ja s'ha arribat a la fulla que conté el caràcter 
				//		c i s la codificació en binari del camí pres.
				if(!trobat) s.pop_back();					
			}
		}
	}
}

void Huffman::inserirCodis(){
	Queue<BinaryTree<Entrada>> cua;
	if(t.mida() == 1){
		string s = "0";
		t.modificarCodificacio(0, s);
	}else{
		for(int i = 0; i < t.mida(); i++){
			BinaryTree<Entrada> a(t.consultarCasella(i), BinaryTree<Entrada>(), BinaryTree<Entrada>());
			cua.push(a);
		}
		comprimirCua(cua);
		BinaryTree<Entrada> comprimit = cua.front();
		for(int i = 0; i < t.mida(); ++i){
			string s;
			bool trobat = false;
			char c = t.consultarCasella(i).getSimbol();
			calcularCodi(comprimit, c, s, trobat);
			t.modificarCodificacio(i, s);
		}	
	}
}

void Huffman::mostrarCodis() const{
	t.mostrarTaula();
}
