//
// Created by axel_ on 31/05/2020.
//

#include <include/gtest/gtest.h>
#include <Sequence.h>
#include <SequenceD.h>

using namespace std;

/**
 *
 * Contient un ensemble tests basique pour nos fonctions (certains test sont des affichages)
 * de SequenceD et des methodes non mèmbre utilisé par celle-ci
 *
 */
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

TEST(DECALAGE,basic_test){

    SequenceD<8> sequence1;
    sequence1[0] = 0;
    sequence1[1] = 1;
    sequence1[2] = 0;
    sequence1[3] = 0;
    sequence1[4] = 1;
    sequence1[5] = 1;
    sequence1[6] = 0;
    sequence1[7] = 1;
    sequence1.decalage(2);
    ASSERT_EQ("0001 0111",sequence1.to_string());

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

TEST(sous_seq,basic_test){
    SequenceD<64> sequenceD;

    Sequence sequence = sequenceD.sous_sequence(32,64);

    ASSERT_EQ(32,sequence.size());

    cout<< "SEQUENCE D : " << sequenceD.to_string()<<endl;
    cout<< "SOUS SEQ : " << sequence.to_string()<<endl;

}

TEST(iostream_test,basic_test){
    SequenceD<64> sequenceD;
    cout<<sequenceD;
}

TEST(test_modif_blank,basic_test){
    SequenceD<64> sequenceD;

    for(int i = 0; i<sequenceD.size();i++){
        sequenceD[i] = 0;
    }
    cout<<sequenceD.to_string()<<endl;
}

TEST(test_modif_cin,basic_test){
    //0110000101100001011000010110000101100001011000010110000101100001
    /**
    char* value;
    SequenceD<64> sequenceD;
    cin>>sequenceD;
    cout<<sequenceD.to_string()<<endl;

     **/
}

TEST(test_de_cin_qui_fonctionne,basic_test){
    SequenceD<64> seqD64;

    for(int i= 0; i<seqD64.size();i+=8){
        Sequence sequence = seqD64.sous_sequence(i,i+8);
        std::string contseq = sequence.to_string();
        char val= strtol(contseq.c_str(),0,2); //*stringToChar(contseq);
        cout<<val;
    }
}

TEST(read_and_write,basic_test){
    // a mettre dans un main
    /**
    SequenceD<64> sequenceD;

    write(cout,sequenceD);
    cout<<endl;
    //1100100000111111101010010010011010101110110110111010011111100111

    read(cin,sequenceD);

    cout<<sequenceD.to_string()<<endl;

     **/
}