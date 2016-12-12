#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> st ;
	int n;
	while(cin>>n && n!=-1)
		st.push(n);
	cout<<"Stack contents : ";
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	//cout<<st.top();
	return 0;
}
