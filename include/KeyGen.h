//
// Created by axel_ on 01/06/2020.
//

#ifndef PROJET_KEYGEN_H
#define PROJET_KEYGEN_H

#include <SequenceD.h>

const std::vector<int> PC1 =   {57,49,41,33,25,17,9,
                               1,58,50,42,34,26,18,
                               10,2,59,51,43,35,27,
                               19,11,3,60,52,44,36,
                               63,55,47,39,31,23,15,
                               7,62,54,46,38,30,22,
                               14,6,61,53,45,37,29,
                               21,13,5,28,20,12,4};
const std::vector<int> PC2 =   {14,17,11,24,1,5,
                                3,28,15,6,21,10,
                                23,19,12,4,26,8,
                                16,7,27,20,13,2,
                                41,52,31,37,47,55,
                                30,40,51,45,33,48,
                                44,49,39,56,34,53,
                                46,42,50,36,29,32};

const std::vector<int> LS = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};


class KeyGen {
public:
    SequenceD<56> sequenceD;
    int round;

    //renvoie la prochaine clé à utiliser dans l’algorithme de chiffrement DES
    // fait une permutation sur SequenceD<64> et renvoie la clé généré par la permutation
    //faire un permutation et un left shift.
    SequenceD<48> next();

    //permettra de gernerer les clées/
    KeyGen(SequenceD<64>&);
};




#endif //PROJET_KEYGEN_H
