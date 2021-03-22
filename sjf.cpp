#include <stdio.h>
#include <conio.h>
main()
{
    int n, i, j, temp, pass, bt[10], wt[10], tat[10], indx[10];
    float avwt = 0, avtat = 0;
    // clrscr();
    printf("Name: Dhruvesh Gangapuram\nRoll no. : 09\n");
    printf("Enter total number of processes:");
    scanf("%d", &n);
    printf("\nEnter Process Burst Time\n");
    for (i = 0; i < n; i++){
        printf("P[%d]:", i + 1);
        scanf("%d", &bt[i]);
        indx[i] = i + 1;
    }
    for (pass = 0; pass < n - 1; pass++){
        for (i = 0; i < n - pass - 1; i++){
            if (bt[i] > bt[i + 1]){
                temp = bt[i];
                bt[i] = bt[i + 1];
                bt[i + 1] = temp;
                temp = indx[i];
                indx[i] = indx[i + 1];
                indx[i + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    for (i = 1; i < n; i++){
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", indx[i], bt[i], wt[i], tat[i]);
    }
    avwt = avwt / i;
    avtat = avtat / i;
    printf("\n\nAverage Waiting Time:%f", avwt);
    printf("\nAverage Turnaround Time:%f", avtat);
    getch();
}