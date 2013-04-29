#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#define LIVE 79
#define DEAD 46

using namespace std;

class gof
{
private:
  char grid[10][10];
  char temp[10][10];
public:
  gof();
  void print();
  void nextgen();
  int neighbours(int, int);
  void setcell(int, int, int);
  void initpattern();
  void copytogrid();
};

gof::gof()
{
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	{
	  grid[i][j]=DEAD;
	  temp[i][j]=DEAD;
	}
    }
}

void gof::print()
{
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	{
	  cout<<grid[i][j]<<" ";
	}
      cout<<"\n";
    }
}

void gof::nextgen()
{
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	{
	  if(grid[i][j]==LIVE)
	    {
	      if(neighbours(i,j)<2)
		{
		  setcell(i,j,0);
		}
	      else if(neighbours(i,j)>3)
		{
		  setcell(i,j,0);
		}
	      else
		{
		  setcell(i,j,1);
		}
	    }
	  else
	    {
	      if(neighbours(i,j)==3)
		{
		  setcell(i,j,1);
		}
	      else
		{
		  setcell(i,j,0);
		}
	    }
	}
    }
  copytogrid();
}

void gof::copytogrid()
{
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	{
	  grid[i][j]=temp[i][j];
	}
    }
}

int gof::neighbours(int x, int y)
{
  int count=0;
  
  if(grid[x-1][y-1]==LIVE)
    {
      count+=1;
    }
  if(grid[x-1][y]==LIVE)
    {
      count+=1;
    }
  if(grid[x-1][y+1]==LIVE)
    {
      count+=1;
    }
  if(grid[x][y-1]==LIVE)
    {
      count+=1;
    }
  if(grid[x][y+1]==LIVE)
    {
      count+=1;
    }
  if(grid[x+1][y-1]==LIVE)
    {
      count+=1;
    }
  if(grid[x+1][y]==LIVE)
    {
      count+=1;
    }
  if(grid[x+1][y+1]==LIVE)
    {
      count+=1;
    }
  
  return(count);
}

 void gof::setcell(int x, int y, int f)
{
  if(f==1)
    {
      temp[x][y]=LIVE;
    }
  else
    {
      temp[x][y]=DEAD;
    }
}

void gof::initpattern()
{
  /*glider*/
  grid[0][1]=LIVE;
  grid[1][2]=LIVE;
  grid[2][0]=LIVE;
  grid[2][1]=LIVE;
  grid[2][2]=LIVE;
}

int main()
{
  gof g;
  g.initpattern();
  while(1)
    {
      g.print();
      g.nextgen();      
      cout<<"\r\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A"<<flush;
      sleep(1);
    }

  return 0;
}

