#include<stdio.h>
int Arrival_Time_1[20],Arrival_Time_2[20];
int Burst_Time_1[20],Burst_Time_2[20],Burst_Time_3[20];
int Priority_2[20],Process_2[20],Arrival_Time_3[20];
int Total=0,t1=0,t2=0,t3=0;
int n,i,at[20],bt[20],pr[20],j=0,k=0,l=0;

int Total,m,Temp[20],Count=0;
float Avg_Waiting_Time_1=0.0,Avg_Turn_Around_Time_1=0.0;

int p,Waiting_Time_3[20],Turn_Around_Time_3[20];
float Avg_Waiting_Time_3=0.0,Avg_Turn_Around_Time_3=0.0;

int Position,q,Temp1,sum=0,Waiting_Time_2[20],Turn_Around_Time_2[20];
float Avg_Waiting_Time_2,Avg_Turn_Around_Time_2=0.0;




int main()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@                                 NAME= KM.SONALI SAHU                                              @@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@                                 SECTION= K18AP                                                    @@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@                                 REG. NO.= 1105237                                                 @@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@                                 PROJECT= MULTILEVEL QUEUE                                         @@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@                                 SUBMMITED TO= DR.BALJIT SINGH SAINI                               @@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("Enter the total number of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time =");
		scanf("%d",&at[i]);
		printf("Burst Time =");
		scanf("%d",&bt[i]);
		printf("enter the priority =");
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\nProcess[%d] having  Queue 1\n",i+1);
			Arrival_Time_1[j]=at[i];
			Burst_Time_1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] having Queue 2\n",i+1);
			Arrival_Time_2[k]=at[i];
			Burst_Time_2[k]=bt[i];
			Priority_2[k]=pr[i];
			Process_2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] having Queue 3\n\n\n\n",i+1);
			Arrival_Time_3[l]=at[i];
			Burst_Time_3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	
	
	Round_Robin_4();
	First_Come_First_Serve();
	Queue_Priority();
	
	return 0;
}
