#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter number of procces"<<endl;
    int n ; cin>>n;
    int burst[n]; //decleration array
    for(int i =0 ;i <n ; i++)
    {
        cout<<"enter burst time"<<endl;
        cin>>burst[i];
    } 
    cout<<"enter time quantum"<<endl;
    int t ; cin>>t; 
    int tot_time = 0;
    int tat[n]; //decleration array
    int wt[n]; //decleration array
    int ct[n]; //decleration array
    int temp_bt[n]; //decleration array
    int k[n]; //decleration array
    for(int i= 0 ; i < n ; i++){
        k[i]=i;
        temp_bt[i] = burst[i];
    }

    int donecnt = 0;
    while(donecnt < n)
    {
        for(int i = 0 ; i<n ; i++){
            if(temp_bt[i] > 0)
            {
                if(temp_bt[i] > t)
                {
                    tot_time += t;
                    temp_bt[i] -= t;
                }
                else
                {
                    tot_time += temp_bt[i];
                    temp_bt[i] = 0;
                    ct[i] = tot_time;
                    tat[i] = ct[i] - k[i];
                    wt[i] = tat[i] - burst[i];
                    donecnt++;
                    
                }
            }
        }
    }
    cout<<"burstt" <<"     "<<"waiting"<<"  "<<"tottime"<<"   " <<"ct"<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<burst[i] <<"     "<<wt[i]<<"  "<<tat[i] <<"   " <<ct[i] <<endl;
    }
}
