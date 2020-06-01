//
// Created by axel_ on 01/06/2020.
//

#include "KeyGen.h"
#include <Permutation.h>
KeyGen::KeyGen(SequenceD<64>& sequence) {
    Permutation<64,56> perm;
    this->round = 0;
    this->sequenceD = perm(sequence,PC1);
}

SequenceD<48> KeyGen::next() {
    //get bits rotated by Round number
    int step = LS[this->round];
    this->round++;
    //appliying left shift of the sequence.
    this->sequenceD.decalage(step);
    Permutation<56,48> perm;

    return perm(sequenceD,PC2);
}