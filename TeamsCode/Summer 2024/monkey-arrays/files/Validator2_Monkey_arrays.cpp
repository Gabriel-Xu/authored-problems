#include "testlib.h"

using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 50'000, "t");
    inf.readEoln();
    int total=0;
    for(int tests = 0; tests < t; tests++){
        setTestCase(tests + 1);
        int n = inf.readInt(1, 500'000, "n"); 
        total+=n;
        inf.readSpace();
        int x = inf.readInt(1, 1'000'000'000, "x");
        inf.readSpace();
        int y = inf.readInt(1, 1'000'000'000, "y");
        inf.readSpace();
        int k = inf.readInt(1, 1'000'000'000, "k"); 
        inf.readEoln();
        inf.readInts(n, 1, 1'000'000'000, "a");
        inf.readEoln();
    }
    inf.readEof();
    ensure(total<=500'000);
}
