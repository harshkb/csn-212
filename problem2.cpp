#include<bits/stdc++.h>
using namespace std;
int main()
{

int width,height;              // width and height from one corner (0,0) to last corner (width,height)
cin>>height>>width;
int n;                        // n denotes number of blocked paths
cin>>n;
int i=0;
char blocked[width+1][height+1];       // matrix to denote blocked paths
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

ways[0][0] = 1;                             // initially ways when only upto [0,0] is 1
	for(int x = 0; x<=width; x++)
	{
	for(int y = 0; y<=height; y++)
	{
		if(blocked[x-1][y]!='X'&&x>=1)      // if previous block along x-axis is not blocked along x-direction 
		ways[x][y]=ways[x][y]+ways[x-1][y]; //then add it in number of ways
		if(blocked[x][y-1]!='Y'&&y>=1)      // if previous block along y-axis is not blocked  along y-direction 
		ways[x][y]=ways[x][y]+ways[x][y-1]; // then add it in number of ways
	}
	}
	cout<< ways[width][height]<<endl;           //total number of ways is upto  [width,height]
}
// Input
// width of the corner from 0
// height of the corner from 0
// number of blocked path 
// (a,b,c,d) co-ordinates of blocked path


//Output
// give number of ways excluding block paths to reach at corner from (0,0)
