//
// Created by axel_ on 31/05/2020.
//
#include <Sequence.h>
#include <SequenceD.h>

using namespace std;

int main(){

    SequenceD<8> sequence1;

    sequence1[0] = 1;
    sequence1[1] = 1;
    sequence1[2] = 1;
    sequence1[3] = 1;
    sequence1[4] = 0;
    sequence1[5] = 1;
    sequence1[6] = 0;
    sequence1[7] = 1;

    cout<<sequence1.to_string()<<endl;
    for (int i=0;i<8;i++) {

    cout << sequence1.operator()(i) << endl;
}
    return 0;


}