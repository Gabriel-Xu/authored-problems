#include "testlib.h"
using namespace std;
 
int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int t=inf.readInt(1, 100, "t");
    inf.readEoln();
    for (int tc=0; tc<t; tc++) {
        setTestCase(t+1);
        string a=inf.readToken();
        inf.readSpace();
        string b=inf.readToken();
        inf.readEoln();
        ensure(1<=b.size() && b.size()<a.size() && 5<=a.size() && a.size()<=10'000);
        ensure(b[0]>'0' && a[0]>'0');
    }
    inf.readEof();
}
