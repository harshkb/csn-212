
#include <bits/stdc++.h>
using namespace std;


  int methodlength(vector<int> input)    // method for finding the length of sequence
  {
     int n=input.size;                 //size of the input vector
    if(n == 1)                // if input is only 1 then output is 1
    return 1;
    vector<int> v(n-1);           // create vector container to store the vaue of differences between input
    for(int i=1;i<n;i++)           
    {
      v[i-1] = input[i] - input[i-1];     // calculating the difference between two consecutive numbers input and save in v vector
    }
    int b=0;
    while( b < v.size() && v[b] == 0)     // till the value of vector is 0 and b is the position
    b++;
    if(b == v.size())                // if all the value is zero then end of the length and  then output is 1;
    return 1;
    int d = v[b];                      // d is the value of vector on that position where difference is not equal to 0
    int l = 2;                            // length starts from 2
    for(int i=b+1;i<v.size();i++)          
    {
      if(v[i]*d<0)                         //check that if there comes alternate positive and negative value of vector 
      {                                    // then if we mutiply them consecutively the product must always be negative
        d=d*-1;                                // changing the value of d consecutively from positive to neagtive and reverse
        l++;                                // if this condition satisfy then increase in length by 1
      }
    }
    return l;                                // return length
  }

int main()
{
   
  int n;                                     // the length of the input
  cin>>n;
  int i=0;
  vector<int> v;                             // store the input in vector v
  while(i<n)
  {
      int val;                          // input value
      cin>>val;
      v.push_back(val);                     // store in vector
      i++;
  }
  cout<<methodlength(v)<<endl;                  // call the method and output the length
}

//Input
// length of the input sequence
// value of the sequences in order

//Output
//output the length which has alternate differences
