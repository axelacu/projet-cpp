//
// Created by axel_ on 31/05/2020.
//
#include <Sequence.h>
#include <SequenceD.h>
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

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

int main(){

    std::string data = "11110101";
    char val= *stringToChar(data);
    cout<<  val << endl;

    SequenceD<64> sequence;

    Sequence sequence1 = sequence.sous_sequence(32,40);

    cout<<sequence.to_string()<<endl;
    cout<<sequence1.to_string()<<endl;

    return 0;


}
