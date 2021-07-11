#include <cstdio>   //printf
#include <iostream> //sout,cin

using namespace std;

int multiplefucn(int num_a,int num_b){

    int sum = num_a + num_b;

    return sum;
}

int main(void) {

    cout << multiplefucn(1 , 5 )<<endl;
    cout << multiplefucn(3 , 4)  << endl;
    cout << multiplefucn(8 , 13)  << endl;

    return 0;
}