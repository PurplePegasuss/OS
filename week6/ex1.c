#include <stdio.h>

int main()
{

    int n,arrival_times[50],burst_times[50]; // scanned from user
    int completed_times[50],turnaround_times[50],waiting_times[50]; // needs to be computed
    double avg_turnaround = 0, avg_waiting = 0;
    
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    
    printf("Enter Arrival Time for each of N processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arrival_times[i]);
    }
    
    printf("Enter Burst Time for each of N processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&burst_times[i]);
    }
    
    int s = arrival_times[0];

    /*
    As we assume that arrivals are sorted in correct order,
    we just calculate completed time of each process.
    */

    for (int i = 0; i < n;i++){
        s=s+burst_times[i];
        completed_times[i]=s;
    }

    /*
    All formulas used below:
    TAT = CT - AT
    WT = TAT - BT
    AVGTAT = SUM_TAT / N
    AVGWAIT = SUM_WAIT / N
    */

    for (int i = 0; i < n;i++){
        turnaround_times[i]=completed_times[i] - arrival_times[i];
        avg_turnaround+=turnaround_times[i];
        waiting_times[i]= turnaround_times[i] - burst_times[i];
        avg_waiting+=waiting_times[i];
    }
    printf("P№\tAT\tBT\tCT\tTT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,arrival_times[i],burst_times[i],completed_times[i],turnaround_times[i],waiting_times[i]);
    }
    double avgt = avg_turnaround/n;
    double avgw = avg_waiting/n;
    printf("Average turnaround: %f\nAverage waiting: %f", avgt, avgw);
}
