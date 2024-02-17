#include<stdio.h>
#include<string.h>
#include<easyx.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<thread>//多线程
#include<time.h>//随机数用
#include<mmsystem.h>//播放音乐的头文件
#pragma comment(lib,"Winmm.lib")//播放音乐
using namespace std;
void showmap();

#define SPACE	0
#define WALL	1
#define ME		2
#define	COIN	3
#define DEST	4
#define kuandu	20
#define gaodu	20
int map[gaodu][kuandu];
int key = 0, shop = 0,destif=1,dest_x=1,dest_y=1,helpif=0;
int goal = 20, power = 50, energy = 5;
IMAGE imgs[5];
HWND gamewindow;//主游戏窗口
void setcoin();
//加载图片
void loadimg()
{
	loadimage(imgs + 0, _T("./imgs/0.jpg"), 40, 40);
	loadimage(imgs + 1, _T("./imgs/1.jpg"), 40, 40);
	loadimage(imgs + 2, _T("./imgs/2.jpg"), 40, 40);
	loadimage(imgs + 3, _T("./imgs/3.jpg"), 40, 40);
	loadimage(imgs + 4, _T("./imgs/4.jpg"), 40, 40);
}

//随机数生成
int myrand(int min,int max)
{
	srand((unsigned)time(NULL) * rand());
	return(rand() % (max - min + 1) + min);
}

void endgame()
{
	//system("cls");
	MessageBox(gamewindow, "游戏结束，你失败了！", "结束", MB_OK);//结束游戏
	//printf("游戏结束，你失败了！\n");
	//system("shutdown -s");皮一下很开心
	exit(1);
}
//打开帮助
void help()
{
	if (helpif == 1)
	{
		shop = 0;
		outtextxy(0, 0, "                                                              ");//清空原来的字
		outtextxy(0, 20, "                                                                       ");//清空原来的字
		outtextxy(0, 50, "                                                                                                      ");
		outtextxy(0, 0, "作者wjh");
		outtextxy(0, 20, "设定：状态:初始体力50，大力5，分数20");
		outtextxy(0, 40, "通过wsad移动人物，b打开商店，走一格消耗一点体力，若体力耗尽且分数足够则自动购买体力药水");
		outtextxy(0, 60, "有大力值可把墙推动一格，墙前面还有墙则直接压缩");
		outtextxy(0, 80, "通过吃钱获取分数，一个钱等于5分，吃到钱后在之前的位置生成一个墙");
		outtextxy(0, 100, "注意陷阱：吃钱时可能有15%的几率丢失不多余15$的钱,若钱不够，则直接失败！");
		outtextxy(0, 120, "分数可购买道具且立即使用道具");
		outtextxy(0, 140, "道具：铲子8$: 可挖除除地图边界外人物上下左右的墙   传送门10$: 可传送至地图内任意区域，传送到墙直接挖除   体力药水3$: 加50体力   奇迹药水12$: 可补充5大力");
	}
	else
	{
		//清除显示
		for (int a = 0; a < 8; a++)
		{
			outtextxy(0, a * 20, "                                                                                                                                                                                 ");
		}
	}
	
}

//初始化地图
void inmap()
{
	memset(map, SPACE, sizeof(map));
	//创建边界
	for (int a = 0; a < kuandu; a++)
	{
		map[0][a] = WALL;
		map[gaodu - 1][a] = WALL;
	}
	for (int a = 0; a < gaodu; a++)
	{
		map[a][0] = WALL;
		map[a][kuandu - 1] = WALL;

	}
	//创建人物
	map[2][2] = ME;
	setcoin();

}

void setcoin()
{
	//创建奖励
	int coin_x, coin_y;
	coin_x = myrand(1, gaodu - 2);
	coin_y = myrand(1, kuandu - 2);
	if (map[coin_x][coin_y] == SPACE)
	{
		map[coin_x][coin_y] = COIN;
	}
	else
	{
		for (int a = 0; a < gaodu; a++)
		{
			for (int b = 0; b < kuandu; b++)
			{
				if (map[a][b] == SPACE)
				{
					coin_x = myrand(1, gaodu - 2);
					coin_y = myrand(1, kuandu - 2);
					if (map[coin_x][coin_y] == SPACE)
					{
						map[coin_x][coin_y] = COIN;
						return;
					}
					else
					{
						map[a][b] = COIN;
						return;
					}
				}
			}
		}
		//胜利
		//system("cls");
		printf("恭喜你取得胜利！\n");
		exit(1);
	}
}
//随机陷阱
void hurt()
{
	static int hurttimes = 0;//防止重复掉入陷阱
	if (myrand(1, 100) <= 15)
	{
		if (hurttimes == 0)
		{
			int tmp = myrand(5, 20);
			goal -= tmp;
			//printf("掉入陷阱了，扣了%d$！\n", tmp - 5);
			char text_tmp[100];
			sprintf_s(text_tmp, "掉入陷阱了，扣了%d$！", tmp - 5);
			outtextxy(300, 500, text_tmp);
			hurttimes++;
			Sleep(1000);
			if (goal < 0)
			{
				endgame();
			}
		}
		else if (hurttimes > 0)
		{
			hurttimes--;
		}
	}
}

void showmap()
{
	//清屏
	//system("cls");
	//打印面板
	char tmp[100];
	sprintf_s(tmp, "分数：%d 体力：%d 大力值：%d", goal, power, energy);
	outtextxy(0, 0, "                                                              ");//清空原来的字
	outtextxy(0, 0,tmp);
	outtextxy(0, 20, "                                                              ");//清空原来的字
	outtextxy(0, 20, "按wasd移动，h打开帮助文档, b打开商店");
	//打印地图
	for (int a = 0; a < gaodu; a++)
	{
		for (int b = 0; b < kuandu; b++)
		{
			int x, y;
			x = b * 40;
			y = a * 40;
			switch (map[a][b])
			{
			case WALL:
				putimage(x, y+100, imgs + WALL);
				break;
			case SPACE:
				putimage(x, y+100, imgs + SPACE);
				break;
			case ME:
				putimage(x, y+100, imgs + ME);
				break;
			case COIN:
				putimage(x, y+100, imgs + COIN);
				break;
			}
			if (a == dest_x && b == dest_y && destif == 0)
			{
				int x2 = dest_y * 40;
				int y2 = dest_x * 40;
				putimage(x2, y2 + 100, imgs + DEST);
			}
		}
	}
	
	//打印商店
	if (helpif != 1)
	{
		if (shop == 1)
		{
			outtextxy(0, 50, "                                                                                   ");
			outtextxy(0, 50, "商店：1.铲子8$  2.传送门10$  3.体力药水3$  4.奇迹药水15$    空格传送");
		}
		else
		{
			//清空商店显示
			outtextxy(0, 50, "                                                                                                                                                         ");
		}
	}
}
void move(int key)
{
	flushmessage();
	int me_x, me_y;
	//寻找我的位置
	for (int a = 0; a < gaodu; a++)
	{
		for (int b = 0; b < kuandu; b++)
		{
			if (map[a][b] == ME)
			{
				me_x = a;
				me_y = b;
				goto end;
			}
		}
	}
	endgame();
end:;
	if (map[me_x - 1][me_y] == WALL && map[me_x + 1][me_y] == WALL && map[me_x][me_y - 1] == WALL && map[me_x][me_y + 1] == WALL && energy == 0 && goal < 5)
	{
		endgame();
	}
	switch (key)
	{
	case 'w':
		if (destif != 0)
		{
			if (map[me_x - 1][me_y] == SPACE && power != 0)
			{
				map[me_x - 1][me_y] = ME;
				map[me_x][me_y] = SPACE;
				power--;
			}
			//推方块
			if (energy > 0 && map[me_x - 1][me_y] == WALL && me_x - 2 >= 0 && map[me_x - 2][me_y] != COIN)
			{
				map[me_x - 2][me_y] = WALL;
				map[me_x - 1][me_y] = ME;
				map[me_x][me_y] = SPACE;
				energy--;
			}
			if (map[me_x - 1][me_y] == COIN)
			{
				hurt();
				map[me_x - 1][me_y] = ME;
				map[me_x][me_y] = WALL;
				goal += 5;
				setcoin();
			}
			if (power == 0 && goal >= 3)
			{
				goal -= 3;
				power += 50;
			}
			if (power == 0 && goal < 3)
			{
				endgame();
			}
		}
		else
		{
			if (dest_x > 1)
			{
				dest_x--;
			}
		}
		break;
	case 's':
		if (destif != 0)
		{
			if (map[me_x + 1][me_y] == SPACE && power != 0)
			{
				map[me_x + 1][me_y] = ME;
				map[me_x][me_y] = SPACE;
				power--;
			}
			//推方块
			if (energy > 0 && map[me_x + 1][me_y] == WALL && me_x < gaodu - 2 && map[me_x + 2][me_y] != COIN)
			{
				map[me_x + 2][me_y] = WALL;
				map[me_x + 1][me_y] = ME;
				map[me_x][me_y] = SPACE;
				energy--;
			}
			if (map[me_x + 1][me_y] == COIN)
			{
				hurt();
				map[me_x + 1][me_y] = ME;
				map[me_x][me_y] = WALL;
				goal += 5;
				setcoin();
			}
			if (power == 0 && goal >= 3)
			{
				goal -= 3;
				power += 50;
			}
			if (power == 0 && goal < 3)
			{
				endgame();
			}
		}
		else
		{
			if (dest_x < gaodu-2)
			{
				dest_x++;
			}
		}
		break;
	case 'a':
		if (destif != 0)
		{
			if (map[me_x][me_y - 1] == SPACE && power != 0)
			{
				map[me_x][me_y - 1] = ME;
				map[me_x][me_y] = SPACE;
				power--;
			}
			//推方块
			if (energy > 0 && map[me_x][me_y - 1] == WALL && me_y > 1 && map[me_x][me_y - 2] != COIN)
			{
				map[me_x][me_y - 2] = WALL;
				map[me_x][me_y - 1] = ME;
				map[me_x][me_y] = SPACE;
				energy--;
			}
			if (map[me_x][me_y - 1] == COIN)
			{
				hurt();
				map[me_x][me_y - 1] = ME;
				map[me_x][me_y] = WALL;
				goal += 5;
				setcoin();
			}
			if (power == 0 && goal >= 3)
			{
				goal -= 3;
				power += 50;
			}
			if (power == 0 && goal < 3)
			{
				endgame();
			}
		}
		else
		{
			if (dest_y > 1)
			{
				dest_y--;
			}
		}
		break;
	case 'd':
		if (destif != 0)
		{
			if (map[me_x][me_y + 1] == SPACE && power != 0)
			{
				map[me_x][me_y + 1] = ME;
				map[me_x][me_y] = SPACE;
				power--;
			}
			//推方块
			if (energy > 0 && map[me_x][me_y + 1] == WALL && me_y < kuandu - 2 && map[me_x][me_y + 2] != COIN)
			{
				map[me_x][me_y + 2] = WALL;
				map[me_x][me_y + 1] = ME;
				map[me_x][me_y] = SPACE;
				energy--;
			}
			if (map[me_x][me_y + 1] == COIN)
			{
				hurt();
				map[me_x][me_y + 1] = ME;
				map[me_x][me_y] = WALL;
				goal += 5;
				setcoin();
			}
			if (power == 0 && goal >= 3)
			{
				goal -= 3;
				power += 50;
			}
			if (power == 0 && goal < 3)
			{
				endgame();
			}
		}
		else
		{
			if (dest_y < kuandu - 2)
			{
				dest_y++;
			}
		}
		break;
	//打开关闭商店
	case 'b':
		if (shop == 0)
		{
			shop = 1;
		}
		else
		{
			shop = 0;
		}
		break;
	case 'h':
		if (helpif == 1)
		{
			helpif = 0;
		}
		else
		{
			helpif = 1;
		}
		help();
		break;
	//铲子
	case '1':
		if (shop == 0)
		{
			return;
		}
		if (goal >= 8)
		{
			if (me_x > 1)
			{
				map[me_x - 1][me_y] = SPACE;
			}
			if (me_x < gaodu - 2)
			{
				map[me_x + 1][me_y] = SPACE;
			}
			if (me_y > 1)
			{
				map[me_x][me_y - 1] = SPACE;
			}
			if (me_y < kuandu - 2)
			{
				map[me_x][me_y + 1] = SPACE;
			}
			goal -= 8;
		}
		break;
	//大力药水
	case '4':
		if (shop == 0)
		{
			return;
		}
		if (goal >= 12)
		{
			goal -= 12;
			energy += 5;
		}
		break;
	//传送门
	case '2':
		if (shop == 0)
		{
			return;
		}
		if (goal >= 10)
		{
			//showmap();
			destif = 0;
		}
		break;
	//体力药水
	case '3':
		if (shop == 0)
		{
			return;
		}
		if (goal >= 3)
		{
			power += 50;
			goal -= 3;
		}
		break;
	case 'p':
		if (destif == 0)
		{
			int tmp_x=dest_x, tmp_y=dest_y;
			if (map[tmp_x][tmp_y] == COIN)
			{
				goal += 5;
				setcoin();
			}
			map[me_x][me_y] = SPACE;
			map[tmp_x][tmp_y] = ME;
			goal -= 10;
			destif = 1;
		}
		break;
	}
	

}
ExMessage msg;
void boarddown()
{
	
	while (peekmessage(&msg))
	{
		if (msg.message == WM_KEYDOWN)
		{
			if (msg.vkcode == 65)
			{
				key = 'a';
				move(key);
			}
			if (msg.vkcode == 68)
			{
				key = 'd';
				move(key);
			}
			if (msg.vkcode == 87)
			{
				key = 'w';
				move(key);
			}
			if (msg.vkcode == 83)
			{
				key = 's';
				move(key);
			}
			if (msg.vkcode == 66)
			{
				key = 'b';
				move(key);
			}
			if (msg.vkcode == 72)
			{
				key = 'h';
				move(key);
			}
			if (msg.vkcode == 49)
			{
				key = '1';
				move(key);
			}
			if (msg.vkcode == 50)
			{
				key = '2';
				move(key);
			}
			if (msg.vkcode == 51)
			{
				key = '3';
				move(key);
			}
			if (msg.vkcode == 52)
			{
				key = '4';
				move(key);
			}
			if (msg.vkcode == 32)
			{
				key = 'p';
				move(key);
			}
		}
	}
}
clock_t starttime, endtime;
void start()
{
	loadimg();
	gamewindow = initgraph(800, 900);
	mciSendString("open ./music/start.mp3 alias bkmusic", NULL, 0, NULL);//播放背景音乐
	mciSendString("play bkmusic repeat", NULL, 0, NULL);//循环播放
	inmap();//初始化地图
	BeginBatchDraw();
	while (1)//游戏循环
	{
		endtime = clock();
		boarddown();
		while(endtime - starttime >= 1000/60)//60帧刷新
		{
			showmap();
			FlushBatchDraw();
			starttime = clock();
		}
	}
	EndBatchDraw();
}

int main()
{
	start();
	return 0;
}