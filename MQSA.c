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


//Round_Robin_4() function for highest priority process using time quantum=4.
void Round_Robin_4()
{
	printf("Time Quantum for Queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		Temp[i]=Burst_Time_1[i];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	m=j;
    for(i=0,Total=0;m!=0;) 
    { 
    	if(Temp[i]<=4&&Temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is using CPU for %d units",i+1,Temp[i]); 
            Total=Total+Temp[i]; 
            Temp[i]=0; 
            Count=1; 
        } 
        else if(Temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is using CPU for 4 units",i+1); 
            Temp[i]=Temp[i]-4; 
            Total=Total+4; 
        } 
        if(Temp[i]==0&&Count==1) 
        { 
            m--; 
            printf("\nProcess[%d]\t%d\t%d\t%d",i+1,Burst_Time_1[i],Total-Arrival_Time_1[i],Total-Arrival_Time_1[i]-Burst_Time_1[i]);
            Avg_Waiting_Time_1=Avg_Waiting_Time_1+Total-Arrival_Time_1[i]-Burst_Time_1[i]; 
            Avg_Turn_Around_Time_1=Avg_Turn_Around_Time_1+Total-Arrival_Time_1[i]; 
            Count = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(Arrival_Time_1[i+1]<=Total) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
}

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
//time quantum between the three queue is 10 unit.
	printf("Time Quantum between the 3 queues is 10\n");
    for(i=1;i<Total;i=i+10)
    {
	    if(t1>10)
	    {
		    printf("Queue1 is using CPU for 10 units\n");
		    t1=t1-10;
	    }
      	else if(t1<=10&&t1!=0)
      	{
	     	printf("Queue1 is using CPU for %d units\n",t1);
		    t1=0;
	    }
	    if(t2>10)
	    {
		    printf("Queue2 is using CPU for 10 units\n");
		    t2=t2-10;
	    }
	    else if(t2<=10&&t2!=0)
     	{
	     	printf("Queue2 is using CPU for %d units\n",t2);
	    	t2=0;
	    }
	    if(t3>10)
	    {
		    printf("Queue3 is using CPU for 10 units\n");
		    t3=t3-10;
	    }
	    else if(t3<=10&&t3!=0)
	    {
		    printf("Queue3 is using CPU for %d units\n",t3);
		    t3=0;
	    }
   }
	
	Round_Robin_4();
	First_Come_First_Serve();
	Queue_Priority();
	
	return 0;
}
