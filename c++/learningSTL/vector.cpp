#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr  ;
	int n,i;
	cout<<"Enter 3 element(push back):";
	for(i=0;i<3;i++){
		cin>>n;
		arr.push_back(n);
	}
	// cout<<"Enter 3 element(push front):";
	// for(i=0;i<3;i++){
	// 	cin>>n;
	// 	arr.push_front(n);
	// }
	cout<<"Array elements"<<endl;
	for(vector<int>::iterator it=arr.begin();it<arr.end();it++)
		cout<<*it;
	return 0;
}