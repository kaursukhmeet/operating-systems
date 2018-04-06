/*
Consider a scheduler which schedules the job by considering the arrival time of the
processes where arrival time if given as 0 is discarded or displayed as error. The scheduler
implements the shortest job first scheduling policy, but checks the queue of the processes after
the every process terminates and time taken for checking and arranging the process according to
the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting
time and turnaround time of the processes. Also compute the total time taken by the processor to
compute all the jobs.
The inputs for the number of requirements, arrival time and burst time should be provided by the
user.
Consider the following units for reference.
Process Arrival time Burst Time
1 0 6
2 3 2
3 5 1
4 9 7
5 10 5
6 12 3
7 14 4
8 16 5
9 17 7
10 19 2
Develop a scheduler which submits the processes to the processor in the defined scenario, and
compute the scheduler performance by providing the waiting time for process, turnaround time
for process and average waiting time and turnaround time.
*/

#include<stdio.h>
#include<stdbool.h>
struct Processes
{
	int p_id;
	int b_time,ar_time;
};
void waiting_time_of_process(struct Processes process[],int number_of_p,int waiting_time[])
{
	
	int temp[number_of_p],value=0;
	int time=0,least_burst_time_p=0,executed=0,f_time,min_time_of_execution=5000;
	bool flag=false;
	int x;
	for(x=0;x<number_of_p;x++)
{
	temp[x]=process[x].b_time;
}
	for(x=0;x<number_of_p;x++)
{
	printf("%d\n",temp[x]);
}
	
	while(executed!=number_of_p)
	{
		
		for(x=0;x<number_of_p;x++)
		{
			
			if((process[x].ar_time<=time)&&(temp[x]<min_time_of_execution&&temp[x]>0))
			{
				min_time_of_execution=temp[x];
				least_burst_time_p=x;
				flag=true;
			}
			
		}
		
		if(flag==false)
		{
			time++;
			continue;
		}
		
		value=temp[least_burst_time_p];
		time=time+value;
		temp[least_burst_time_p]=0;
		min_time_of_execution=5000;
		if(temp[least_burst_time_p]==0)
		{
			executed++;
			f_time=time+1;
			waiting_time[least_burst_time_p]=f_time-process[least_burst_time_p].b_time-process[least_burst_time_p].ar_time+2;
			
			
		}
		
		
	}
} 

void turn_around_time_of_process(struct Processes process[],int number_of_p,int waiting_time[],int turn_around_time[])
{
	int a;
	for(a=0;a<number_of_p;a++)
	{
		turn_around_time[a]=process[a].b_time+waiting_time[a];
		 
	}
}





void find_average_A_time(struct Processes process[],int number_of_p)
{
	int waiting_time[number_of_p],turn_around_time[number_of_p];
	int total_waiting_time=0,total_turn_around_time=0;      //int
	
	waiting_time_of_process(process,number_of_p,waiting_time);
	turn_around_time_of_process(process,number_of_p,waiting_time,turn_around_time);
	
	printf("| Processes |\t| Burst time |\t| Waiting time |\t| Turn around time | \n");
	int x;
	for(x=0;x<number_of_p;x++)
	{
		total_waiting_time=total_waiting_time+waiting_time[x];
		total_turn_around_time=total_turn_around_time+turn_around_time[x];
		printf("  %d \t\t%d \t\t%d \t\t%d\n",process[x].p_id,process[x].b_time,waiting_time[x],turn_around_time[x]);
	}
		printf("\nAverage waiting time of processes : %f",(float)total_waiting_time / (float)number_of_p);
    	printf("\nAverage turn around time of processes : %f",(float)total_turn_around_time / (float)number_of_p);
}
int main()
{
	int no_of_processes;
	printf("\n How many processes you want to enter into the CPU ? \n");
	scanf("%d",&no_of_processes);
	struct Processes process[no_of_processes];
	int i=0;
	while(i<no_of_processes)
	{
		//system("cls");
		printf("\nEnter the process ID : ");
		scanf("%d",&process[i].p_id);
		printf("\nEnter the arrival time : ");
		scanf("%d",process[i].ar_time);
		while(process[i].ar_time==0)
		{
			printf("\nEntered process arrival time is wrong. Enter the correct arrival time \nArrival Time : ");
			scanf("%d",process[i].ar_time);
		}
		printf("\nEnter the burst time : ");
		scanf("%d",process[i].b_time);	
		i++;
	}
	find_average_A_time(process,no_of_processes);
	return 0;	
}

