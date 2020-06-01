//
// Created by axel_ on 01/06/2020.
//

#ifndef PROJET_PERMUTATION_H
#define PROJET_PERMUTATION_H
#include <SequenceD.h>
#include <Sequence.h>
#include <vector>
//NON COMPRIS : patron de class fonction ? c'est un patron de class ou patron de fonction ?
// les deux paramètre, taille_sortie, et taill entrer.
template<int taille_entree,int taille_sortie> class Permutation {
    //le vecteur d'entre doit avoir la même taille que taille_sortie
public:

    //permet de permuter des elements de la sequence en entree sans le modifier
    SequenceD<taille_sortie> operator()(SequenceD<taille_entree> sequence_in, std::vector<int> vector){
        SequenceD<taille_sortie> sequence_out;
        for(int pos = 0; pos < taille_sortie; pos++){
            //acces avec la methode ()
            sequence_out[pos] = sequence_in(vector[pos]-1);
        }
        return sequence_out;
    }
};


#endif //PROJET_PERMUTATION_H
