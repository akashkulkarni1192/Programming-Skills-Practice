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
char arr[90][90];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char strr[90],ch;
    gets(strr);
    //cout<<strr;
    string str(strr);
    int space = count_if(str.begin(),str.end(),isSpace);
    remove_if(str.begin(),str.end(),isSpace);
    int newLen = str.size()-space;
    int row = floor(sqrt(newLen));
    int col = ceil((float)newLen/row);
    cout<<"New Len : "<<newLen<<"   "<<row<<" x "<<col<<endl;
    string::iterator it = str.begin();
    for(int i=0;i<row && it!=str.end()-space;i++){
        for(int j=0;j<col && it!=str.end()-space;j++){
            arr[i][j]=*it;
            it++;
        }
    }
    cout<<"Matrix"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col ;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<"Result :\n";
    int i,j;
    for( i=0;i<col;i++){
        //cout<<"\n i = "<<i<<endl;
        for( j=0;j<row;j++){
           // cout<<"["<<j<<","<<i<<"]"<<endl;
            if(arr[j][i]==0)
                break;
            cout<<arr[j][i];
        }
        cout<<" ";
    }
    cout<<endl<<"Stopped at ["<<i<<","<<j<<endl;
    /*for(string::iterator it = str.begin();it!=str.end()-space;it++){
        
    }*/
    //cout<<space;
    return 0;
}
