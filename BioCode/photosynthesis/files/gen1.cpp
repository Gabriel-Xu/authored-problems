#include "testlib.h"
#include <iostream>
using namespace std;
 
int main(int argc, char* argv[]) {
    int n=atoi(argv[1]);
    registerGen(argc, argv, 1);
    int a =  rnd.next(0, 1000000000);
    int b =  rnd.next(0, 1000000000);
    cout << a << " " << b << "\n";
}
