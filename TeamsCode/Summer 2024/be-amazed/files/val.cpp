#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t=inf.readInt(1, 10'000, "t");
    inf.readEoln();
    long long tot=0;
    for (int tc=0; tc<t; tc++) {
        setTestCase(tc+1);
        long long n=inf.readInt(1, 1'000'000, "n");
        inf.readSpace();
        long long m=inf.readInt(1, 1'000'000, "m");
        inf.readEoln();
        tot+=n*m;
        for (int i=0; i<n; i++) {
            std::string s=inf.readToken();
            inf.readEoln();
            ensure(s.length()==m);
            if (i==0) {
                ensure(s[0]=='1');
            }
            for (int j=0; j<m; j++) {
                ensure(s[j]=='0'||s[j]=='1');
            }
        }
    }
    ensure(tot<=1'000'000);
    inf.readEof();
}
