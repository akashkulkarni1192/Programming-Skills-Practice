#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<int> arr ;
	deque<int> arr2(5,10);
	deque<int> third;
	int n;
	for(deque<int> :: iterator it = arr2.begin();it!=arr2.end();it++)
		cout<<"Element : "<<*it<<endl;
	cout<<"Arr2 Size "<<arr2.size()<<endl;
		cout<<"Arr Size "<<arr.size()<<endl;
	cout<<"Enter some elements into deque (push_back fashion): "<<endl;
	while((cin>>n) && n!=-1)
		arr.push_back(n);
	cout<<"Enter some elements into deque (push_front fashion): "<<endl;
	while((cin>>n) && n!=-1)
		arr.push_front(n);
	cout<<"Arr elements are : ";
	for(deque<int>::iterator it=arr.begin();it!=arr.end();it++)
		cout<<*it<<" ";

	cout<<"Inserting 100 at location 2 "<<endl;
	arr.insert(arr.begin()+1,100);
	cout<<"Deleting 5th element :"<<endl;
	arr.erase(arr.begin()+4);
	cout<<"Arr elements are : ";
	for(deque<int>::iterator it=arr.begin();it!=arr.end();it++)
		cout<<*it<<" ";
	//arr.pop_back()

	//arr.pop_front()

	//arr.front() arr.back() both gives value

	//arr.begin() and arr.end() both gives pointer
	//it=arr.begin()+1;
	//arr.insert(it,10);

	// cout<<endl<<" displaying arr using pop_front"<<endl;
	// while(!arr.empty()){
	// 	cout<<"Popped "<<arr.front()<<endl;
	// 	arr.pop_front();
	// }

	// third.assign(arr.begin()+1,arr.end());
	// cout<<"Third array assigned from 2nd location to last . Now displaying "<<endl;
	// for(deque<int>::iterator it=third.begin();it!=third.end();it++)


	// 	cout<<*it<<" ";
	return 0;

}