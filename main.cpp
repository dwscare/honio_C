//�ɱ�����¼�Ƶ�GIF��������ScreenToGif��ɵ�
//�ұ���������VS2015����ɵ��Ե�
////����������У��뽫�ύ�ļ���EasyX_20220116.exe��װ��VS2015����߰汾
//������ͨ���鿴�ύ�ļ��е�EasyX_Help.chm������ȡ��Ϣ
#include <graphics.h>   //ͼ�ο�ͷ�ļ�
#include <conio.h>  //һ���ܹ��ϵ�ͷ�ļ������ر����⣬stdio.h�������Դ���
#include <stdio.h>
#include<Windows.h>   //ʹ���˶�ʱ����Sleep����
#include<stdlib.h>      //ʹ��system�����Ե��ã�DOS��ϵͳ�����shell���
#define length 1500  //����
#define height 400  //�߶�

int n;   //n��������������һ��ȫ�ֱ���
int** p;  //p��һ��ָ��ָ��
int  A = 0, B = 1, C = 2;

void show();
void startup();
void honio(int a, int b, int c, int k);
void move(int a, int b);

int main()   
{
	printf("input a number(it had better not be more than 16):");  //����̫����Ļ��װ����Ŷ���������ƶ������л��ص���
	scanf_s("%d", &n);     //������������scanf������VS2022�б���Ϊ����ȫ�����Ҫʹ��scanf_s�����Դ���
	int* tem[3]{};              //����ָ������
	 p = tem;                
	 int sad[3][64] = {};       //�����ά���飬Ԫ��ֵĬ��Ϊ0
	for (int i = 0; i < 3; i++)
		p[i] =sad[i]; 
	for (int i = 0; i < n; i++)
	{
		p[0][i] = 1;   //p[0][i]��Ӧ��0����λ�ϵĵ�i�����ӣ�A~0,B~1,C~2,���ִ�0��ʼ����)��ֵΪ0��ʾ���Ӳ��ử����ֵΪ1��ʾ���ӻ���
	}                         //���ӵĴ�������ϵ��¼���
	
	initgraph(length, height); //1500��400����
	BeginBatchDraw(); //��ʼ������ͼ��ִ�к��κλ�ͼ����������ʱ���������ͼ�����ϣ�ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ���
	show();
	honio(A, B, C, n);
	system("pause"); //��ͣ��Ϊ����ʾ

	//_getch();        �˺�����������ͷ�ļ�conio.h�С����ã��������������һ����ʹ������������棬�����ò���
	//closegraph();   ���ã��رջ�ͼ���ڡ�         ����һ��һ���ڱ����������𵽺͵�35�д���һ����Ч��
	return 0;
}

void show()
{
	startup();  //�������Żձ꺯��
	//�����ӣ�
	setfillcolor(RGB(0,128,255)); //���õ�ǰ�豸�����ɫ
	setlinecolor(WHITE);   //���õ�ǰ�豸������ɫ
	for (int i = 0; i < 3; i++)
	{
		int count= 0;
		//ֵΪ0��ʾ���Ӳ��ử����ֵΪ1��ʾ���ӻ���
		for (int j = n; j > 0; j--)
		{
			if (p[i][j - 1] == 1)
			{                       //fillrectangle���������б߿��������                                                                                             //���Ӹ߶�Ϊ10����С�����ӳ���Ϊ20
				fillrectangle(length * (i + 1) / 4 - j * 10, height - (count + 1) * 10, length * (i + 1) / 4 + j * 10, height - count * 10); //�������£�i��������j��cnt���������ϵĴ���
				count++;                                                                                                                                                                            //����ԭ�������Ͻǣ�X ������Ϊ����Y ������Ϊ����������λ������
			}
		}
	}																						
	FlushBatchDraw();  //ִ��δ��ɵĻ�������
}

void startup() //�������Żձ꺯��
{
	setfillcolor(RGB(128,128,128));          //���õ�ǰ�豸�����ɫ
	setlinecolor(WHITE);      //���õ�ǰ�豸������ɫ
	fillrectangle(length * 1 / 4 - 5, 0, length * 1 / 4 + 5, 400);    //��A��
	fillrectangle(length * 2 / 4 - 5, 0, length * 2 / 4 + 5, 400); //��B��
	fillrectangle(length * 3 / 4 - 5, 0, length * 3 / 4 + 5, 400); //��C��
	IMAGE img;	// ���� IMAGE ����
}

void honio(int a, int b, int c, int k)   //��a���ϵ����ӽ���b�����ƶ���c����
{
	if (k == 1)            //k��ָ������
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
	cleardevice();   //ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
	show();        //����������
	Sleep(500);  //�趨Ϊ��ʱ0.5s
}

//�ο��ĵ���https://docs.easyx.cn/zh-cn/intro  ����EasyX�ٷ��ĵ�web��
