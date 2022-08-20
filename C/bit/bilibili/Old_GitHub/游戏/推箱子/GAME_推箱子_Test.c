#include <stdio.h>
#include <conio.h>
#include <Windows.h>
/***********************************************************
*                                                          *
*     利用getch进行连续输入	            （基本的函数使用）    *
*     定义、使用了三个函数              （函数的多次调用）    *
*     利用数组，绘制图像                （数组的使用！！）    *
*     利用在数组中的加减，实现“移动”     （对数组元素修改）    *
*                                                          *
************************************************************/

/***********************************
*  定义以下的函数，函数内容在下面  *
************************************/

int huitu();
int yidong();
int shuying();
int main()//主函数 —— mian函数
{
	while (1)             //保证永远为真，进行循环，调用函数以停止循环
	{
		system("cls");   //每一步进行以后，删除前一步,避免图像过多
		huitu();         //绘制地图
		yidong();        //控制移动
	}
	return 0;
}

//定义数组，也是推箱子的地图
int map[9][11] = {
	{0,1,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0},
	{0,1,0,0,3,0,0,0,0,1,0},
	{0,1,0,3,0,3,3,3,0,1,1},
	{0,1,0,0,0,2,0,0,0,0,1},
	{1,1,0,0,1,1,1,0,3,0,1},
	{1,0,4,4,0,4,0,0,0,0,1},
	{1,0,4,4,0,4,4,3,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,0}
};

//根据上面的数组，绘制一个地图出来，后面的“移动”函数是修改数组中的数字来实现的
int huitu()
{
	shuying();                                //先判断输赢，如果赢了就不会再继续绘制
	for (int i = 0; i < 9; i++)               //控制上面定义的数组输出“图像”
	{
		for (int j = 0; j < 11; j++)
		{
			switch (map[i][j])
			{
			case 0: printf("  "); break;
			case 1: printf("■"); break;
			case 2: printf("♀"); break;
			case 3: printf("☆"); break;
			case 4: printf("◎"); break;
			case 6: printf("♂"); break;
			case 7: printf("★"); break;
			}
		}
		/********************************
		*   0表示“空地”               *
		*   1表示“墙”                 *
		*   2表示“人”                 *
		*   3表示“箱子”               *
		*   4表示“须要到达的地方”     *
		*   6表示“人站在点位上”       *
		*   7表示“箱子到达后的图像”   *
		*********************************/
		printf("\n");
	}
	return 0;
}

//“移动”的实现、推动箱子、撞墙等判定
int yidong()
{
	int temp_1, temp_2 = 0;
	int i, j, yidong;
	for (i = 0; i < 9; i++) 
	{
		for (j = 0; j < 11; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)
			{
				temp_1 = i;
				temp_2 = j;
			}
		}
	}

	yidong = _getch();      //使用字母WASD来控制移动
	switch (yidong)
	{
	case 'W':   
	case 'w':    

		if (map[temp_1 - 1][temp_2] == 0 || map[temp_1 - 1][temp_2] == 4)
		{
			map[temp_1][temp_2] -= 2;
			map[temp_1 - 1][temp_2] += 2;
		}
		else if (map[temp_1 - 1][temp_2] == 3 || map[temp_1 - 1][temp_2] == 7)
		{
			if (map[temp_1 - 2][temp_2] == 0 || map[temp_1 - 2][temp_2] == 4)
			{
				map[temp_1][temp_2] -= 2;
				map[temp_1 - 1][temp_2] -= 1;
				map[temp_1 - 2][temp_2] += 3;
			}
		}
		break;



	case 'S':
	case 's':

		if (map[temp_1 + 1][temp_2] == 0 || map[temp_1 + 1][temp_2] == 4)
		{
			map[temp_1][temp_2] -= 2;
			map[temp_1 + 1][temp_2] += 2;
		}

		else if (map[temp_1 + 2][temp_2] == 0 || map[temp_1 + 2][temp_2] == 4)
		{
			if (map[temp_1 + 1][temp_2] == 3 || map[temp_1 + 1][temp_2] == 7)
			{
				map[temp_1][temp_2] -= 2;
				map[temp_1 + 1][temp_2] -= 1;
				map[temp_1 + 2][temp_2] += 3;
			}
		}
		break;



	case 'A':
	case 'a':
		if (map[temp_1][temp_2 - 1] == 0 || map[temp_1][temp_2 - 1] == 4)
		{
			map[temp_1][temp_2] -= 2;
			map[temp_1][temp_2 - 1] += 2;
		}

		else if (map[temp_1][temp_2 - 2] == 0 || map[temp_1][temp_2 - 2] == 4)
		{
			if (map[temp_1][temp_2 - 1] == 3 || map[temp_1][temp_2 - 1] == 7)
			{
				map[temp_1][temp_2] -= 2;
				map[temp_1][temp_2 - 1] -= 1;
				map[temp_1][temp_2 - 2] += 3;
			}
		}
		break;



	case 'D':
	case 'd':
		if (map[temp_1][temp_2 + 1] == 0 || map[temp_1][temp_2 + 1] == 4)
		{
			map[temp_1][temp_2] -= 2;
			map[temp_1][temp_2 + 1] += 2;
		}

		else if (map[temp_1][temp_2 + 2] == 0 || map[temp_1][temp_2 + 2] == 4)
		{
			if (map[temp_1][temp_2 + 1] == 3 || map[temp_1][temp_2 + 1] == 7)
			{
				map[temp_1][temp_2] -= 2;
				map[temp_1][temp_2 + 1] -= 1;
				map[temp_1][temp_2 + 2] += 3;
			}
		}
		break;

	}
	return 0;
}

//利用函数控制输赢，结束main函数中的循环
int shuying()
{
	printf("\n   使用WASD控制你的人物\n\n");
	int k = 0;
	for (int i = 0; i < 9; i++)   //数组中代表箱子的数字为3，判定数组中是否存在3来判定是否赢
	{
		for (int j = 0; j < 11; j++)
		{
			if (map[i][j] == 3)
				k++;              //如果数组“地图”中存在3，则k便不会为0，并且由于每次绘制“地图”的时候都会判定  int shuying  函数，故每次 k 的初值都是0
		}
	}
	if (k == 0)                   //如果k等于0，则没有“箱子”了，便可以表示赢了
		printf("恭喜你，你赢了！\n");
	return 0;
}
