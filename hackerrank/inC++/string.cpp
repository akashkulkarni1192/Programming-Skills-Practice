#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isSpace(char c){
    if(c==' ')
        return true;
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char strr[90],ch;
    gets(strr);
    //cout<<strr;
    string str(strr);
    int space = count_if(str.begin(),str.end(),isSpace);
    for(string::iterator it = str.begin();it!=str.end()-space;it++)
        cout<<*it;
    //cout<<space;
    return 0;
}
