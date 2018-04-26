#include <iostream>
//nao confundir com <cstring.h> q eh a biblioteca do c
#include <string>

using namespace std;

class SuperPoder{
	//inicializacao de nome deve ser feita no construtor
	string nome;
	int categoria;
//	Teste x[2]={1,2}; <--- errado, nao pode inicializar
//  Teste x[2]; <---- deveria ser inicializado la em SuperPoder::(string .....):nome(nome),categoria(categoria),X[2]={1,2} {};
public:
		string getNome();
		int getCategoria(); 
		SuperPoder(string,int);
};
class Personagem{
	string nome;
	string nomeVidaReal;
	SuperPoder **poderes;
	int npoderes;
public:
	Personagem(string,string);
	~Personagem();
	string getNome();
	string getNomeVidaReal();
	//Ver como declarar a funcao adicionarSuperpoder fora da classe
	bool adicionaSuperPoder(SuperPoder &sp){ // se passar o sp sem o "&" a referencia seria por copia,
		if (npoderes==4)//ao colocar o & ele passa por referencia
			return false;
		poderes[npoderes] = &sp;
		npoderes++;
		return true;
	}
	virtual float getPoderTotal();//Pq virtual? significa que há uma cadeia polimorfica
};//para não dar prioridade ao metodo de personagem usa-se o virtual

class SuperHeroi:public Personagem{ // ":" operador Herança, class superheroi herdou personagem
	
public:
	SuperHeroi(string,string);
	
};

SuperHeroi::SuperHeroi(string nome, string nomeVidaReal):
	Personagem(nome, nomeVidaReal){ //ta mandando chamar o construtor Personagem
}



float Personagem::getPoderTotal(){
	float soma = 0;
	for (int i = 0 ; i < npoderes; i++){
		soma += poderes[i]->getCategoria();
		
	}
	return soma;
}




Personagem::Personagem(string nome, string nomeVidaReal):nome(nome),nomeVidaReal(nomeVidaReal),npoderes(0){
	poderes = new SuperPoder*[4]; // não pode usar malloc pois há objeto
	//o Asterisco antes do [4] indica um vetor de ponteiros  
	//se o construtor faz alocacao dinamica, deve ser feito destrutor

}
Personagem::~Personagem(){
	delete[] poderes;//o colchete é pra desalocar vetor
}

string Personagem::getNome(){
	return nome;
}
string Personagem::getNomeVidaReal(){
	return nomeVidaReal;
}

//construtor.
//O Construtor é invocado após a criação do objeto
//o nome dentro do (nome) é o atribbuto em (string nome)
//o nome dentro de (categoria) vem de (int categoria)
SuperPoder::SuperPoder(string nome, int categoria):nome(nome),categoria(categoria){
}
int SuperPoder::getCategoria(){
	return categoria;
}
string SuperPoder::getNome(){
	return nome;
}


int main()
{
	SuperPoder sp1("velocidade",1);
	cout << sp1.getNome() << ": " << sp1.getCategoria() << endl;
	Personagem p("SuperMan", "Clark Kent");
	p.adicionaSuperPoder(sp1);
	p.adicionaSuperPoder(sp1);	
	cout << p.getPoderTotal();
	
	return 0;
}

