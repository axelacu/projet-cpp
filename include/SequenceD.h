//
// Created by axel_ on 12/05/2020.
//

#ifndef PROJET_SEQUENCED_H
#define PROJET_SEQUENCED_H


#include "Sequence.h"
// on suppose que la la taille donnée en paramètre c'est celle la prmière sequence.
template<int size_para = 4> class SequenceD : public Sequence {

public:
    Sequence sequence_right = Sequence(size_para);
public:
    //
    //Un constructeur sans paramètre
    //
    SequenceD():Sequence(size_para){
        taille=size_para;
    };
    /// Un constructeur prenant en paramètre deux Sequence
    /// \param sequenceA
    /// \param sequenceB
    SequenceD(Sequence& gauche, Sequence& droite);
    /// destructeur
    ~SequenceD(){
        sequence_left.clear();
    }

private:
    /// L’opérateur [] qui permettra d’accéder (et potentiellement modifier) un bit de la séquence.
    /// \return
    int& operator[](int valeur_entier){

    }

    /// L’opérateur () qui renverra la valeur d’un bit sans permettre de la modifier
    /// const spécifie que la fonction est une fonction « en lecture seule » qui ne modifie pas l’objet
    /// pour lequel elle est appelée
    /// \return
    int operator()(int valeur_entier) const{

    }

    /// fonction membre size qui renvoie le nombre de bits de la séquence.
    /// \return
    int size() const;

    /// fonction membre decalage qui prendra en paramètre un entier et qui effectuera un décalage à gauche des
    ///bits de chaque sous-séquence d’autant de bits qu’indiqué par le paramètre entier
  // on Utilise un void ou un BOOl ?
    void decalage(int);

    /// Opérateur * pour deux SequenceD(de même taille) donnée en paramètre.
    /// \param sequenceB sequence donnée en paramètre.
    /// \return SequenceD correspondant au résultat du «ou exclusif» (XOR)

     //renverra une SequenceD correspondant au résultat du « ou exclusif » (XOR) entre les deux séquences
     //données en paramètres
     SequenceD operator*(SequenceD const &sequenceB);
    //Surdéfinition opérateur
public:
    const Sequence &right() const {
        return sequence_right;
    }

    const Sequence &left() const {
        return sequence_left;
    }
    void setRight(const Sequence &sequence) {
        sequence_right = sequence;
    }

    std::string to_string(){
        return Sequence::to_string()  + " " + sequence_right.to_string() ;
    }

    // TODO : Getter sous sequence Gauche ( ou fonction left)
};

int toto_2();


#endif //PROJET_SEQUENCED_H
