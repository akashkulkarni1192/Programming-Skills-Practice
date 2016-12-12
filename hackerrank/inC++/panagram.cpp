#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype.h>
using namespace std;

char str[1001];
int freq[26];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i,j;
    gets(str);
    for(i=0;str[i];i++)
        if(isupper(str[i]))
            str[i]=tolower(str[i]);
    cout<<str;
    return 0;
}
