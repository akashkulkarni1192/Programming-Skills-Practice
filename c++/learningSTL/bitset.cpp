#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int t,a;
    bitset<32> var ;
    cin>>t;
    while(t--){
        cin>>a;
        var = bitset<32>(a);
        cout<<var.flip().to_ulong()<<endl;
    }
    return 0;
}
