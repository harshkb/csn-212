#include <iostream>
#include<vector>
using namespace std;
int n, t, tmp;
vector <int> v, lisa;
		
int lis(vector<int> v, int n, int l)
{
   	vector<int> var;
	for(int i=l; i<l+n; i++)
	{
		int num=v[i];
		vector<int> :: iterator it;
		it=lower_bound(var.begin(),var.end(),num);
		if(it==var.end())
		 	var.push_back(num);
		else
			*it=num;
	}
	int temp=var.size();
	var.clear();
    return temp;
 
}
 
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>tmp;
			v.push_back(tmp);
		}
		for(int i=0; i<n; i++)
		{
			tmp=v[i];
			v.push_back(tmp);
		}
	
		
		int count=0;
		for(int i=0; i<n; i++)
		{
			int temp=lis(v,n,i);
			if(temp>count)
			count=temp;
		}
		cout<<count<<endl;
		v.clear();
	}
	return 0;
} 