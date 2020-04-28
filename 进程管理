#include <stdio.h>
#include <stdlib.h>

struct PCB{
    int PID; //进程的id
    int runTime; //进程的剩余时间
    int priority;//进程的优先级
    int cpl_flag; //完成标志m，已完成为1，未完成为0
    int arrive_time; //到达时间
    int bb_runtime; //完成所需时间
}process[50],temp,temp2;

int len;

void delete_pcb(int len,int i)
{
    int k=0;
    for(k=i;k<len-1;k++)
    {
        process[k]=process[k+1];
    }
}

void xlxfw(int n)
{
    int i,j,time;
    len=n;
    printf("请输入时间片大小：");
    scanf("%d",&time);
    for(i=0;i<n;i++)
    {
        process[i].cpl_flag=0;
        printf("请输入进程的PID：");
        scanf("%d",&process[i].PID);
        printf("请输入该进程所需的运行时间：");
        scanf("%d",&process[i].runTime);
        process[i].bb_runtime=process[i].runTime;
        printf("请输入该进程的优先级：");
        scanf("%d",&process[i].priority);
    }
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(process[j].priority>process[j+1].priority)
            {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1]=temp;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        printf("进程%d正在运行..\n",process[i].PID);
        printf("进程%d已经完成\n",process[i].PID);
    }
}

void sjp(int n)
{
    int i,j,time;
    len=n;
    printf("请输入时间片大小：");
    scanf("%d",&time);
    for(i=0;i<n;i++)
    {
        process[i].cpl_flag=0;
        printf("请输入进程的PID：");
        scanf("%d",&process[i].PID);
        printf("请输入该进程所需的运行时间：");
        scanf("%d",&process[i].runTime);
        process[i].bb_runtime=process[i].runTime;
        printf("请输入该进程的优先级：");
        scanf("%d",&process[i].priority);
        process[i].arrive_time=i;
    }
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(process[j].priority>process[j+1].priority)
            {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1]=temp;
            }
        }
    }
    
    while(len!=0)
    {
        for(i=0;i<len;i++)
        {
            if(i==0)
            {
                printf("\nPID\t到达时间\t优先级\t已经运行时间\n");
                printf("————————————————————————————\n");
            }
            
            printf(" %d\t\t",process[i].PID);
            printf(" %d\t\t",process[i].arrive_time);
            printf("%d\t\t",process[i].priority);
            printf("%d\t\t",process[i].bb_runtime - process[i].runTime);
            printf("\n");
        }
        for(i=0;i<len;i++)
        {
            
            //printf("%d\t",pr->runTime-pr->workTime);
            printf("\n");
            printf("进程%d正在运行..\n",process[i].PID);
            if(process[i].runTime <= time)
            {
                process[i].cpl_flag=1;
                printf("进程%d已经完成\n",process[i].PID);
                delete_pcb(len,i);
                len--;
                break;
            }
            else
            {
                process[i].runTime=process[i].runTime-time;
                process[len]=process[i];
                len++;
                delete_pcb(len, i);
                len--;
                break;
            }
        }
    }
}

void dtyxj(int n)
{
    int i,j,time;
    len=n;
    printf("请输入时间片大小：");
    scanf("%d",&time);
    for(i=0;i<n;i++)
    {
        process[i].cpl_flag=0;
        printf("请输入进程的PID：");
        scanf("%d",&process[i].PID);
        printf("请输入该进程所需的运行时间：");
        scanf("%d",&process[i].runTime);
        process[i].bb_runtime=process[i].runTime;
//        process[i].priority=rand() % 20;
        printf("请输入该进程的优先级：");
        scanf("%d",&process[i].priority);
        process[i].arrive_time=i;
    }
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(process[j].priority>process[j+1].priority)
            {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1]=temp;
            }
        }
    }
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(process[j].priority>process[j+1].priority)
            {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1]=temp;
            }
        }
    }
    while(len!=0)
    {
        for(i=0;i<len;i++)
        {
            if(i==0)
            {
                printf("\nPID\t到达时间\t优先级\t已经运行时间\n");
                printf("————————————————————————————\n");
            }
            
            printf(" %d\t\t",process[i].PID);
            printf(" %d\t\t",process[i].arrive_time);
            printf("%d\t\t",process[i].priority);
            printf("%d\t\t",process[i].bb_runtime-process[i].runTime);
            printf("\n");
        }
        
        for(i=0;i<len;i++)
        {
            printf("进程%d正在运行..\n",process[i].PID);
            if(process[i].runTime <= time)
            {
                process[i].cpl_flag=1;
                printf("进程%d已经完成\n",process[i].PID);
                delete_pcb(len,i);
                len--;
                break;
            }
            else
            {
                process[i].runTime=process[i].runTime-time;
                process[i].priority=process[i].priority-3;
                for(i=0;i<len-1;i++)
                {
                    for(j=0;j<len-1-i;j++)
                    {
                        if(process[j].priority>process[j+1].priority)
                        {
                            temp = process[j];
                            process[j] = process[j+1];
                            process[j+1]=temp;
                        }
                    }
                }
                break;
            }
        }
    }
    
    
}


int main() {
    int n,choice;
    printf("请输入进程个数：");
    scanf("%d",&n);
    printf("请选择所用算法：1.先来先服务 2.时间片轮转 3.动态优先级\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 2:
            sjp(n);
            break;
        case 1:
            xlxfw(n);
            break;
        case 3:
            dtyxj(n);
            break;
        default:
            break;
    }
    return 0;
}
