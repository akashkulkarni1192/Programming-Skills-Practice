#include<iostream>
#include<set>
using namespace std;
int main(){
	set<int> arr;
	int n;
	cout<<"Enter elements : ";
	while(cin>>n && n!=-1)
		arr.insert(n);
	cout<<"\nElements are : ";
	for(set<int>::iterator it=arr.begin();it!=arr.end();it++)
		cout<<*it<<" ";
	cout<<"\nEnter element to be deleted : ";
	cin>>n;
	set<int>::iterator it = arr.find(n);
	if(it==arr.end())
		cout<<endl<<n<<" not found ";
	else
		arr.erase(it);
	cout<<"\nElements are : ";
	for(set<int>::iterator it=arr.begin();it!=arr.end();it++)
		cout<<*it<<" ";
	return 0;
}