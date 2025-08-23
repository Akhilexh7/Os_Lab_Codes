#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of processes: ";
    cin>>n;
    int Burst_time[n];
    int Waiting[n];
    int TurnAround[n];
    int p[n];
    vector<int> pri(n);
    for(int i = 0 ; i <n ; i++){
        p[i] = i+1;
        
    }
    

    for(int i = 0; i<n ; i++){
        cout<<"Enter Burst Time for "<< p[i] <<"th process "<<endl;
        cin>>Burst_time[i];
        cout<<"Enter priority for "<< p[i] <<"th process"<<endl;
        cin>>pri[i];
    }

    cout<<"Pri   "<<"P   "<<"B    " << "W    " <<"T  "<<endl ;
    Waiting[0] = 0;

    reverse(pri.begin() , pri.end());
    //sort of waiting time
    int cnt = 0;
    for(int i = 0 ; i<n ; i++){

        for(int j = i+1 ;j<n ; j++){
            if(pri[i]>pri[j]){
                cnt++;
                int temp = Burst_time[i];
                Burst_time[i] = Burst_time[j];
                Burst_time[j] = temp; 

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                
            }
        }
    }

    TurnAround[0] = Burst_time[0];
    cout<<pri[0]<<"    "<<p[0]<<"    "<< Burst_time[0] <<"    "<< Waiting[0] << "    "<<TurnAround[0]  <<endl;

     for(int i = 1 ; i<n ; i++){
        Waiting[i] = Waiting[i-1] + Burst_time[i-1];
        TurnAround[i] = Waiting[i] + Burst_time[i];
        cout<<pri[i]<<"    "<<p[i]<<"    "<< Burst_time[i] <<"    "<< Waiting[i] <<"    "<<TurnAround[i]  <<endl;
    }

    // cout<<cnt;

}