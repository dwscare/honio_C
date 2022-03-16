//由本程序录制的GIF，是依靠ScreenToGif完成的
//且本程序是在VS2015中完成调试的
////如果不能运行，请将提交文件的EasyX_20220116.exe安装到VS2015或更高版本
//还可以通过查看提交文件中的EasyX_Help.chm，来获取信息
#include <graphics.h>   //图形库头文件
#include <conio.h>  //一个很古老的头文件，除特别函数外，stdio.h即可用以代替
#include <stdio.h>
#include<Windows.h>   //使用了定时函数Sleep（）
#include<stdlib.h>      //使用system（）以调用（DOS）系统命令（和shell命令）
#define length 1500  //长度
#define height 400  //高度

int n;   //n代表盘子数，是一个全局变量
int** p;  //p是一个指针指针
int  A = 0, B = 1, C = 2;

void show();
void startup();
void honio(int a, int b, int c, int k);
void move(int a, int b);

int main()   
{
	printf("input a number(it had better not be more than 16):");  //数字太大，屏幕会装不下哦（盘子在移动过程中会重叠）
	scanf_s("%d", &n);     //输入盘子数。scanf（）在VS2022中被认为不安全，因而要使用scanf_s函数以代替
	int* tem[3]{};              //定义指针数组
	 p = tem;                
	 int sad[3][64] = {};       //定义二维数组，元素值默认为0
	for (int i = 0; i < 3; i++)
		p[i] =sad[i]; 
	for (int i = 0; i < n; i++)
	{
		p[0][i] = 1;   //p[0][i]对应第0个座位上的第i个盘子（A~0,B~1,C~2,数字从0开始数起)，值为0表示盘子不会画出，值为1表示盘子画出
	}                         //盘子的次序需从上到下计算
	
	initgraph(length, height); //1500×400像素
	BeginBatchDraw(); //开始批量绘图。执行后，任何绘图操作都将暂时不输出到绘图窗口上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出
	show();
	honio(A, B, C, n);
	system("pause"); //暂停，为了显示

	//_getch();        此函数被包含在头文件conio.h中。作用：按任意键进行下一步。使用它会产生警告，因而最好不用
	//closegraph();   作用：关闭绘图窗口。         与上一行一起在本问题中能起到和第35行代码一样的效果
	return 0;
}

void show()
{
	startup();  //画底座放徽标函数
	//画盘子：
	setfillcolor(RGB(0,128,255)); //设置当前设备填充颜色
	setlinecolor(WHITE);   //设置当前设备画线颜色
	for (int i = 0; i < 3; i++)
	{
		int count= 0;
		//值为0表示盘子不会画出，值为1表示盘子画出
		for (int j = n; j > 0; j--)
		{
			if (p[i][j - 1] == 1)
			{                       //fillrectangle函数：画有边框的填充矩形                                                                                             //盘子高度为10，最小的盘子长度为20
				fillrectangle(length * (i + 1) / 4 - j * 10, height - (count + 1) * 10, length * (i + 1) / 4 + j * 10, height - count * 10); //左上右下，i决定座，j（cnt）决定座上的次序
				count++;                                                                                                                                                                            //坐标原点在左上角，X 轴向右为正，Y 轴向下为正，度量单位是像素
			}
		}
	}																						
	FlushBatchDraw();  //执行未完成的绘制任务
}

void startup() //画底座放徽标函数
{
	setfillcolor(RGB(128,128,128));          //设置当前设备填充颜色
	setlinecolor(WHITE);      //设置当前设备画线颜色
	fillrectangle(length * 1 / 4 - 5, 0, length * 1 / 4 + 5, 400);    //画A座
	fillrectangle(length * 2 / 4 - 5, 0, length * 2 / 4 + 5, 400); //画B座
	fillrectangle(length * 3 / 4 - 5, 0, length * 3 / 4 + 5, 400); //画C座
	IMAGE img;	// 定义 IMAGE 对象
}

void honio(int a, int b, int c, int k)   //把a座上的盘子借由b座，移动到c座上
{
	if (k == 1)            //k代指盘子数
		move(a, c);   
	else
	{
		honio(a, c, b, k - 1);
		move(a, c);
		honio(b, a, c, k - 1);
	}
}

void move(int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		if (p[a][i] == 1)
		{
			p[a][i] = 0;
			p[b][i] = 1;
			break;
		}
	}
	cleardevice();   //使用当前背景色清空绘图设备
	show();        //画底座函数
	Sleep(500);  //设定为延时0.5s
}

//参考文档：https://docs.easyx.cn/zh-cn/intro  ←←EasyX官方文档web版
