#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n=inf.readInt(1, 100000, "n");
    inf.readSpace();
    int d=inf.readInt(1, 1'000'000'000, "d");
    inf.readSpace();
    int m=inf.readInt(1, n, "m");
    inf.readEoln();
    inf.readInts(n, -1'000'000'000, 1'000'000'000);
    inf.readEoln();
    inf.readEof();
}
