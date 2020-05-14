//
// Created by axel_ on 13/05/2020.
//

#ifndef PROJET_SEQUENCE_H
#define PROJET_SEQUENCE_H


class Sequence {
    // Un constructeur prenant en paramètre un entier
    Sequence(int taille = 4);
    ~Sequence();
// Un second constructeur qui construit une Sequence
    ConstructionSequence : VOIR COURS 4,
    // opérateur [] permet d’accéder a un bit de la séquence
    int& operator[](int);
    //renvoit la valeur d’un bit sans de la modifier
    int operator()() const ;
    // fonction membre size renvoie le nbre de bits de la séquence.
    int size() const;
    //opérateur = renvoit et affecte à une séquence un bit
    int operator= Je ne comprends pas

    // fonction membre decalage
    bool decalage();

    // Opérateur * pour deux Sequence(de même taille) données en paramètre.
    // param sequence sequence donnée en paramètr
    Sequence operator * (Sequence const &ConstructionSequence);

    //

};


#endif //PROJET_SEQUENCE_H
