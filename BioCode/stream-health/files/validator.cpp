#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t=inf.readInt(1, 1000, "t");
    inf.readEoln();
    inf.readInts(t, 0, 1'000'000, "NO3");
    inf.readEoln();
    inf.readInts(t, 0, 1'000'000, "P");
    inf.readEoln();
    inf.readEof();
}
