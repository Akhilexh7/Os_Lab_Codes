#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"enter number of processes"<<endl;
    int n; 
    cin >> n;

    int burst[n];
    for(int i = 0; i < n; i++){
        cout<<"enter burst time"<<endl;
        cin >> burst[i];
    }

    cout<<"enter time quantum"<<endl;
    int t; 
    cin >> t;

    int tot_time = 0;
    int tat[n], wt[n], ct[n], temp_bt[n];

    for(int i = 0; i < n; i++){
        temp_bt[i] = burst[i]; 
    }

    int donecnt = 0;

    while(donecnt < n){
        for(int i = 0; i < n; i++){

            if(temp_bt[i] > 0){

                if(temp_bt[i] > t){ // not yet finished
                    tot_time += t;
                    temp_bt[i] -= t;
                }
                else{
                    tot_time += temp_bt[i];
                    temp_bt[i] = 0;

                    ct[i] = tot_time; // to update only we carryying tot time
                    tat[i] = ct[i];                 // FIXED
                    wt[i] = tat[i] - burst[i]; // no bt was harmed

                    donecnt++; // no of process done
                }


            }
        }
    }

    cout << "BT   WT   TAT   CT\n";
    for(int i = 0; i < n; i++){
        cout << burst[i] << "   " << wt[i] << "   " 
             << tat[i] << "   " << ct[i] << endl;
    }
}
