#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of processes: ";
    cin>>n;
    int Burst_time[n];
    int Waiting[n];
    int TurnAround[n];

    for(int i = 0; i<n ; i++){
        cout<<"Enter Burst Time for "<< i+1 <<"th process ";
        cin>>Burst_time[i];
    }

    cout<<"P  "<<"B  " << "W  " <<"T "<<endl ;
    Waiting[0] = 0;
    TurnAround[0] = Burst_time[0];
    cout<< Burst_time[0] <<" "<< Waiting[0] << " "<<TurnAround[0]  <<endl;

    for(int i = 1 ; i<n ; i++){
        Waiting[i] = Waiting[i-1] + Burst_time[i-1];
        TurnAround[i] = Waiting[i] + Burst_time[i];
        cout<<i-1<<" "<< Burst_time[i] <<" "<< Waiting[i] << " "<<TurnAround[i]  <<endl;
    }
    cout<<endl;
    int sum_W = 0;
    int sum_T = 0;
    for(int i = 0 ; i< n ; i++){
        sum_W += Waiting[i];
        sum_T += TurnAround[i];
    }

    float Avg_W = sum_W / n;
    float Avg_T = sum_T / n;

    cout<<"Avrage of Waiting Time: "<<Avg_W<<endl;
    cout<<"Avrage of TurnAround: "<<Avg_T<<endl;
    return 0;


}