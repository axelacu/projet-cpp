//
// Created by axel_ on 31/05/2020.
//

#include <include/gtest/gtest.h>
#include <Sequence.h>
#include <SequenceD.h>

using namespace std;
TEST(initialize_seqD,basic_test){
    SequenceD<8> sequenceD;

    ASSERT_EQ(sequenceD.size(),8);
    cout << sequenceD.to_string() << endl;

    cout<<"Seq_droite : " << sequenceD.right().to_string()<<endl;
    cout<<"Seq_gauche : " << sequenceD.left().to_string()<<endl;

    ASSERT_EQ(sequenceD.right().size(),4);
    ASSERT_EQ(sequenceD.left().size(),4);

    Sequence sequenceA(8);
    Sequence sequenceB(8);

    cout<<"Seq_A : " << sequenceA.to_string()<<endl;
    cout<<"Seq_B : " << sequenceB.to_string()<<endl;
    SequenceD<> sequenceD1 = SequenceD<>(sequenceA,sequenceB);

    cout<<"Seq_D : " << sequenceD1.to_string() <<endl;
    ASSERT_EQ(sequenceD1.to_string(),sequenceA.to_string() + " "  + sequenceB.to_string());

}


TEST(initialize_seqD,basic_test){

}