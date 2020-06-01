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

TEST(crochet_seqD, basic_test){
    SequenceD<8> sequence1;

    sequence1[0] = 1;
    sequence1[1] = 1;
    sequence1[2] = 1;
    sequence1[3] = 1;
    sequence1[4] = 0;
    sequence1[5] = 1;
    sequence1[6] = 0;
    sequence1[7] = 1;

    ASSERT_EQ("1111 0101",sequence1.to_string());
    ASSERT_EQ(1,sequence1(1));
}


TEST(operateur_etoile,basic_test){
    SequenceD<8> sequenceD;
    sequenceD[0] = 1;
    sequenceD[1] = 1;
    sequenceD[2] = 1;
    sequenceD[3] = 1;
    sequenceD[4] = 0;
    sequenceD[5] = 1;
    sequenceD[6] = 0;
    sequenceD[7] = 1;

    SequenceD<8> sequenceXor;
    sequenceXor[0] = 0;
    sequenceXor[1] = 1;
    sequenceXor[2] = 0;
    sequenceXor[3] = 1;
    sequenceXor[4] = 0;
    sequenceXor[5] = 1;
    sequenceXor[6] = 0;
    sequenceXor[7] = 1;

    SequenceD<8> seq_obtenu = sequenceD*sequenceXor;
    cout<<"Valeur seq obtenu "<<seq_obtenu.to_string()<<endl;
    cout<<"Valeur seqD "<<sequenceD.to_string()<<endl;
    cout<<"Valeur seq xor "<<sequenceXor.to_string()<<endl;


    ASSERT_EQ("1010 0000",seq_obtenu.to_string());
}