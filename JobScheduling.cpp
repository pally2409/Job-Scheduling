#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct Schedule
{
	char Name[15];
	char Position[15];
	int pr;
	struct Schedule* link;
}*FRONT=NULL;

struct ele
{
	char jobpos[15]={'\0'};
	int interviewtime;
	int priority;
}sched[10];


int getPriority(char A[],int n)
{
	int i,pr;
	for(i=0;i<n;i++)
	{
		if(strcmp(A,sched[i].jobpos)==0)
		{
			pr=i;
		}
	}
	
	return pr;
}


void insert(int n)
{
	struct Schedule* temp,*ptr;
	char job[15]={'/0'};
	int tempPriority=0,i;
	ptr=FRONT;
	temp=(struct Schedule*)malloc(sizeof(struct Schedule));
	printf("\nEnter the name of the interviewee:");
	scanf("%s",temp->Name);
	printf("\nEnter the position to apply:");
	scanf("%s",temp->Position);
//	strcpy(temp->Position,job);
     for(i=0;i<n;i++)
	{
		if(strcmp(temp->Position,sched[i].jobpos)==0)
		{
			tempPriority=i;
		}
	}
//	tempPriority=getPriority(job,n);
    temp->pr=tempPriority;
    
	if(FRONT==NULL||tempPriority>FRONT->pr)
	{
		temp->link=FRONT;
		FRONT=temp;
	}
	else
	{
	    while(ptr->link!=NULL&&ptr->link->pr>=tempPriority)
	    {
	      ptr=ptr->link;
		  temp->link=ptr->link;
		  ptr->link=temp;
		  
	    }	
    }
}

void interviewtime()
{
	struct Schedule* temp;
	if(FRONT==NULL)
	{
		printf("\nNo scheduled interviews.");
	}
	else
	{
		temp=FRONT;
		printf("\n%s please proceed for your interview.",temp->Name);
		FRONT=FRONT->link;
	}
	
	free(temp);
}



void Display()
{
	struct Schedule* ptr;
	int i=1;
	ptr=FRONT;
	if(FRONT==NULL)
	{
		printf("\nNo scheduled interviews.");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n%d. %s for %s",i,ptr->Name,ptr->Position);
			ptr=ptr->link;
			i++;
		}
	}
}






main()
{
	int n,i,max,j,x,ch,a;
	struct ele temp;
	/*printf("\nEnter the number of vacant job positions:");
	scanf("%d",&n);
	printf("\nEnter the vacant job positions:");
	for(i=0;i<n;i++)
	{
		printf("\n%d:",i);
		scanf("%s",jobpos[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n%s",i,jobpos[i]);
	}
	printf("\nEnter the respective interview time for each job:");
	for(i=0;i<n;i++)
	{
		printf
	} */
	
	printf("\nEnter the number of vacant job positions:");
	scanf("%d",&n);
	printf("\nEnter the vacant job positions and duration scheduled for respective interview:");
	for(i=0;i<n;i++)
	{
		printf("\n%d: ",i+1);
		scanf("%s",sched[i].jobpos);
		printf("%s",sched[i].jobpos);
		printf("\nDuration for %s interview(in minutes):",sched[i].jobpos);
		scanf("%d",&sched[i].interviewtime);
	}
	

	for(i=0;i<n;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(sched[j].interviewtime>sched[max].interviewtime)
			{
				max=j;
			}
		}
		
		temp=sched[i];
		sched[i]=sched[max];
		sched[max]=temp;
	}
	for(i=0;i<n;i++)
	{
		sched[i].priority=i;
	}
		for(i=0;i<n;i++)
	         {
               printf("\n %d",i+1);
               printf(": %s",sched[i].jobpos);
               printf(": %d",sched[i].interviewtime);
               printf(": %d",sched[i].priority);
	         } 
	while(1)
	{
	printf("\nEnter the operation you'd like to perform");
	printf("\n1.For scheduling a new interview.\n2.For sending in the next candidate.\n3.For display the scheduled interviews.");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: insert(n);
		break;
		case 2:interviewtime();
		break;
		case 3: Display();
		break;
		
	}
    }
//	x=getPriority("Manager",n);
//	printf("\n%d",x);

}
