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
		printf(" 1.��� 	record\n");
		printf(" 2.��ȡ    	record\n");
		printf(" 3.�б�  	record\n");
		printf(" 4.����    	record\n");
		printf(" 5.ɾ��  	record\n");
		printf(" 6.�޸�    	record\n");
		printf(" 7.����    	record\n");
		printf(" 0.�˳�\n");
		printf("�������ѡ��");
}
struct Tour * add(struct Tour *head)
{
	
	int m,i,flag;                                                               //�������ͱ���m,i
	char sel[3],*ch1=sel;                                                  //�����ַ����飬�ַ�ָ��
	struct Tour *p,*p1,*p2;                                          //����ṹ��ָ��p,p1,p2
	p1=p2=(struct Tour *)malloc(LEN);                                //����һ���ṹ���С�Ŀռ䲢�ѵ�ַ��p1��p2
	if(head==NULL)                                                         //�ж��Ƿ��м�������
	{
		p=p1;                                                              //��¼����ͷ
	}
	else
	{
		printf("�Ƿ�Ҫ��ԭ�������ϼ������(Yes/No)?");                     //������ʾ�Ƿ�Ҫ��ԭ�����ϼ����������
		scanf("%s",ch1);                                                   //����ѡ��
		getchar();
		if(strcmp(ch1,"Yes")==0)                                           //�ж�ѡ��
		{
			p=head;                                                        //��¼ԭ�����ͷ
			for(i=1;i<n;++i)                                               //ѭ��n��
			{
				head=head->next;                                           //ָ����һ���ṹ��
			}
			head->next=p1;                                                 //����֮�������
		}
		else
		{
			head=NULL;                                                     //���ԭ����ͷ
			p=p1;                                                          //��¼����ͷ
		}
	}
	printf("\n��������ӵ�����:");
	scanf("%d",&m);                                                        //�����������
	getchar();
	for(i=1;i<=m;++i)                                                      //ѭ��m��
	{
		n++;                                                               //���Ӽ�������
		printf("\n�Ŷӱ��:");
		scanf("%d",&p1->team);
		printf("\n��������:");
		scanf("%s",p1->name);
		printf("\n����Ŀ�ĵ�:");
		scanf("%s",p1->mudi);
		printf("\n��������:");
		scanf("%s",p1->statedate);
		printf("\n��������:");
		scanf("%s",p1->overdate);
		printf("\n�ο�����:");
		scanf("%d",&p1->num);
		getchar();
		if(i==m)                                                           //�ж��Ƿ�Ϊ���һ��
		{
			p1->next=NULL;                                                 //�����һ�˵�nextָ�븳ֵΪ��ָ��
			break;                                                         //����ѭ����
		}
		p2=(struct Tour *)malloc(LEN);                               //����һ���ṹ���С�Ŀռ䲢����ַ����p2
		p1->next=p2;                                                       //���¿��ٵ�������֮ǰ������������
		p1=p2; 
	}
	printf("��ӳɹ�!\n");                                                
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
			printf("�Ŷӱ��    ��������    ����Ŀ�ĵ�      ��������     ��������    �ο�����\n");
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
	printf("           1.�Ŷӱ��                        2.��������\n");
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
	printf("����:");
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
	printf("�Ŷӱ��:");
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
	printf("ȷ��ɾ������Ϣ(Yes/No)?");
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
		printf("ɾ���ɹ�!\n");
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
	printf("\n�Ŷӱ��:");
		scanf("%d",&head->team);
		printf("\n��������:");
		scanf("%s",head->name);
		printf("\n����Ŀ�ĵ�:");
		scanf("%s",head->mudi);
		printf("\n��������:");
		scanf("%s",head->statedate);
		printf("\n��������:");
		scanf("%s",head->overdate);
		printf("\n�ο�����:");
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
			file();/* ��ʾ�˵�������ȡ�û����� */
			scanf("%c",&d);
			getchar();
			switch (d)
			{
				case'1':head=add(head);break;   //��ȡ
	            case'2':head=load(head);break;    //���
	            case'3':list(head);break;   //�б�
	            case'4':seach(head);break;  //����
	            case'5':head=del(head);break;    //ɾ��
	            case'6':amend(head);break;  //�޸�
	            case'7':save(head);break;   //����
	            case'0':exit(0);printf("End of program!");break;   //�˳�
				default:printf("Input error!");break;
			}
		}
}