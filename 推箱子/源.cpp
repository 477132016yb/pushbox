#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
/*
	  #  墙      1
	  &  目的地  3
	  ^  箱子    4
	  %  箱子到达目的地  7
	  *  人      5
	  *  人到达目的地 8
	  空格  路   0
*/
int cas;
int imgIndex[7] = { 0,1,3,4,5,7,8 };
IMAGE img[7];
int map[3][8][8] =
{
	1,1,1,1,1,1,1,1,
	1,3,4,0,0,4,3,1,
	1,0,1,0,1,1,0,1,
	1,0,0,5,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,1,0,1,1,0,1,
	1,3,4,0,0,4,3,1,
	1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,
	1,3,4,0,0,4,3,1,
	1,0,1,0,1,1,0,1,
	1,0,0,5,4,3,0,1,
	1,0,0,0,0,0,0,1,
	1,0,1,0,1,1,0,1,
	1,3,4,0,0,4,3,1,
	1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,
	1,3,4,0,0,4,3,1,
	1,0,1,0,1,1,0,1,
	1,3,4,5,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,1,0,1,1,0,1,
	1,3,4,0,0,4,3,1,
	1,1,1,1,1,1,1,1,
};
void loadresource()
{
	for (int i = 0; i < 7; i++)
	{
		CHAR FileName[20] = { 0 };
		sprintf(FileName, "scr/%d.png", imgIndex[i]);
		loadimage(img + i, FileName, 100, 100);
	}
}
void drawgrap()
{
	int x, y;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			x = j * 100;
			y = i * 100;
			switch (map[cas][i][j])
			{
			case 0:
				putimage(x, y, img + 0);
				break;
			case 1:
				putimage(x, y, img + 1);
				break;
			case 3:
				putimage(x, y, img + 2);
				break;
			case 4:
				putimage(x, y, img + 3);
				break;
			case 5:
				putimage(x, y, img + 4);
				break;
			case 7:
				putimage(x, y, img + 5);
				break;
			case 8:
				putimage(x, y, img + 6);
				break;
			}
		}
		printf("\n");
	}
}
void keydown()
{
	printf("第%d关", cas + 1);
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 5 || map[cas][i][j] == 8)
			{
				break;
			}
		}
		if (map[cas][i][j] == 5 || map[cas][i][j] == 8)
		{
			break;
		}
	}
	char userkey = getchar();
	switch (userkey)
	{
	case 'w':
	case 72:
		if ((map[cas][i - 1][j] >= 0 && map[cas][i - 1][j] < 9) && (map[cas][i - 1][j] == 0 || map[cas][i - 1][j] == 3))
		{
			map[cas][i - 1][j] += 5;
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i - 1][j] == 4 || map[cas][i - 1][j] == 7)
		{
			if (map[cas][i - 2][j] == 0 || map[cas][i - 2][j] == 3)
			{
				map[cas][i][j] -= 5;
				map[cas][i - 1][j] += 1;
				map[cas][i - 2][j] += 4;
			}
		}
		break;
	case 's':
		if ((map[cas][i + 1][j] >= 0 && map[cas][i + 1][j] < 9) && (map[cas][i + 1][j] == 0 || map[cas][i + 1][j] == 3))
		{
			map[cas][i + 1][j] += 5;
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i + 1][j] == 4 || map[cas][i + 1][j] == 7)
		{
			if (map[cas][i + 2][j] == 0 || map[cas][i + 2][j] == 3)
			{
				map[cas][i][j] -= 5;
				map[cas][i + 1][j] += 1;
				map[cas][i + 2][j] += 4;
			}
		}
		break;
	case 'a':
		if ((map[cas][i][j - 1] >= 0 && map[cas][i][j - 1] < 9) && (map[cas][i][j - 1] == 0 || map[cas][i][j - 1] == 3))
		{
			map[cas][i][j - 1] += 5;
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i][j - 1] == 4 || map[cas][i][j - 1] == 7)
		{
			if (map[cas][i][j - 2] == 0 || map[cas][i][j - 2] == 3)
			{
				map[cas][i][j] -= 5;
				map[cas][i][j - 1] += 1;
				map[cas][i][j - 2] += 4;
			}
		}
		break;
	case 'd':
		if ((map[cas][i][j + 1] >= 0 && map[cas][i][j + 1] < 9) && (map[cas][i][j + 1] == 0 || map[cas][i][j + 1] == 3))
		{
			map[cas][i][j + 1] += 5;
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i][j + 1] == 4 || map[cas][i][j + 1] == 7)
		{
			if (map[cas][i][j + 2] == 0 || map[cas][i][j + 2] == 3)
			{
				map[cas][i][j] -= 5;
				map[cas][i][j + 1] += 1;
				map[cas][i][j + 2] += 4;
			}
		}
		break;
	}
}
int gamerover()
{
	int i, j, flagbox = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 4)
			{
				flagbox = 1;
				return(flagbox);
			}
		}
	}
	return(flagbox);
}
int main()
{
	loadresource();
	initgraph(100 * 8, 100 * 8);
	while (1)
	{
		drawgrap();
		keydown();
		if (!gamerover())
		{
			cas++;
			if (cas == 3)
				break;
		}
	}
	closegraph();
	printf("恭喜你通关了");
	return 0;
}
