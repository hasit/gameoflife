#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#define LIVE 79
#define DEAD 46

using namespace std;

class gol
{
private:
  char grid[20][20];
  char temp[20][20];
public:
  gol();
  void print();
  void nextgen();
  int neighbours(int, int);
  void setcell(int, int, int);
  void initpattern();
  void copytogrid();
};

gol::gol()
{
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
	{
	  grid[i][j]=DEAD;
	  temp[i][j]=DEAD;
	}
    }
}

void gol::print()
{
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
	{
	  cout<<grid[i][j]<<" ";
	}
      cout<<"\n";
    }
}

void gol::nextgen()
{
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
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

void gol::copytogrid()
{
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
	{
	  grid[i][j]=temp[i][j];
	}
    }
}

int gol::neighbours(int x, int y)
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

 void gol::setcell(int x, int y, int f)
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

void gol::initpattern()
{
  //Glider
  /*
  grid[0][1]=LIVE;
  grid[1][2]=LIVE;
  grid[2][0]=LIVE;
  grid[2][1]=LIVE;
  grid[2][2]=LIVE;
  */

  //Pulsar (period 3)
  grid[2][4]=LIVE;
  grid[2][5]=LIVE;
  grid[2][6]=LIVE;
  grid[2][10]=LIVE;
  grid[2][11]=LIVE;
  grid[2][12]=LIVE;

  grid[4][2]=LIVE;
  grid[4][7]=LIVE;
  grid[4][9]=LIVE;
  grid[4][14]=LIVE;
  
  grid[5][2]=LIVE;
  grid[5][7]=LIVE;
  grid[5][9]=LIVE;
  grid[5][14]=LIVE;
  
  grid[6][2]=LIVE;
  grid[6][7]=LIVE;
  grid[6][9]=LIVE;
  grid[6][14]=LIVE;
  
  grid[7][4]=LIVE;
  grid[7][5]=LIVE;
  grid[7][6]=LIVE;
  grid[7][10]=LIVE;
  grid[7][11]=LIVE;
  grid[7][12]=LIVE;

  grid[9][4]=LIVE;
  grid[9][5]=LIVE;
  grid[9][6]=LIVE;
  grid[9][10]=LIVE;
  grid[9][11]=LIVE;
  grid[9][12]=LIVE;

  grid[10][2]=LIVE;
  grid[10][7]=LIVE;
  grid[10][9]=LIVE;
  grid[10][14]=LIVE;
  
  grid[11][2]=LIVE;
  grid[11][7]=LIVE;
  grid[11][9]=LIVE;
  grid[11][14]=LIVE;
  
  grid[12][2]=LIVE;
  grid[12][7]=LIVE;
  grid[12][9]=LIVE;
  grid[12][14]=LIVE;

  grid[14][4]=LIVE;
  grid[14][5]=LIVE;
  grid[14][6]=LIVE;
  grid[14][10]=LIVE;
  grid[14][11]=LIVE;
  grid[14][12]=LIVE;
}

int main()
{
  gol g;
  
  g.initpattern();
  
  while(1)
    {
      g.print();
      g.nextgen();      
      cout<<"\r\x1b[20A"<<flush;
      // \r - reset the poition to the beginning of the next line
      // \x1b - ESC
      // [numberA - move cursor up number lines
      // [numberB - move cursor down number lines
      // [numberC - move cursor right number chars
      // [numberD - move cursor left number chars
      // H - upper left corner
      sleep(1);
    }

  return(0);
}

