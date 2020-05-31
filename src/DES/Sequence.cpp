
// Created by axel_ on 13/05/2020.
#include <iostream>
#include <vector>
#include <initializer_list>
#include <Sequence.h>
#include <math.h>
#include <time.h>

using namespace std;

Sequence::Sequence(int taille)
{//Attribution aléatoire de valeurs booléenneà la liste
    this->taille = taille;
    for(int i=0;i<taille;i++){
        sequence_left.push_back(rand()%2);
    }
}
//[s1,s2,s3]
//[1001,1011,0101]
Sequence::Sequence(std::list<Sequence> sequences_list) {
    taille=0;

    for(list<Sequence>::iterator it = sequences_list.begin(); it != sequences_list.end(); it++){
        int size = it->size();
        //Ajout des valeurs de chaque liste dans une seule et unique liste
        for(int val = 0; val<size;val++){
            int bit = it->operator()(val);
            sequence_left.push_back(bit);
            taille++;
        }
    }
}
int& Sequence::operator[](int pos){
    int pos_it=0;
    for(std::deque<int>::iterator it= sequence_left.begin(); it!=sequence_left.end(); ++it)
    {
        if(pos_it==pos){
            return (*it);   //On accède à l'élément pointé via l'étoile
        }
        pos_it++;
    }

}

int Sequence::operator()(int pos) const {
    return sequence_left[pos];
}

int Sequence::size() const {
    return sequence_left.size();
}
//https://codes-sources.commentcamarche.net/source/9720-conversion-decimale-binaire
int& Sequence::operator=(int valeur_entier) {

    int bits, bit_fac;
    char binary[255];
    bits = int(log(valeur_entier)/log(2));
    for(int i = 0; i < bits+1; ++i)
    {
        bit_fac=int(pow(2,bits-i));
        binary[i]=(valeur_entier / bit_fac > 0? '1' : '0');
        valeur_entier=(valeur_entier / bit_fac > 0? valeur_entier - bit_fac : valeur_entier);
    }


    for(int j=0; j<taille; ++j)
    {
        std::cout<<"interieur boucle : " << binary[j] <<std::endl;
        sequence_left[j] = binary[j];
    }
}


std::string Sequence::to_string() {
    std::string str = "";
    for(int i = 0 ; i < sequence_left.size(); i++){

        str+=std::to_string(sequence_left[i]);
    }
    return str;
}

Sequence::~Sequence() {
    sequence_left.clear();
}

