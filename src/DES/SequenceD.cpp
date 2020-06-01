//
// Created by axel_ on 12/05/2020.
//

#include <SequenceD.h>

// ici on trouve seulement les fonctions non membres
// l'implementation des methodes de la classe sont dans SequenceD.h

//https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
const char* stringToChar(std::string data){
    std::stringstream sstream(data);
    char c;
    std::string output;
    while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        c = char(bits.to_ulong());
        output+=c;
    }
    return output.c_str();
}

//operateur << fonctionne mais à du mal avec l'encriptage des ascciii
//si elle est utilisé ailleur elle fonctionne très bien or avec out du ostream problème d'encodage.
std::ostream& operator<<(std::ostream& out,SequenceD<64> seqD64)
{
    for(int i=0;i<64;i+=8)
    {
        Sequence sequence = seqD64.sous_sequence(i,i+8);
        std::string contseq = sequence.to_string();
        //on a utilisé de librairie orienté C et pas c++ sinon on a une autre methode, qui utilise que du C++
        char val= strtol(contseq.c_str(),0,2);  //*stringToChar(contseq);

        //std::cout<<val<<std::endl;
        out<<val;
    }
    return out;
}


const std::string charToBinary(char c) {
    std::string str;
    for (int i = 7; i >= 0; --i) {
        str+= ((c & (1 << i))? '1' : '0');
    }

    return str;
}


std::istream& operator>>(std::istream& in,SequenceD<64> &seqD64){
    char entre[8];
    in>>entre;

    for(int bit_index = 0,bit_seq = 0;bit_index<8;bit_index++){

        if(entre[bit_index] == '\0'){
            for(int j = bit_seq; j<64;j++){
                seqD64[j] = 0;
            }
            break;
        }
        std::string binary_char = charToBinary(entre[bit_index]);
        //std::cout<<entre[bit_index]<<std::endl;
        //std::cout<<binary_char<<std::endl;
        for(int i = 0;i < 8;i++,bit_seq++){
            if(binary_char[i] == '1'){
                seqD64[bit_seq] = 1;
            }
            else {
                seqD64[bit_seq] = 0;
            }
        }
    }
    return in;
}

void write(std::ostream& out,SequenceD<64> &seqD64){
    out.write((seqD64.left().to_string() + seqD64.right().to_string()).c_str(),seqD64.size());

}

void read(std::istream& in,SequenceD<64> &seqD64){
    char lecture[64];
    in.read(lecture,seqD64.size());

    for(int i = 0; i<64;i++){
        if(lecture[i] == '1'){
            seqD64[i] = 1;
        }
        else {
            seqD64[i] = 0;
        }
    }

}
