#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student//定义结构体
{
	int ID;//学号
	char name[10];//姓名
	char sex[4];//性别
	int Eng;//英语
	int Com;//计算机
	int Math;//数学
	//int All;//总分
	//double Average;//平均分
};

void ReMenu();
void DisplayMenu();//菜单
void InputStu_lee(struct Student stu[], int n);//输入
void OutputStu_lee(struct Student stu[], int n);//输出
int SearchStu_lee(struct Student stu[], int n);//查找
void UpdateStu_lee(struct Student stu[], int n);//修改
void AppendStu_lee(struct Student stu[], int *n);//添加

int main() {
	int userChoice;
	int n;
	struct Student *stu[100];
	
	printf("请输入学生人数：");
	scanf("%d", &n);
	InputStu_lee(stu, n);
	//OutputStu_lee(stu, n);
	
	do
	{
		DisplayMenu();
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 0:
			break;
		case 1:
		
			OutputStu_lee(stu, n);
			system("pause");
			break;
		case 2:
			SearchStu_lee(stu, n);
			system("pause");
			break;
		case 3:
			UpdateStu_lee(stu, n);
			system("pause");
			break;
		case 4:
			AppendStu_lee(stu, &n);
			
			system("pause");
			break;
		}
	} while (userChoice != 0);
	return 0;
}

/* 函数功能：显示菜单*/
void DisplayMenu()
{
	system("cls");
	printf("==============================\n");
	printf("      学生信息管理系统\n");
	printf("==============================\n");
	//输出菜单选项
	printf("\t0. 退出\n");
	printf("\t1. 显示学生信息\n");
	printf("\t2. 查找学生信息\n");
	printf("\t3. 修改学生信息\n");
	printf("\t4. 添加学生信息\n");
	printf("==============================\n");
	printf("请输入选项：");
}

//输入
void InputStu_lee(struct Student stu[], int n) {
	/*调试代码*/
	
		stu[0].ID = 4256007;
		strcpy(stu[0].name, "贝小鹏");
		strcpy(stu[0].sex, "男");
		stu[0].Eng = 76;
		stu[0].Com = 68;
		stu[0].Math = 84;
		if (n == 1) {
			return;
		}
	
		stu[1].ID = 4256012;
		strcpy(stu[1].name, "黄坚");
		strcpy(stu[1].sex, "女");
		stu[1].Eng = 87;
		stu[1].Com = 64;
		stu[1].Math = 66;
		if (n == 2) {
			return;
		}

		stu[2].ID = 4256020;
		strcpy(stu[2].name, "林继磊");
		strcpy(stu[2].sex, "女");
		stu[2].Eng = 78;
		stu[2].Com = 69;
		stu[2].Math = 78;
		if (n == 3) {
			return;
		}

		stu[3].ID = 4256026;
		strcpy(stu[3].name, "潘耀");
		strcpy(stu[3].sex, "男");
		stu[3].Eng = 54;
		stu[3].Com = 66;
		stu[3].Math = 52;
		if (n == 4) {
			return;
		}
	/*提交代码*/
	/*for (int i = 0; i < n; i++) {
		printf("正在输入第%d个学生的信息\n", i + 1);
		printf("请输入学号：");
		scanf("%d", &stu[i].ID);
		printf("请输入姓名：");
		scanf("%s", stu[i].name);
		printf("请输入性别：");
		scanf("%s", stu[i].sex);
		printf("请输入英语成绩：");
		scanf("%d", &stu[i].Eng);
		printf("请输入计算机成绩：");
		scanf("%d", &stu[i].Com);
		printf("请输入数学成绩：");
		scanf("%d", &stu[i].Math);
	}*/
}
//输出
void OutputStu_lee(struct Student stu[], int n) {
	printf("序号\t学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", i + 1, stu[i].ID, stu[i].name, stu[i].sex,
			stu[i].Eng, stu[i].Com, stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math, 
			(double)(stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math) / 3);
	}
}
//查找
int SearchStu_lee(struct Student stu[], int n) {
	int SerID;
	printf("请输入学生学号：");
	scanf("%d", &SerID);
	for (int i = 0; i < n; i++) {
		if (SerID == stu[i].ID) {
			printf("序号\t学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
			printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", i + 1, stu[i].ID, stu[i].name, stu[i].sex,
				stu[i].Eng, stu[i].Com, stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math,
				(double)(stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math) / 3);
			return (i + 1);
		}
		
		
	}
	printf("该学生的信息不存在，查找失败\n");
}
//修改
void UpdateStu_lee(struct Student stu[], int n) {
	int UpID;
	int m;
	printf("请输入需要修改的学生学号：");
	scanf("%d", &UpID);

	for (int i = 0; i < n; i++) {
		if (UpID == stu[i].ID) {
			do
			{
				printf(" 这是修改前的学生信息：\n");
				printf("序号\t学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
				printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", i + 1, stu[i].ID, stu[i].name, stu[i].sex,
					stu[i].Eng, stu[i].Com, stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math,
					(double)(stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math) / 3);
				ReMenu();
				scanf("%d", &m);
				
				switch (m)
				{
				case 0:
					break;
				case 1:
					printf("请输入修改后的姓名：");
					scanf("%s", stu[i].name);
					break;
				case 2:
					printf("请输入修改后的性别：");
					scanf("%s", stu[i].sex);
					break;
				case 3:
					printf("请输入修改后的英语成绩：");
					scanf("%d", &stu[i].Eng);
					break;
				case 4:
					printf("请输入修改后的计算机成绩：");
					scanf("%d", &stu[i].Com);
					break;
				case 5:
					printf("请输入修改后的高数成绩：");
					scanf("%d", &stu[i].Math);
				}
			} while (m != 0);

			printf("这是修改后的学生信息：\n");
			printf("序号\t学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
			printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", i + 1, stu[i].ID, stu[i].name, stu[i].sex,
				stu[i].Eng, stu[i].Com, stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math,
				(double)(stu[i].Math, stu[i].Eng + stu[i].Com + stu[i].Math) / 3);
				return;
			}

		
	}
	printf("该学生的信息不存在，修改失败\n");
}

//添加
void AppendStu_lee(struct Student stu[], int *n) {
	int i;
	if (*n == 100)
		printf("空间已满，添加失败！");
	else {
		printf("正在输入第%d个学生的信息\n", *n + 1);
		printf("请输入学号：");
		scanf("%d", &stu[*n].ID);
		printf("请输入姓名：");
		scanf("%s", stu[*n].name);
		printf("请输入性别：");
		scanf("%s", stu[*n].sex);
		printf("请输入英语成绩：");
		scanf("%d", &stu[*n].Eng);
		printf("请输入计算机成绩：");
		scanf("%d", &stu[*n].Com);
		printf("请输入数学成绩：");
		scanf("%d", &stu[*n].Math);
		*n = *n + 1;

	}
}



/*修改菜单*/
void ReMenu() {
	printf("==============================\n");
	printf("      请选择需要修改的数据\n");
	printf("==============================\n");
	printf("\t0. 退出\n");
	printf("\t1. 姓名\n");
	printf("\t2. 性别\n");
	printf("\t3. 英语\n");
	printf("\t4. 计算机\n");
	printf("\t5. 高数\n");
	printf("==============================\n");
	printf("请输入选项："); 
}
