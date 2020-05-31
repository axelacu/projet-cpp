
// Created by axel_ on 13/05/2020.
#include <iostream>
#include <vector>
#include <initializer_list>
#include <Sequence.h>
#include <math.h>
#include <time.h>
#include <algorithm>

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

void Sequence::decalage(int pas)  {

    this->sequence_left;

    rotate(sequence_left.begin(), sequence_left.begin()+pas, sequence_left.end());
}

//http://www.cplusplus.com/forum/general/65862/
static std::string convert_to_binary(unsigned int val)
{
    std::string binary_string;
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);

    for(int i = 0; i < sizeof(int) * 8; i++)
    {
        if( (val & mask) == 0 )
            binary_string += '0' ;
        else
            binary_string+= '1' ;

        mask  >>= 1;
    }
    return binary_string;
}

void Sequence::operator=(int valeur_entier) {

    std::string value_binary_str = convert_to_binary(valeur_entier);
    for(int last = (this->size()-1), decrease = 1; last >=0 ; last--){
        if(last<value_binary_str.size()){
            char val_char = value_binary_str[value_binary_str.size() - decrease];

            int value = std::atoi(&val_char);
            (this)->operator[](last) = value;
            decrease++;
        }
    }
}
//affichage
std::string Sequence::to_string() {
    std::string str = "";
    for(int i = 0 ; i < sequence_left.size(); i++){

        str+=std::to_string(sequence_left[i]);
    }
    return str;
}
//destructeur de la deque
Sequence::~Sequence() {
    sequence_left.clear();
}

