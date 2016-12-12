#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string s = "akashKulkarni";
  s.insert(s.size()/2,"*");
  cout << s << endl;

  reverse(s.begin()+5, s.end());
  cout<<s<<endl;
}