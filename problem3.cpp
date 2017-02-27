#include <bits/stdc++.h>
using namespace std;
		
int guests(vector<int> v, int n, int l)               // method to find number of guests eligible for lucky draw 
{                                                     // if there are n guests and we start from position l 
   	vector<int> store;                              // empty vector to store the value on sheets of eligible guests
	for(int i=l; i<l+n; i++)
	{
		int num=v[i];                         // number on sheet written on ith guest and store it in num
		vector<int> :: iterator it;             
		it=lower_bound(store.begin(),store.end(),num);   // search the number num in already store vectore 
		if(it==store.end())                              // if num is not found then
		 	store.push_back(num);                     // store it in store vector, so by this there is no repetition
		else
			*it=num;                                 // if it is found then iterator value will be num
	}
	int length=store.size();                                 // calculate the size of store vector in length
	store.clear();
    return length;                                      // and return the length
 
}
 
 
int main() 
{
	int t;                        // number of test cases
	cin>>t;
	while(t--)
	{
		int n;          //number of guests invited to party
		cin>>n;
		vector <int> v;         // to store the number written on sheet of each guest 
		int sheet;          // number written on sheet of each guest
		for(int i=0; i<n; i++)
		{
			cin>>sheet;    
			v.push_back(sheet);   // push the number on sheet
		}
		
		int count=0;                        // maximum number of guests available for lucky draw
		for(int i=0; i<n; i++)
		{
			int temp=guests(v,n,i);    // number of guests eligible for lucky draw if there are n guests and we start from position i 
			if(temp>count)            // if it is maximum number of guests
			count=temp;               // then change change the vakue of count to maximum number of guests
		}
		cout<<count<<endl;                    // Output maximum number of guests
		v.clear();                             // clear the value in vector v
	}
	
} 
//Input
// number of test cases
//number of guests
// value of the number written on their sheets

//Output
// the maximum number of guests eligible for lucky draw
