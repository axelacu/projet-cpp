//
// Created by axel_ on 12/05/2020.
//

#ifndef PROJET_SEQUENCED_H
#define PROJET_SEQUENCED_H


#include "Sequence.h"
// on suppose que la la taille donnée en paramètre c'est celle la prmière sequence.
template<int taille> class SequenceD : public Sequence {

public:
    Sequence sequence_droite;
public:
    //
    //Un constructeur sans paramètre
    //
    SequenceD();

    /// Un constructeur prenant en paramètre deux Sequence
    /// \param sequenceA
    /// \param sequenceB
    SequenceD(Sequence& gauche, Sequence& droite);
    /// destructeur
    ~SequenceD();

private:
    /// L’opérateur [] qui permettra d’accéder (et potentiellement modifier) un bit de la séquence.
    /// \return
    int& operator[](int);

    /// L’opérateur () qui renverra la valeur d’un bit sans permettre de la modifier
    /// const spécifie que la fonction est une fonction « en lecture seule » qui ne modifie pas l’objet
    /// pour lequel elle est appelée
    /// \return
    int operator()() const ;

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
        return sequence_droite;
    }

    const Sequence &left() const {
        return sequence_left;
    }
    void setRight(const Sequence &sequence) {
        sequence_droite = sequence;
    }

    // TODO : Getter sous sequence Gauche ( ou fonction left)
};


#endif //PROJET_SEQUENCED_H
