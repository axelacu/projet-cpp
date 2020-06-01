//
// Created by axel_ on 01/06/2020.
//

#ifndef PROJET_NONMEMBER_H
#define PROJET_NONMEMBER_H
#include <iostream>
#include <SequenceD.h>


std::ostream& operator<<(std::ostream& out,SequenceD<64> seqD64);

std::istream& operator>>(std::istream&,SequenceD<64>);

void write(std::ostream&,SequenceD<64>);

void read(std::istream&,SequenceD<64>);

template<class T> void affichage(T param_class);

#endif //PROJET_NONMEMBER_H
