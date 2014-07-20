#include<stdio.h>
#include<stdlib.h>
#include<string.h>   
#define LEN sizeof(struct Tour)
#define TOUR_NUM 100

struct Tour
{int team;
char name[10];
char mudi[10];
char statedate[10];
char overdate[10];
int num;
struct Tour *next;
};
int n;

struct Tour *head;
struct Tour *p1,*p2;
typedef struct Tour FILL;
void file(void)
{
		printf("\nManagement for Students' scores\n");
		printf(" 1.添加 	record\n");
		printf(" 2.读取    	record\n");
		printf(" 3.列表  	record\n");
		printf(" 4.查找    	record\n");
		printf(" 5.删除  	record\n");
		printf(" 6.修改    	record\n");
		printf(" 7.保存    	record\n");
		printf(" 0.退出\n");
		printf("输入你的选择：");
}
struct Tour * add(struct Tour *head)
{
	
	int m,i,flag;                                                               //定义整型变量m,i
	char sel[3],*ch1=sel;                                                  //定义字符数组，字符指针
	struct Tour *p,*p1,*p2;                                          //定义结构体指针p,p1,p2
	p1=p2=(struct Tour *)malloc(LEN);                                //开辟一个结构体大小的空间并把地址给p1和p2
	if(head==NULL)                                                         //判断是否有加载链表
	{
		p=p1;                                                              //记录链表头
	}
	else
	{
		printf("是否要在原有数据上继续添加(Yes/No)?");                     //给出提示是否要在原数据上继续添加内容
		scanf("%s",ch1);                                                   //输入选择
		getchar();
		if(strcmp(ch1,"Yes")==0)                                           //判断选择
		{
			p=head;                                                        //记录原链表表头
			for(i=1;i<n;++i)                                               //循环n次
			{
				head=head->next;                                           //指向下一个结构体
			}
			head->next=p1;                                                 //链表之间的链接
		}
		else
		{
			head=NULL;                                                     //清除原链表头
			p=p1;                                                          //记录链表头
		}
	}
	printf("\n请输入添加的人数:");
	scanf("%d",&m);                                                        //输入添加人数
	getchar();
	for(i=1;i<=m;++i)                                                      //循环m次
	{
		n++;                                                               //增加加载人数
		printf("\n团队编号:");
		scanf("%d",&p1->team);
		printf("\n导游名字:");
		scanf("%s",p1->name);
		printf("\n旅游目的地:");
		scanf("%s",p1->mudi);
		printf("\n出发日期:");
		scanf("%s",p1->statedate);
		printf("\n结束日期:");
		scanf("%s",p1->overdate);
		printf("\n游客人数:");
		scanf("%d",&p1->num);
		getchar();
		if(i==m)                                                           //判断是否为最后一人
		{
			p1->next=NULL;                                                 //将最后一人的next指针赋值为空指针
			break;                                                         //跳出循环体
		}
		p2=(struct Tour *)malloc(LEN);                               //开辟一个结构体大小的空间并将地址赋给p2
		p1->next=p2;                                                       //将新开辟的链表与之前链表链接起来
		p1=p2; 
	}
	printf("添加成功!\n");                                                
	return p;                                                              
}                                                             
struct Tour * load(FILL *head)
{
	int i;
	char n;
	FILL *fp,*p1=NULL,*p2=NULL;
	char filename[10],*p=filename;
	printf("Please enter load file's name:");
	scanf("%s",p);
	getchar();
	if((fp=fopen(p,"rb"))==NULL)
	{
		printf("Sorry cannot open file!\n");
		return NULL;
	}
	if(fread(&n,sizeof(int),1,fp)!=1)
	{
		printf("Sorry cannot read file!\n");
		return NULL;
	}
	p1=p2=(struct Tour *)malloc(LEN);
	for(i=1;;++i)
	{
		if(fread(p1,sizeof(struct Tour),1,fp)!=1)
		{
			printf("Sorry cannot read file!\n");
			return NULL;
		}
		if(p1->next==NULL)
		{
			head=p1;
			if(i==1)
			{
				p1->next=NULL;break;
			}
			p1->next=p2;break;
		}
		if(i==1)
		{
			p1->next=NULL;
			p1=(struct Tour *)malloc(LEN);
			continue;
		}
		p1->next=p2;
		p2=p1;
		p1=(struct Tour *)malloc(LEN);
	}
	fclose(fp);
	printf("Load Success!\n");
	return head;
}
void list(FILL *head)
{
	int i;
	struct Tour *p1=head;
	if(head==NULL)
	{
		printf("Sorry, nobody to list!\n");
		return;
	}
	for(i=0;;++i)
	{
		printf("\n");
		if(head==NULL)break;
		else 
		{
			printf("团队编号    导游名字    旅游目的地      出发日期     结束日期    游客人数\n");
			printf("  %-8d    ",head->team);
			printf("%-8s    ",head->name);
			printf("%-10s    ",head->mudi);
			printf("%-8s    ",head->statedate);
			printf("%-8s    ",head->overdate);
			printf("  %-8d\n",head->num);
			head=head->next;
		}
		printf("\n");
	}
}
void Search_menu()
{
	printf("           1.团队编号                        2.导游名字\n");
	printf("Please enter your choice:");

}
void Search_name(FILL *head)
{
	int flag=1;
	char Sname[10];
	struct Tour *p;
	if(head==NULL)
	{
		printf("Sorry nobody to search!\n");
		return;
	}
	printf("姓名:");
	scanf("%s",Sname);
	getchar();
	while(head!=NULL)
	{
		if(strcmp(Sname,head->name)==0)
		{
			flag=0;
			p=head->next;
			head->next=NULL;
			list(head);
			head->next=p;
		}
		head=head->next;
	}
	if(flag)
	{
		printf("Sorry, cannot found!\n");
		return;
	}
}
void Search_num(FILL *head)
{
	int flag=1;
	int Sid;
	struct Tour *p;
	if(head==NULL)
	{
		printf("Sorry nobody to search!\n");
		return;
	}
	printf("团队编号:");
	scanf("%d",&Sid);
	getchar();
	while(head!=NULL)
	{
		if(Sid==head->team)
		{
			flag=0;
			p=head->next;
			head->next=NULL;
			list(head);
			head->next=p;
		}
		head=head->next;
	}
	if(flag)
	{
		printf("Sorry, cannot found!\n");
		return;
	}
}
void seach(FILL *head)
{
	void Search_num(FILL *head);
	void Search_name(FILL *head);
	void Search_menu();
	int a;
	if(head==NULL)
	{
		printf("Sorry nobody to search!\n");
		return;
	}
	Search_menu();
	scanf("%d",&a);
	getchar();
	if(a==1)
		Search_num(head);
	if(a==2)
		Search_name(head);
		
}
struct Tour *  del(FILL *head)
{
	FILL *p=head;
	char sel[3],*ch=sel;
	if(head==NULL)
	{
		printf("Sorry nobody to delete!\n");
		return ;
	}
	printf("确定删除该信息(Yes/No)?");
	scanf("%s",ch);
	getchar();
	if(strcmp(ch,"Yes")==0)
	{
		n--;
		if(p1==NULL)
		{
			p=p->next;
		}
		else
		{
			p1->next=head->next;
		}
		free(head);
		printf("删除成功!\n");
		return p;
	}
	else
	{
		return p;
	}
}
void amend(struct Tour *head)
{
	if(head==NULL)
	{
		printf("Sorry nobody to amend!\n");
		return;
	}
	printf("\n团队编号:");
		scanf("%d",&head->team);
		printf("\n导游名字:");
		scanf("%s",head->name);
		printf("\n旅游目的地:");
		scanf("%s",head->mudi);
		printf("\n出发日期:");
		scanf("%s",head->statedate);
		printf("\n结束日期:");
		scanf("%s",head->overdate);
		printf("\n游客人数:");
		scanf("%d",&head->num);
		getchar();
}
void save(struct Tour *head)
{
	char n;
	FILE *fp=NULL;
	char filename[10],*p=filename;
	if(head==NULL)
	{
		printf("Sorry nobody to save!\n");
		return;
	}
	printf("Please enter save file's name:");
	scanf("%s",p);
	getchar();
	if((fp=fopen(p,"wb"))==NULL)
	{
		printf("Sorry cannot open file!\n");
		return;
	}
	if((fwrite(&n,sizeof(int),1,fp))!=1)
	{
		printf("file write error!\n");
		return;
	}
	while(head!=NULL)
	{
		if((fwrite(head,sizeof(struct Tour),1,fp))!=1)
		{
			printf("file write error!\n");
			fclose(fp);
			return;
		}
		head=head->next;
	}
	printf("Save Success!\n");
	fclose(fp);
}
int main()
{
	   char  d;	
		while (1)
		{
			file();/* 显示菜单，并读取用户输入 */
			scanf("%c",&d);
			getchar();
			switch (d)
			{
				case'1':head=add(head);break;   //读取
	            case'2':head=load(head);break;    //添加
	            case'3':list(head);break;   //列表
	            case'4':seach(head);break;  //查找
	            case'5':head=del(head);break;    //删除
	            case'6':amend(head);break;  //修改
	            case'7':save(head);break;   //保存
	            case'0':exit(0);printf("End of program!");break;   //退出
				default:printf("Input error!");break;
			}
		}
}