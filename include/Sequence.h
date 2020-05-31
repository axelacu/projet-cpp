//
// Created by axel_ on 13/05/2020.
//

#ifndef PROJET_SEQUENCE_H
#define PROJET_SEQUENCE_H
#include<iostream>
#include<deque>
#include <list>
#include <vector>
#include <string>
class Sequence {

public:
    int taille;
    std::deque<int> sequence_left;

    // Un constructeur prenant en paramètre un entier
    Sequence(int taille = 4);
    ~Sequence();

    //
    Sequence(std::list<Sequence>);
   // ~Sequence();

    // opérateur [] permet d’accéder a un bit de la séquence
    int& operator[](int );
    //renvoit la valeur d’un bit sans de la modifier
    int operator()(int) const ;
    // fonction membre size renvoie le nbre de bits de la séquence.
    int size() const;
    //opérateur = renvoit et affecte à une séquence un bit
    void operator=(int);

    // fonction membre decalage
    void decalage(int);

    // Opérateur * pour deux Sequence(de même taille) données en paramètre.
    // param sequence sequence donnée en paramètr
    Sequence operator*(Sequence const&);
    //Création d'une nouvelle séquence qui ne modifie pas la séquence initiale de l'objet
    //En entrée nous retrouverons un vecteur d'entiers, recréation d'une nouvelle séquence à partir des élément
    //du vecteur, l'element en position i du vecteur se trouvera en positon i de la nouvelle sequence.
    // La taille de la la nouvelle sequence sera celle du vecteur
    Sequence permutation(std::vector<int>) const;
    //Le premier int correspond à l'indice de début(gauche) et le second à l'indice de fin (droite)
    Sequence sous_sequence(int, int);

    std::string to_string();
};


#endif //PROJET_SEQUENCE_H
