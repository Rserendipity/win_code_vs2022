#define _CRT_SECURE_NO_WARNINGS 1
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#define Width 40///���Ժ궨���ͼ��С
int main()
{
	srand((unsigned)malloc(1));//��ʼ�����������
	do///���¿�ʼ��ֱ����һ��ѭ��
	{
		int hX = Width / 2, hY = Width / 2, len = 4, i = 0, map[Width * Width] = { 0 };//ͷ���꣬�߳���ѭ����������ͼ��-1:ʳ��;0:�հ�;>0:����
		for (i = 0; i < Width; i += 2)///������ͼԪ�أ�-2:ǽ
			map[i] = map[Width * Width - 1 - i] = map[i * Width] = map[i * Width + Width - 1] = -2;//ʹ���ܵ�ǽ����һ��ֲ�
		char c = 'd', cl = 3, deaw[Width * Width * 2 + 1] = { 0 };//��ʼ�������뻺�棬���ƻ���
		sprintf_s(deaw, 32, "mode con: cols=%d lines=%d", Width * 2, Width);
		system(deaw);//�޸Ŀ���̨���ڴ�С
		for (int num = 3; num; num--)///���ɶ��ʳ�num��������
		{
			do i = rand() % (Width * Width);
			while (map[i]);
			map[i] = -1;
		}
		for (system("title �÷�:0"); 1; Sleep(100))///��ʼ���Ʒְ壬�ӳ�
		{
			if (_kbhit() && (cl = _getch()))//�ж��Ƿ�����
				switch (cl)
				{
				case 'a':case 'A':if (c != 'd')c = 'a'; break;//�ж���ԭ�����Ƿ��ͻ
				case 'd':case 'D':if (c != 'a')c = 'd'; break;
				case 's':case 'S':if (c != 'w')c = 's'; break;
				case 'w':case 'W':if (c != 's')c = 'w'; break;
				case ' ':_getch(); break;///�����������ո���ͣ
				case 27:exit(0); break;///����������Esc�˳�
				}
			switch (c)
			{
			case 'a':hX -= hX > 0 ? 1 : 1 - Width; break;//����ͷ����
			case 'd':hX += hX < Width - 1 ? 1 : 1 - Width; break;
			case 's':hY += hY < Width - 1 ? 1 : 1 - Width; break;
			case 'w':hY -= hY > 0 ? 1 : 1 - Width; break;
			}
			if (map[hY * Width + hX] > 1 || map[hY * Width + hX] == -2) break;//�ж��Ƿ�Ե��Լ�
			if (map[hY * Width + hX] == -1)//�ж��Ƿ�Ե�ʳ��
			{
				len++;
				do i = rand() % (Width * Width);
				while (map[i]);//��ֹʳ��λ�ø�����
				map[i] = -1;
				sprintf_s(deaw, 32, "title �÷�:%d", len - 4);///�������Ʒְ�
				system(deaw);
			}
			else for (i = 0; i < Width * Width; i++)//ȫ������ֵ-1
				if (map[i] > 0)map[i] -= 1;
			map[hY * Width + hX] = len;//��ͷ��ֵ
			for (i = 0; i < Width * Width * 2; i++)//���»��ƻ���
			{
				if (map[i / 2] == 0)deaw[i] = ' ';
				else if (map[i / 2] > 0)deaw[i] = (i & 1) ? ')' : '(';
				else if (map[i / 2] == -2)deaw[i] = (i & 1) ? ']' : '[';///������ǽ
				else deaw[i] = '0';
			}
			system("cls");//����
			printf(deaw);//��ӡ
		}
		sprintf_s(deaw, 48, "title GameOver!�÷�:%d ���ո�����¿�ʼ", len - 4);
		system(deaw);
	} while (_getch() == ' ');///�ո������
}
