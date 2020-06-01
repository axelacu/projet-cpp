//
// Created by axel_ on 01/06/2020.
//

#include <include/gtest/gtest.h>
#include <test.h>
#include <SequenceD.h>
#include <Permutation.h>
#include <KeyGen.h>

using namespace std;
TEST(test_keyGenNext,basic_test) {
    SequenceD<64> sequenceD;
    for(int i=1 ; i < 65; i++){
        sequenceD[i-1] = i;
    }

    KeyGen keyGen(sequenceD);

    std::string after_pc1 = "5749413325179158504234261810259514335271911360524436 6355473931231576254463830221466153453729211352820124";

    ASSERT_EQ(keyGen.sequenceD.to_string(),after_pc1);

    //modifier sequenceD de keygen pour faciliter test
    SequenceD<56> sequenceKeyGen;
    for(int i=1 ; i < 57; i++){
        sequenceD[i-1] = i;
    }

    keyGen.sequenceD = sequenceKeyGen;

    SequenceD<48> sequencepc2 = keyGen.next();


    cout<< sequencepc2.to_string()<<endl;

}