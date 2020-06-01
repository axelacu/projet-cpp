//
// Created by axel_ on 12/05/2020.
//

#ifndef PROJET_SEQUENCED_H
#define PROJET_SEQUENCED_H

#include "Sequence.h"

#include <sstream>
#include <bitset>
#include <cstring>
#include <bits/stdc++.h>
// on suppose que la la taille donnée en paramètre c'est celle la prmière sequence.
template<const int size_para = 4> class SequenceD : public Sequence {

public:
    Sequence sequence_right = Sequence(size_para/2);
public:
    //
    //Un constructeur sans paramètre
    //
    SequenceD():Sequence(size_para/2){
        taille=size_para/2;
    };
    /// Un constructeur prenant en paramètre deux Sequence
    /// \param sequenceA
    /// \param sequenceB
    SequenceD(Sequence& gauche, Sequence& droite){
        this->sequence_right = droite;
        sequence_left.clear();
        for(int i = 0; i< gauche.size(); i++){
            sequence_left.push_back(gauche[i]);
        }
    }
    /// destructeur
    ~SequenceD(){
        sequence_left.clear();
    }

public:
    /// L’opérateur [] qui permettra d’accéder (et potentiellement modifier) un bit de la séquence.
    /// \return
    int& operator[](int valeur_entier){

            int moitie = this->size()/2;


            if(valeur_entier<moitie)
            {
                return Sequence::operator[](valeur_entier);
            } else
            {
                //4 --> première de la sequence right
                //5 --> la deuxieme  de la sequence right

                return sequence_right[valeur_entier-moitie];
            }
    }

    /// L’opérateur () qui renverra la valeur d’un bit sans permettre de la modifier
    /// const spécifie que la fonction est une fonction « en lecture seule » qui ne modifie pas l’objet
    /// pour lequel elle est appelée
    /// \return
    int operator()(int valeur_entier) const{
        int moitie = this->size()/2;
        if(valeur_entier<moitie)
        {
            return Sequence::operator()(valeur_entier);
        } else
        {
            //4 --> première de la sequence right
            //5 --> la deuxieme  de la sequence right

            return sequence_right(valeur_entier-moitie);
        }

    }

    /// fonction membre size qui renvoie le nombre de bits de la séquence.
    /// \return
    int size() const{
        return Sequence::size() + sequence_right.size();
    }

    /// fonction membre decalage qui prendra en paramètre un entier et qui effectuera un décalage à gauche des
    ///bits de chaque sous-séquence d’autant de bits qu’indiqué par le paramètre entier

    void decalage(int pas){
        Sequence::decalage(pas);
        sequence_right.decalage(pas);
    }

    /// Opérateur * pour deux SequenceD(de même taille) donnée en paramètre.
    /// \param sequenceB sequence donnée en paramètre.
    /// \return SequenceD correspondant au résultat du «ou exclusif» (XOR)

     //renverra une SequenceD correspondant au résultat du « ou exclusif » (XOR) entre les deux séquences
     //données en paramètres

    SequenceD operator*(SequenceD &sequenceB)
    {
        if(sequenceB.size() != this->size()){
            std::cout<<" sequence de tailles differentes "<<std::endl;
            exit(EXIT_FAILURE);
        }

        SequenceD sequence_res = SequenceD(sequenceB.left(),sequenceB.right());

        for(int pos = 0; pos < this->size();pos++){
            bool bit_s1_val = sequenceB(pos);
            bool bit_s2_val = this->operator()(pos);
            sequence_res[pos] = !bit_s1_val != !bit_s2_val;
        }

        return sequence_res;
    }

    //Surdéfinition opérateur
public:
    Sequence &right() {
        return sequence_right;
    }

    Sequence &left()  {
        return super_class();
    }
    void setRight(const Sequence &sequence) {
        sequence_right = sequence;
    }

    std::string to_string(){
        return Sequence::to_string()  + " " + sequence_right.to_string() ;
    }

    Sequence sous_sequence(int begin,int fin){
        Sequence seq_res = Sequence(fin-begin);
        // pour chaque element entre begin et fin de la sequence le mettre dans seq_res
        for(int i=begin,j = 0;i<fin;i++,j++){

            seq_res[j] = this->operator()(i);
        }// retour nouvelle sequence
        return seq_res;
    }

    friend std::ostream& operator<<(std::ostream& out,SequenceD<64> seqD64);
    // TODO : Getter sous sequence Gauche ( ou fonction left)

    friend std::istream& operator>>(std::istream& in,SequenceD<64> &seqD64);
};


//https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
const char* stringToChar(std::string data){
    std::stringstream sstream(data);
    char c;
    std::string output;
    while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        c = char(bits.to_ulong());
        output+=c;
    }
    return output.c_str();
}

std::ostream& operator<<(std::ostream& out,SequenceD<64> seqD64)
{
    for(int i=0;i<64;i+=8)
    {
        Sequence sequence = seqD64.sous_sequence(i,i+8);
        std::string contseq = sequence.to_string();
        char val= *stringToChar(contseq);
        out<<val;
    }
    return out;
}

const char* charToBinary(char c) {
    std::string str;
    for (int i = 7; i >= 0; --i) {
        str+= ((c & (1 << i))? '1' : '0');

        std::cout<<str<<std::endl;
    }
    std::cout<<str<<std::endl;
    return str.c_str();
}

std::istream& operator>>(std::istream& in,SequenceD<64> &seqD64){
    char entre[8];
    in>>entre;

    for(int bit_index = 0;bit_index<8;bit_index++){
        const char* binary_char = charToBinary(entre[bit_index]);
        std::cout<<entre[bit_index]<<std::endl;
        for(int i = 0;i<64;i++){
            switch (binary_char[i]) {
                case '1':
                    seqD64[i] = 1;
                    break;
                case '0':
                    seqD64[i] = 0;
                    break;
                default:
                    seqD64[i] = 0;
            }
        }
    }
    return in;
}



#endif //PROJET_SEQUENCED_H
