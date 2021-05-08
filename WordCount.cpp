#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main(int argc, char *argv[])
{
	FILE *fp;    //文件指针
	int ch;
	int num = 0;


	// 判断是否输入文件
	if (argc != 3)
	{
		printf("请使用格式: %s 文件名", argv[0]);
		exit(1); 
	}

	// 判断能否成功打开文件
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("打开文件 %s 失败", argv[2]);
		exit(1);
	}

	if (strcmp(argv[1], "-c") == 0)
	{
		while ((ch = getc(fp)) != EOF)
		{  //EOF 表示文件结束
			num++;
		}
		printf("字符数：%d个\n", num);
	}
	else if(strcmp(argv[1], "-w") == 0)
	{
		while ((ch = getc(fp)) != EOF)
		{
			if ((ch == ' ') || (ch == ','))
			{
				num++;
			}
		}
		printf("单词数：%d个\n", num+1);
	}
	else
	{
		printf("输入格式不正确");
	}
	fclose(fp);
	return 0;
}

