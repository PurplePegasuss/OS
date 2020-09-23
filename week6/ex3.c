#include <stdio.h>
/*
I've tested the same values on different types of algorithms & different quantums.
First, let's see obtained results:
Uchanged expression:

N = 4
№ AT BT
0 0  3   
1 0  1
2 4  5
3 5  1

FSFC Algo:
P№      AT      BT      CT      TT      WT                                                                                                                                     
0       0       3       3       3       0                                                                                                                                      
1       0       1       4       4       3                                                                                                                                      
2       4       5       9       5       0                                                                                                                                      
3       5       1       10      5       4                                                                                                                                      
Average turnaround: 4.250000                                                                                                                                                   
Average waiting: 1.750000

SJF:
P№      AT      BT      CT      TT      WT                                                                                                                                     
1       0       1       1       1       0                                                                                                                                      
0       0       3       4       4       1                                                                                                                                      
2       4       5       9       5       0                                                                                                                                      
3       5       1       10      5       4                                                                                                                                      
Average turnaround: 3.750000                                                                                                                                                   
Average waiting: 1.250000

Round Robin(Quantum = 1):
P№      AT      BT      CT      TT      WT                                                                                                                                     
1       0       1       2       2       1                                                                                                                                      
0       0       3       4       4       1                                                                                                                                      
3       5       1       6       1       0                                                                                                                                      
2       4       5       10      6       1                                                                                                                                      
Average turnaround: 3.250000                                                                                                                                                   
Average waiting: 0.750000

Round Robin(Quantum = 2):
P№      AT      BT      CT      TT      WT                                                                                                                                     
1       0       1       3       3       2                                                                                                                                      
0       0       3       4       4       1                                                                                                                                      
3       5       1       7       2       1                                                                                                                                      
2       4       5       10      6       1                                                                                                                                      
Average turnaround: 3.750000                                                                                                                                                   
Average waiting: 1.250000

Round Robin(Quantum = 3):
P№      AT      BT      CT      TT      WT                                                                                                                                     
0       0       3       3       3       0                                                                                                                                      
1       0       1       4       4       3                                                                                                                                      
3       5       1       8       3       2                                                                                                                                      
2       4       5       10      6       1                                                                                                                                      
Average turnaround: 4.000000                                                                                                                                                   
Average waiting: 1.500000

Round Robin(Quantum = 4):
P№      AT      BT      CT      TT      WT                                                                                                                                     
0       0       3       3       3       0                                                                                                                                      
1       0       1       4       4       3                                                                                                                                      
3       5       1       9       4       3                                                                                                                                      
2       4       5       10      6       1                                                                                                                                      
Average turnaround: 4.250000                                                                                                                                                   
Average waiting: 1.750000

Since my initial values contain most fast and short processes with a large difference between arrival times,
Round Robin with a small quantum is optimal for this algorithm. SJF and FSFC showed poor results due to an
unbalanced arrangement of high burst and low burst tasks. If you take more balanced burst values, they are
likely to be more effective. Thus, each algorithm is unique and suitable for a specific task. Round Robin
is attractive for me because the user can analyze the data and choose the appropriate quantum.

*/
int main()
{

    int n,arrival_times[50],burst_times[50]; // scanned from user
    int completed_times[50],turnaround_times[50],waiting_times[50]; // needs to be computed
    int add_burst_times[50]; // the array to dynamically change remaining burst values

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
        add_burst_times[i] = burst_times[i];
    };

    int quantum;
    printf("Enter quantum for all processes:\n");
    scanf("%d",&quantum);

    int counter = 0; // variable to check if all processes are done
    int s = 0; // completed time variable
    int flag = 0; // flag to see if the process was used previously, but hasn't had enough time to end his work in single quantum
    
    printf("P№\tAT\tBT\tCT\tTT\tWT\n");
    /*
    My idea is to change the amount of left burst values in the copy of the burst array.
    Hence, we should observe the case then burst time is less than a quantum, and than
    it's bigger than a quantum. 
    */ 
    for (int i=0;;){
        if (add_burst_times[i] <= quantum){ // if the burst time is less than quantum, we add time spent on ex. of that quantum and set the flag active;
            if (add_burst_times[i] != 0){
                flag = 1;
                s+= add_burst_times[i];
                add_burst_times[i] = 0;
            }
        }else if (add_burst_times[i] != 0){ //if the burst time is bigger than quantum, we add time spent on ex. of that quantum and decrease the amount of left burst in copy of the array
            s+= quantum;
            add_burst_times[i]-= quantum;
        }
        if ((add_burst_times[i] == 0)&&(flag == 1)){
            flag = 0;
            counter++;
            completed_times[i]=s;
            /*
            All formulas used below:
            TAT = CT - AT
            WT = TAT - BT
            AVGTAT = SUM_TAT / N
            AVGWAIT = SUM_WAIT / N
            */
            turnaround_times[i]=completed_times[i] - arrival_times[i];
            avg_turnaround+=turnaround_times[i];
            waiting_times[i]= turnaround_times[i] - burst_times[i];
            avg_waiting+=waiting_times[i];
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,arrival_times[i],burst_times[i],completed_times[i],turnaround_times[i],waiting_times[i]);
        }

        if (counter == n) break; // condition to check if all processes are done with its work
            
		if((arrival_times[i+1] <= s)&&(i+1 != n)){ // conditions to change i values in a "greedy" way.
		    i++;
		} else {
		    i=0;
		}
    }

    double avgt = avg_turnaround/n;
    double avgw = avg_waiting/n;
    printf("Average turnaround: %f\nAverage waiting: %f", avgt, avgw);
}
