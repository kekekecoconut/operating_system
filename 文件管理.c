//
//  main.c
//  dzyyx
//
//  Created by 帅可 on 2019/12/6.
//  Copyright © 2019 uu. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN sizeof(struct documents)

//using namespace std;

int count=0;
int fla=0;
int logined_user=-2;
int state_n=-1;

//用户名和密码
typedef struct Users
{
    char username[10]; //用户名
    char password[20]; //密码
}Users;

//文件结构
struct documents
{
    long int address;
    char name[10];
    //int pwd; //文件保护码
    int length; //文件长度
    char content[20]; //文件内容
    int wr_flag;//只读为0，读写为1
    int state; //读写状态位，读为1，写为-1
    int isopen;//打开标志位，打开为1，未打开为0
    struct documents *next;
};

//用户目录
typedef struct user_file_Directory
{
    struct documents *doc;
    struct user_file_Directory *next;
}UFD;

//主文件目录
typedef struct master_file_Diretory
{
    UFD *user;
    Users member;
}MFD;

MFD user[100];

void create_user(); //创建用户包括创建用户和创建用户目录
int user_login(); //用户登录
void user_logout(); // 用户注销
void create_file(char a[],int fl); //创建文件
void delete_doc(char a[],int fl); //删除文件
void open_doc(int fl,char a[]); //打开文件
void close_doc(int fl,char a[]); //关闭文件
void read_doc(int fl,char a[]); //读文件
void write_doc(int fl,char a[]); //写文件
//void master_mkdir();
void user_mkdir(int fl); //列用户目录文件列表
void first();
void select_or(char order[50],int fl);
void exit_1()
{
    logined_user=-2;
    printf("注销成功！\n");
    first();
}
void first()
{
    while(1)
    {
        if((logined_user!=-1) && (logined_user!=-2))
        {
        printf("********************************************\n");
        printf("                  1、注销\n");
        printf("                  2、进入目录中\n");
        printf("********************************************\n");
        int k;
        printf("请输入你的选项：");
        scanf("%d",&k);
        switch (k) {
            case 1:
                exit_1();
                break;
            default:
                break;
        }
        if(k!=1)
        {
            break;
        }
        }
        else{
            printf("********************************************\n");
            printf("                  1、创建用户\n");
            printf("                  2、登录\n");
            printf("********************************************\n");
            int n;
            printf("请输入你的选项：");
            scanf("%d",&n);
            switch (n) {
                case 1:
                    create_user();
                    break;
                case 2:
                    while(1)
                    {
                        logined_user=user_login();
                        if(logined_user!=-1)
                        {
                            break;
                        }
                    }
                default:
                    break;
            }
            if((n!=1)&&(n!=2))
            {
                break;
            }
        }
    }
}


int main()
{
    first();
    for(int i=0;i<100;i++)          //初始化用户UFD目录文件的头指针
    {
        user[i].user=(UFD *)malloc(sizeof(UFD));
        user[i].user->next=NULL;
    }
    while(1)
    {
        printf("%s:/>",user[logined_user].member.username);
        char order[100];
        gets(order);
        std::cin.get(order,100);
        select_or(order, logined_user);
        if(state_n==0)
        {
            break;
        }
    }
    return 0;
}



void select_or(char order[50],int fl)
{
    if(strncmp(order,"create",6)==0)
    {
        create_file(order, fl);
    }
    else{
        if(strncmp(order,"read",4)==0)
        {
            read_doc(fl, order);
        }
        else{
            if(strncmp(order,"write",5)==0)
            {
                write_doc(fl,order);
            }
            else
            {
                if(strncmp(order,"del",3)==0)
                {
                    delete_doc(order, fl);
                }
                else{
                    if(strncmp(order,"mkdir",5)==0)
                    {
                        user_mkdir(fl);
                    }
                    else{
                        if(strncmp(order,"close",5)==0)
                        {
                            close_doc(fl, order);
                        }
                        else{
                            if(strncmp(order,"open",4)==0)
                            {
                                open_doc(fl, order);
                            }
                            else{
                                if(strncmp(order,"cd",2)==0)
                                {
                                    exit_1();
                                }
                                else{
                                    state_n=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void create_user()
{
    char username[10];
    char password[15];
    printf("请输入用户名：");
    scanf("%s",username);
    printf("请输入密码：");
    scanf("%s",password);
    if(fla<100)
    {
        strcpy(user[fla].member.username,username);
        strcpy(user[fla].member.password,password);
        fla++;
        printf("创建成功！\n");
    }
    else{
        printf("用户数量已经达到可创建数量上限！\n");
    }
}

int user_login()
{
    char username[10];
    char password[15];
    int flag=0;
    printf("请输入用户名：");
    scanf("%s",username);
    printf("请输入密码：");
    scanf("%s",password);
    int i=0;
    for(i=0;i<fla;i++)
    {
        if(strcmp(password,user[i].member.password)==0 
          && strcmp(username,user[i].member.username)==0)
        {
            printf("登录成功！\n");
            flag=i;
            break;
        }
        else{
            flag=-1;
        }
    }
    if(flag==-1)
    {
        printf("用户名或者密码错误，请核实后再试！\n");
    }
    return flag;
}

void create_file(char a[],int fl)
{
    int len=(int)strlen(a),i=0,j=0,flag=0,ks=0;
    char name[10];
    char content[50];
    for(i=7;i<len;i++)
    {
        if(a[i]!=' ')
        {
            name[ks]=a[i];
            ks++;
            flag=i;
        }
        else{
            break;
        }
    }
    name[ks]='\0';
    ks=0;
    for(j=flag+2;j<len;j++)
    {
        content[ks]=a[j];
        ks++;
    }
    content[ks]='\0';
   // printf("%s\n",content);
    UFD *docNode,*p;
    docNode=(UFD *)malloc(sizeof(UFD));
    docNode->doc=(documents *)malloc(sizeof(documents));
    docNode->doc->isopen=0;
    docNode->doc->state=0;
    docNode->doc->address=count;
    docNode->doc->length=(int)strlen(content);
    count=count+docNode->doc->length;
    strcpy(docNode->doc->content,content);
    strcpy(docNode->doc->name,name);
    srand(time(0));
    docNode->doc->wr_flag=(rand()%100)%2;
    docNode->next=NULL;
    if(user[fl].user->next==NULL)
    {
        user[fl].user->next=docNode;
    }
    else{
        p=user[fl].user->next;
        while(p->next)
        {
            p=p->next;
        }
        p->next=docNode;
    }
    printf("创建文件成功！\n");
}

void delete_doc(char a[],int fl)
{
    int len=(int)strlen(a),i=0,kk=0;
    char name[10];
    for(i=7;i<len;i++)
    {
        if(a[i]!=' ')
        {
            name[kk]=a[i];
            kk++;
        }
    }
    name[kk]='\0';
    UFD *q,*p,*temp,*m;
    q=user[fl].user;
    p=q->next;
    while(p)
    {
        if(!strcmp(p->doc->name,name))
            break;
        else{
            p=p->next;
            q=q->next;
        }
    }
    if(p)
    {
        if(p->doc->isopen==0) //没打开
        {
            //count = count - p->doc->length;
            m=p->next;
            int lent=p->doc->length;
            while(m)
            {
                m->doc->address=m->doc->address-lent;
                m=m->next;
            }
            count = count - p->doc->length;
            temp=p;
            q->next=p->next;
            free(temp);
            printf("文件删除成功！\n");
        }
        else{
            printf("文件删除失败，请将该文件关闭后重试！\n");
        }
    }
    else{
        printf("没有找到该文件，请重新核对文件名称！\n");
    }
}

void open_doc(int fl,char a[])
{
    int len=(int)strlen(a),i=0,kk=0;
    char name[10];
    for(i=5;i<len;i++)
    {
        if(a[i]!=' ')
        {
            name[kk]=a[i];
            kk++;
        }
    }
    name[kk]='\0';
    UFD *p;
    p=user[fl].user->next;
    while(p)
    {
        if(strcmp(p->doc->name,name)==0)
        {
            if(p->doc->isopen==1)
            {
                printf("文件已经打开，请不要重复打开！\n");
                break;
            }
            else{
                p->doc->isopen=1;
                printf("文件打开成功！\n");
                break;
            }
        }
        else{
            p=p->next;
        }
    }
    if(p==NULL)
    {
        printf("没有找到该文件，请重新核对文件名称！\n");
    }
}

void close_doc(int fl,char a[])
{
    int len=(int)strlen(a),i=0,kk=0;
    char name[10];
    for(i=5;i<len;i++)
    {
        if(a[i]!=' ')
        {
            name[kk]=a[i];
            kk++;
        }
    }
    name[kk]='\0';
    UFD *p;
    p=user[fl].user->next;
    while(p)
    {
        if(strcmp(p->doc->name,name)==0)
        {
            if(p->doc->isopen==0)
            {
                printf("文件已经关闭，请不要重复打开！\n");
                break;
            }
            else{
                p->doc->isopen=0;
                p->doc->state=0;
                printf("文件关闭成功！\n");
                break;
            }
        }
        else{
            p=p->next;
        }
    }
    if(p==NULL)
    {
        printf("没有找到该文件，请重新核对文件名称！\n");
    }
}

void read_doc(int fl,char a[])
{
    int len=(int)strlen(a),i=0,kk=0;
    char name[10];
    for(i=5;i<len;i++)
    {
        if(a[i]!='0')
        {
            name[kk]=a[i];
            kk++;
        }
    }
    name[kk]='\0';
    UFD *p;
    p=user[fl].user->next;
    while(p)
    {
        if(strcmp(p->doc->name,name)==0)
        {
            if(p->doc->wr_flag==1)
            {
                printf("此文件禁止读和写！\n");
                break;
            }
            else{
                if(p->doc->isopen==1) //处于打开状态
                {
                    p->doc->state=1;
                    printf("文件内容是：");
                    printf("%s\n",p->doc->content);
                    break;
                }
                else{
                    open_doc(fl, a);
                    read_doc(fl,a);
                    break;
                }
            }
        }
        else{
            p=p->next;
        }
    }
    if(p==NULL)
    {
        printf("没有找到该文件，请重新核对文件名称！\n");
    }
}

void write_doc(int fl,char a[])
{
    int len=(int)strlen(a),i=0,j=0,flag=0,ks=0;
    char name[10];
    char content[50];
    for(i=6;i<len;i++)
    {
        if(a[i]!=' ')
        {
            name[ks]=a[i];
            ks++;
            flag=i;
        }
        else{
            break;
        }
    }
    name[ks]='\0';
    ks=0;
    for(j=flag+2;j<len;j++)
    {
        content[ks]=a[j];
        ks++;
    }
    content[ks]='\0';
    //printf("%s\n",name);
    UFD *p;
    p=user[fl].user->next;
    while(p)
    {
        if(strcmp(p->doc->name,name)==0)
        {
            if(p->doc->wr_flag==1)
            {
                printf("此文件禁止读和写！\n");
                break;
            }
            else{
                if(p->doc->isopen==1) //处于打开状态
                {
                    if(p->doc->state==1)
                    {
                        printf("此文件正在被读中，请关闭后再试！\n");
                        break;
                    }
                    else{
                        strcpy(p->doc->content,content);
                        printf("文件写入文件成功！\n");
                        break;
                    }
                }
                else{
                    //open_doc(fl,a);
                    p->doc->isopen=1;
                    printf("文件已打开！\n");
                    write_doc(fl,a);
                    break;
                }
            }
        }
        else{
            p=p->next;
        }
    }
    if(p==NULL)
    {
        printf("没有找到该文件，请重新核对文件名称！\n");
    }
}

void user_mkdir(int fl)
{
    printf("/<%s>\n",user[fl].member.username);
    UFD *p;
    p=user[fl].user->next;
    printf("*************************************************\n");
    printf("文件名         物理地址      保护码     文件长度\n");
    for(;p!=NULL;p=p->next)
    {
        printf("%s %ld %d %d\n",p->doc->name,、p->doc->address,p->doc->wr_flag,p->doc->length);
    }
    printf("***************************************\n");
}
