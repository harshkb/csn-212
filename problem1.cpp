
#include <bits/stdc++.h>
using namespace std;


  int methodlength(vector <int> seq)
  {
    if(seq.size() == 1)
    return 1;
    vector<int> v(seq.size()-1);
    for(int i=1;i<seq.size();i++)
    {
      v[i-1] = seq[i] - seq[i-1];
    }
    int b=0;
    while( b < v.size() && v[b] == 0)
    b++;
    if(b == v.size())
    return 1;
    int d = v[b];
    int l = 2;
    for(int i=b+1;i<v.size();i++)
    {
      if(v[i]*d<0)
      {
        d*=-1;
        l++;
      }
    }
    return l;
  }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
  int n;
  cin>>n;
  int i=0;
  vector<int> v;
  while(i<n)
  {
      int val;
      cin>>val;
      v.push_back(val);
      i++;
  }
  cout<<methodlength(v)<<endl;
}
}
