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
#include <stdio.h>
#include <stdlib.h>
// on suppose que la la taille donnée en paramètre c'est celle la prmière sequence.
template<const int size_para = 4> class SequenceD : public Sequence {

public:
    // sequence de droite
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
    friend void write(std::ostream& out,SequenceD<64> &seqD64);
    friend void read(std::istream& in,SequenceD<64> &sequenceD);
};

template<class T> void affichage(T param_class){
    for(int i = 0; i < param_class.size(); i++){
        std::cout<< param_class(i);
    }
    std::cout<<std::endl;
};
#endif //PROJET_SEQUENCED_H
