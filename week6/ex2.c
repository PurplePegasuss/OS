#include <stdio.h>

int main()
{

    int n,arrival_times[50],burst_times[50]; // scanned from user
    int completed_times[50],turnaround_times[50],waiting_times[50]; // needs to be computed
    int reserved_table[50]; // reserved table - helps to see which processes were already done
    double avg_turnaround = 0, avg_waiting = 0;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    
    printf("Enter Arrival Time for each of N processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arrival_times[i]);
    };
    
    printf("Enter Burst Time for each of N processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&burst_times[i]);
    };
    
    int first_pr = 0; // the index of the next process to be done 

    int min_arrival = arrival_times[0]; // min_arrival - minimum value out of all of the arrival times

    for(int i=1;i<n;i++){ // finding the minimum value out of all of the arrival times
        if (arrival_times[i] < min_arrival){
            min_arrival = arrival_times[i];
            first_pr = i;
        };
    };
    
    int min_burst = burst_times[first_pr];
    
     for(int i=0;i<n;i++){ // finding the minimum value out of arrival times and having the least burst time
        if (min_arrival == arrival_times[i]){
            if (burst_times[i] < min_burst){
                min_burst = burst_times[i];
                first_pr = i;
            }
        };
    };

    //As we have found the first index to be calculated, we can calculate everything for it

    /*
    All formulas used below:
    TAT = CT - AT
    WT = TAT - BT
    AVGTAT = SUM_TAT / N
    AVGWAIT = SUM_WAIT / N
    */

    printf("P№\tAT\tBT\tCT\tTT\tWT\n");
    int s = arrival_times[first_pr];
    s +=  burst_times[first_pr];
    completed_times[first_pr] = s;
    turnaround_times[first_pr]=completed_times[first_pr] - arrival_times[first_pr];
    waiting_times[first_pr]= turnaround_times[first_pr] - burst_times[first_pr];
    avg_turnaround += turnaround_times[first_pr];
    avg_waiting += waiting_times[first_pr];

    for(int i=0;i<n;i++){ // filling the reservation table with zero's
        reserved_table[i] = 0;
    };
    reserved_table[first_pr] = 1;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",first_pr,arrival_times[first_pr],burst_times[first_pr],completed_times[first_pr],turnaround_times[first_pr],waiting_times[first_pr]);
    
    /*
    Basically at that part of the code we just check if arrival time is less that overall time spent,and also check if the processes was done before.
    If everything meets the requirements, search for a minimal burst time out of all candidates. Repeat the same thing untill all processes are done.
    */
    while (min_burst != -1){
        
        min_burst = -1; 
        
        int borderline = completed_times[first_pr];
        for (int i=0;i<n;i++){
            if ((borderline>=arrival_times[i]) && (reserved_table[i] != 1)){
                if (min_burst == -1) {
                    min_burst = burst_times[i];
                    first_pr = i;
                }else 
                if (burst_times[i] < min_burst){
                    min_burst = burst_times[i];
                    first_pr = i;
                }
            }
        }
        
        if (min_burst == -1) break;
        
        s +=  burst_times[first_pr];
        completed_times[first_pr] = s;
        
        turnaround_times[first_pr]=completed_times[first_pr] - arrival_times[first_pr];
        waiting_times[first_pr]= turnaround_times[first_pr] - burst_times[first_pr];
        avg_turnaround += turnaround_times[first_pr];
        avg_waiting += waiting_times[first_pr];
        reserved_table[first_pr] = 1;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",first_pr,arrival_times[first_pr],burst_times[first_pr],completed_times[first_pr],turnaround_times[first_pr],waiting_times[first_pr]);
    }
    double avgt = avg_turnaround/n;
    double avgw = avg_waiting/n;
    printf("Average turnaround: %f\nAverage waiting: %f", avgt, avgw);
}
