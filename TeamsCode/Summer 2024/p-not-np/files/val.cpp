#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int p=inf.readInt(0, 100'000, "p");
    inf.readEoln();
    inf.readEof();
}
