//
// Created by axel_ on 01/06/2020.
//

#include <include/gtest/gtest.h>
#include <test.h>
#include <SequenceD.h>
#include <Permutation.h>
#include <KeyGen.h>

using namespace std;
TEST(test_permetation,basic_test){
    SequenceD<64> sequenceD;
    for(int i=1 ; i < 65; i++){
        sequenceD[i-1] = i;
    }
    cout<<sequenceD.to_string()<<endl;

    Permutation<64,56> perm;

    Sequence sequence = perm(sequenceD,PC1);

    cout<<sequence.to_string()<<endl;
}