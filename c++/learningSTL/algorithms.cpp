#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool wayToSort(int i, int j) {
 	return i%10 < j%10; 
}
int main(){
	int arr[] = { 2,2,1,6,7},n=4;
	vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
	cout<<"\nArray details : ";
	for(int i=0;i<5;i++)
		cout<<v[i]<<" ";
	/*		----/SORT/----		*/
	sort(v.begin(),v.end());
	sort(arr,arr+n);
	cout<<"\nArray details : ";
	for(int i=0;i<5;i++)
		cout<<v[i]<<" ";

	/*		----/BINARY SEARCH/-----	*/
	cout<<"\nSearching : 2 : "<<binary_search(arr,arr+4,2);
	cout<<"\nSearching : 3 : "<<binary_search(v.begin(),v.end(),3);
 	
 	int iV[] =  {56, 77, -43, 32, 115, 951, 138, -152, -56};
    vector<int> intVec(iV,iV+8);
    // Do not include the () when you call wayToSort
    // It must be passed as a function pointer or function object
    //sort(intVec.begin(), intVec.end(), wayToSort);
    sort(iV,iV+9,wayToSort);
    cout<<"\nSorted by last digit  :  ";
    for (int i=0;i<9;i++)
        cout << iV[i] << " ";
   

   /*		----/LINEAR SEARCH/----		*/
    if(find(iV,iV+9,951)!=(iV+9))
    	cout<<"\nFound";
    else
    	cout<<"\nNot found";


    /*			----/COUNT/----		    */
    cout<<"\n2 appears in arr for "<<count(arr,arr+5,2)<<" times"<<endl;
    cout<<"\n8 appears in arr for "<<count(arr,arr+5,8)<<" times"<<endl;

    /*			----/COUNT IF/ ----		*/
    int mycount = count_if (arr,arr+5,[](int x){ return (x&1);});
  	std::cout << "arr contains " << mycount  << " odd values.\n";
	return 0;
}