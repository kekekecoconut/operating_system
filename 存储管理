/
//  main.c
//  dzyyx
//
//  Created by 帅可 on 2019/12/6.
//  Copyright © 2019 uu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int temp[320];
int count=0;

struct block
{
    int pageNum;//页号
    int al_time; //记录页多久没有被访问，用于opt置换
    
}blocks[4]={{0,0},{0,0},{0,0},{0,0}};


void FIFO()
{
    printf("FIFO算法计算如下：\n");
    int i=0,j=0,kf=0;
    for(j=0;j<4;j++)
    {
        blocks[j].pageNum=temp[j]/10;
    }
    printf("当前块内信息为：\n");
    printf("第一块：%d\n",blocks[0].pageNum);
    printf("第二块：%d\n",blocks[1].pageNum);
    printf("第三块：%d\n",blocks[2].pageNum);
    printf("第四块：%d\n",blocks[3].pageNum);
    for(i=4;i<320;i++)
    {
        int a=temp[i]/10;
        if(searchInBlock(a)!=0)
        {
            blocks[kf%4].pageNum = a;
            kf++;
            printf("当前块内信息为：\n");
            printf("第一块：%d\n",blocks[0].pageNum);
            printf("第二块：%d\n",blocks[1].pageNum);
            printf("第三块：%d\n",blocks[2].pageNum);
            printf("第四块：%d\n",blocks[3].pageNum);
        }
        else{
            printf("当前块内信息为：\n");
            printf("第一块：%d\n",blocks[0].pageNum);
            printf("第二块：%d\n",blocks[1].pageNum);
            printf("第三块：%d\n",blocks[2].pageNum);
            printf("第四块：%d\n",blocks[3].pageNum);
        }
    }
    double mm=(double)kf/320;
    printf("LRU置换算法的命中率为：%lf\n",1-mm);
}


int searchMaxAl()
{
    int i,max,maxal;
    max=blocks[0].al_time;
    maxal=0;
    for(i=0;i<4;i++)
    {
        if(blocks[i].al_time>max)
        {
            maxal=i;
            max=blocks[i].al_time;
        }
    }
    return maxal;
}

void add(int a,int max)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(blocks[i].pageNum==a)
        {
            blocks[i].al_time=0;
        }
        else{
        if(i==max)
        {
            blocks[i].al_time=0;
        }
        else
        {
            blocks[i].al_time++;
        }
    }
    }
    for(i=0;i<4;i++)
    {
        printf("每个块的当前多久没有访问值为%d\n",blocks[i].al_time);
    }
}

void add_cf(int a)
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(blocks[i].pageNum==a)
        {
            blocks[i].al_time=0;
        }
        else{
            blocks[i].al_time++;
        }
    }
    for(i=0;i<4;i++)
    {
        printf("每个块的当前多久没有访问值为%d\n",blocks[i].al_time);
    }
}

int searchInBlock(int pageNum)
{
    int i,flag = 0;
    for(i=0;i<4;i++)
    {
        if(pageNum == blocks[i].pageNum) //页号和块内页号相同
        {
            flag=0;
            break;
        }
        else{
           // blocks[i].al_time++;
            flag++;
        }
    }
    return flag;
}



void LRU()
{
    int i=0,j=0;
    printf("LRU算法计算如下：\n");
    for(j=0;j<4;j++)
    {
        blocks[j].pageNum=temp[j]/10;
        blocks[j].al_time=0;
    }
    for(i=0;i<4;i++)
    {
        printf("每个块的当前多久没有访问值为%d\n",blocks[i].al_time);
    }
    printf("当前块内信息为：\n");
    printf("第一块：%d\n",blocks[0].pageNum);
    printf("第二块：%d\n",blocks[1].pageNum);
    printf("第三块：%d\n",blocks[2].pageNum);
    printf("第四块：%d\n",blocks[3].pageNum);
    for(i=4;i<320;i++)
    {
        int a=temp[i]/10;
        if(searchInBlock(a)!=0)
        {
            int max=searchMaxAl();
            //printf("max=%d",max);
            add(a,max);
            blocks[max].pageNum=a;
            blocks[max].al_time=0;
            printf("当前块内信息为：\n");
            printf("第一块：%d\n",blocks[0].pageNum);
            printf("第二块：%d\n",blocks[1].pageNum);
            printf("第三块：%d\n",blocks[2].pageNum);
            printf("第四块：%d\n",blocks[3].pageNum);
            count++;
        }
        else{
            add_cf(a);
            printf("当前块内信息为：\n");
            printf("第一块：%d\n",blocks[0].pageNum);
            printf("第二块：%d\n",blocks[1].pageNum);
            printf("第三块：%d\n",blocks[2].pageNum);
            printf("第四块：%d\n",blocks[3].pageNum);
        }
    }
    double k=(double)count/320;
    printf("LRU置换算法的命中率为：%lf\n",1-k);
}



void cssjs()
{
    int m=0,i=0,m1=0,m2=0;
    for(i=1;i<=320;i=i+4)
    {
        m = rand() % 319 + 0;
        printf("%d.正在执行第%d条指令\n",i,m+1);
        temp[i-1]=m+1;
        m1=rand()%(m+1)+0;
        printf("%d.正在执行第%d条指令\n",i+1,m1);
        temp[i]=m1;
        printf("%d.正在执行第%d条指令\n",i+2,m1+1);
        temp[i+1]=m1+1;
        m2=m1+2;
        temp[i+2]=rand()%(319-m2) + m2;
        printf("%d.正在执行第%d条指令\n",i+3,temp[i+2]);
    };
}

int main(int argc, const char * argv[]) {
    int sc;
    cssjs();
    printf("请输入你所想要选择的页面置换算法：1.FIFO 2.LRU\n");
    scanf("%d",&sc);
    switch (sc) {
        case 1:
            FIFO();
            break;
        case 2:
            LRU();
            break;
        default:
            break;
    }
    return 0;
}
