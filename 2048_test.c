#include "2048.h"


void show_grid(int (*grid)[4])
{
	printf("\n");
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4;j++)
		{
			printf("%d ",grid[i][j]);
		};
		printf("\n");
	};
};

bool rand_assign(int (*grid)[4])
{
	unsigned int rand_num=0;
	unsigned index=0;
	unsigned blank[16]={0};
	int fd = 0;
	bool ret = false;
	unsigned i = 0;
	unsigned j = 0;

	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(grid[i][j] == 0)
			{
				blank[index] = (i*4+j);
				index++;
			};
		};
	};
	if(index != 0)
	{
		fd = open("/dev/urandom",O_RDONLY);
		if(fd<0)
		{
			close(fd);
			return false;
		};
		read(fd,&rand_num,sizeof(int));
		close(fd);
		index = rand_num%16;
		i=blank[index]/4;
		j=blank[index]%4;
		grid[i][j]=2;
		ret=true;
	};
	return ret;
};

void left(int (*grid)[4])
{
	for(int i = 0; i<4; i++)
	{
		for(int j=0; j<3;j++)
		{
			int k = 1;
			while((grid[i][j] == 0) && ( k<(4-j)))
			{
				if(grid[i][j+k]!=0)
				{
					grid[i][j] = grid[i][j+k];
					grid[i][j+k] = 0;
					break;
				};
				k++;
			};
		};
	};
	return;
};

void right(int (*grid)[4])
{
	for(int i = 0; i<4; i++)
	{
		for(int j=3; j>0;j--)
		{
			int k = 1;
			while((grid[i][j] == 0) && ( k <= j))
			{
				if(grid[i][j-k]!=0)
				{
					grid[i][j] = grid[i][j-k];
					grid[i][j-k] = 0;
					break;
				};
				k++;
			};
		};
	};
	return;
};

void up(int (*grid)[4])
{
	for(int i = 0; i<4; i++)
	{
		for(int j=0; j<3;j++)
		{
			int k = 1;
			while((grid[j][i] == 0) && ( k<(4-j)))
			{
				if(grid[j+k][i]!=0)
				{
					grid[j][i] = grid[j+k][i];
					grid[j+k][i] = 0;
					break;
				};
				k++;
			};
		};
	};
	return;
};

void down(int (*grid)[4])
{
	for(int i = 0; i<4; i++)
	{
		for(int j=3; j>0;j--)
		{
			int k = 1;
			while((grid[j][i] == 0) && ( k <= j))
			{
				if(grid[j-k][i]!=0)
				{
					grid[j][i] = grid[j-k][i];
					grid[j-k][i] = 0;
					break;
				};
				k++;
			};
		};
	};
	return;
};

bool left_add(int (*grid)[4])
{
	bool ret=false;
	for(int i = 0; i<4; i++)
	{
		int j = 0;
		while(j<3)
		{
			if(grid[i][j]==0)
			{
				break;
			};
			if(grid[i][j] == grid[i][1+j])
			{
				grid[i][j] += grid[i][1+j];
				grid[i][1+j] = 0;
				j+=2;
				ret=true;
			}
			else
			{
				j++;
			};
		};
	};
	return ret;
};

bool right_add(int (*grid)[4])
{
	bool ret = false;
	for(int i = 0; i<4; i++)
	{
		int j = 3;
		while(j>0)
		{
			if(grid[i][j]==0)
			{
				break;
			};
			if(grid[i][j] == grid[i][j-1])
			{
				grid[i][j] += grid[i][j-1];
				grid[i][j-1] = 0;
				j-=2;
				ret=true;
			}
			else
			{
				j--;
			};
		};
	};
	return ret;
};

bool up_add(int (*grid)[4])
{
	bool ret=false;
	for(int i = 0; i<4; i++)
	{
		int j = 0;
		while(j<3)
		{
			if(grid[j][i]==0)
			{
				break;
			};
			if(grid[j][i] == grid[j+1][i])
			{
				grid[j][i] += grid[j+1][i];
				grid[j+1][i] = 0;
				j+=2;
				ret=true;
			}
			else
			{
				j++;
			};
		};
	};
	return ret;
};

bool down_add(int (*grid)[4])
{
	bool ret=false;
	for(int i = 0; i<4; i++)
	{
		int j = 3;
		while(j>0)
		{
			if(grid[j][i]==0)
			{
				break;
			};
			if(grid[j][i] == grid[j-1][i])
			{
				grid[j][i] += grid[j-1][i];
				grid[j-1][i] = 0;
				j-=2;
				ret=true;
			}
			else
			{
				j--;
			};
		};
	};
	return ret;
};

void main()
{
	bool ret = true;
	char order;
	int grid[4][4]={{0,2,2,0},{2,2,8,2},{8,0,4,2},{0,0,0,0}};
	show_grid(grid);
	while(ret)
	{
		scanf("%c",&order);
		if('n' == order)
		{
			ret = rand_assign(grid);
			show_grid(grid);
		};
	};
	return;
};


