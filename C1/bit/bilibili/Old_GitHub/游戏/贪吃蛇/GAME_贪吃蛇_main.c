#include<windows.h>
#include<conio.h>
#include<stdio.h>
#define Width 45///可以宏定义地图大小
int main()
{
	srand((unsigned)malloc(1));//初始化随机数种子
	do///重新开始，直接套一个循环
	{
		int hX = Width / 2, hY = Width / 2, len = 4, i = 0, map[Width * Width] = { 0 };//头坐标，蛇长，循环变量，地图（-1:食物;0:空白;>0:蛇身）
		for (i = 0; i < Width; i += 2)///新增地图元素：-2:墙
			map[i] = map[Width * Width - 1 - i] = map[i * Width] = map[i * Width + Width - 1] = -2;//使四周的墙都隔一格分布
		char c = 'd', cl = 3, deaw[Width * Width * 2 + 1] = { 0 };//初始方向，输入缓存，绘制缓存
		sprintf_s(deaw, 32, "mode con: cols=%d lines=%d", Width * 2, Width);
		system(deaw);//修改控制台窗口大小
		for (int num = 3; num; num--)///生成多个食物，num控制数量
		{
			do i = rand() % (Width * Width);
			while (map[i]);
			map[i] = -1;
		}
		for (system("title 得分:0"); 1; Sleep(100))///初始化计分板，延迟
		{
			if (_kbhit() && (cl = _getch()))//判断是否输入
				switch (cl)
				{
				case 'a':case 'A':if (c != 'd')c = 'a'; break;//判断与原方向是否冲突
				case 'd':case 'D':if (c != 'a')c = 'd'; break;
				case 's':case 'S':if (c != 'w')c = 's'; break;
				case 'w':case 'W':if (c != 's')c = 'w'; break;
				case ' ':_getch(); break;///新增操作：空格暂停
				case 27:exit(0); break;///新增操作：Esc退出
				}
			switch (c)
			{
			case 'a':hX -= hX > 0 ? 1 : 1 - Width; break;//更新头坐标
			case 'd':hX += hX < Width - 1 ? 1 : 1 - Width; break;
			case 's':hY += hY < Width - 1 ? 1 : 1 - Width; break;
			case 'w':hY -= hY > 0 ? 1 : 1 - Width; break;
			}
			if (map[hY * Width + hX] > 1 || map[hY * Width + hX] == -2) break;//判断是否吃到自己
			if (map[hY * Width + hX] == -1)//判断是否吃到食物
			{
				len++;
				do i = rand() % (Width * Width);
				while (map[i]);//防止食物位置覆盖蛇
				map[i] = -1;
				sprintf_s(deaw, 32, "title 得分:%d", len - 4);///新增：计分板
				system(deaw);
			}
			else for (i = 0; i < Width * Width; i++)//全部蛇身值-1
				if (map[i] > 0)map[i] -= 1;
			map[hY * Width + hX] = len;//蛇头赋值
			for (i = 0; i < Width * Width * 2; i++)//更新绘制缓存
			{
				if (map[i / 2] == 0)deaw[i] = ' ';
				else if (map[i / 2] > 0)deaw[i] = (i & 1) ? ')' : '(';
				else if (map[i / 2] == -2)deaw[i] = (i & 1) ? ']' : '[';///新增：墙
				else deaw[i] = '0';
			}
			system("cls");//清屏
			printf(deaw);//打印
		}
		sprintf_s(deaw, 48, "title GameOver!得分:%d 按空格键重新开始", len - 4);
		system(deaw);
	} while (_getch() == ' ');///空格键继续
}
