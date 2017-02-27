#include<bits/stdc++.h>
using namespace std;
int main()
{

int width,height;              // width and height of the path
cin>>height>>width;
int n;                        // n denotes number of blocked paths
cin>>n;
int i=0;
char blocked[width+1][height+1];       // to store the value of blocked paths
for(int x = 0; x<=width; x++)
	{
	for(int y = 0; y<=height; y++)
	{
		blocked[x][y]='N';              //firstly 'N' denotes no path is blocked in start
	}
	}
while(i<n)
{
  int e,f,g,h;                         // points of blocked path
  cin>>e>>f>>g>>h;
   int w=min(e,g);                     // starting point on x-axis of blocked path 
   int he=min(f,h);                    // starting point on y-axis of blocked path
   if(e!=g)                            // if block is along x-axis then value in 'X'
   blocked[w][he]='X';
   else
        blocked[w][he]='Y';   	      //if block is along y-axis then value in 'Y' 
    i++;

}

int ways[width+1][height+1];            // dp matrix containing the number of ways
for(int x = 0; x<=width; x++)            //initially all ways are zero
	{
	for(int y = 0; y<=height; y++)
	{
		ways[x][y]=0;
	}
	}

ways[0][0] = 1;                             // initially ways when only on [0,0] is 1
	for(int x = 0; x<=width; x++)
	{
	for(int y = 0; y<=height; y++)
	{
		if(blocked[x-1][y]!='X'&&x>=1)      // if along x-axis is not blocked then add it in number of ways
		ways[x][y]=ways[x][y]+ways[x-1][y];
		if(blocked[x][y-1]!='Y'&&y>=1)      // if along y-axis is not blocked then add it in number of ways
		ways[x][y]=ways[x][y]+ways[x][y-1];
	}
	}
	cout<< ways[width][height]<<endl;           //total number of ways is in [width,height]
}
