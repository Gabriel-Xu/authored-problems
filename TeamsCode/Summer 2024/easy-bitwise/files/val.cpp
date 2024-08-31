#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t=inf.readInt(1, 100, "t");
    inf.readEoln();
    int tot=0;
    for (int tc=0; tc<t; tc++) {
        setTestCase(tc+1);
        int n=inf.readInt(2, 200'000, "n");
        tot+=n;
        inf.readEoln();
        inf.readInts(n, 1, 1'000'000'000, "a");
        inf.readEoln();
    }
    ensure(tot<=200'000);
    inf.readEof();
}
