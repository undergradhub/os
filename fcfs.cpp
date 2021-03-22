#include<stdio.h>
#include<conio.h>
main()
{
    int n,i,j,bt[10],wt[10],tat[10];
    float avg_wt=0,avg_tat=0;
    // clrscr();
    printf("Name: Dhruvesh Gangapuram\nRoll no. : 09\n");
    printf("Enter total number of processes:");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time\n");

    for(i=0;i<n;i++){
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++){   
        wt[i]=0;
	    for(j=0;j<i;j++)
	        wt[i]+=bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    avg_wt=avg_wt/i;
    avg_tat=avg_tat/i;

    printf("\n\nAverage Waiting Time:%f",avg_wt);
    printf("\nAverage Turnaround Time:%f",avg_tat);

    getch();
    
}
