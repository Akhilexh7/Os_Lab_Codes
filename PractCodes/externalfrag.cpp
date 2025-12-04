#include<bits/stdc++.h>
using namespace std;
int main() {
    int total_system_memory; 
    cout<<"enter total sys memo " <<endl;
    cin>>total_system_memory;
    int n;
    cout<<"enter number of processes "<<endl; 
    cin>>n;
    int memory_for_each_process[n];
    int remainingmemo[n];
    remainingmemo[0] = total_system_memory;
    int external_fragmentation = -1;
    int end = n;
    for(int i = 0 ; total_system_memory >= 0 && i < n ; i++) {
        cout<<"enter memory for " << i+1 <<"th process" <<endl;
        cin>>memory_for_each_process[i];
        remainingmemo[i] = total_system_memory - memory_for_each_process[i];
        if(total_system_memory - memory_for_each_process[i] < 0) {
            external_fragmentation = abs(total_system_memory - memory_for_each_process[i]);
            cout<<"external fragmentation has occured in " <<i+1<<"th process" <<endl;
            end = i+1;
            break;
        } else {
            total_system_memory -= memory_for_each_process[i];
        }
    }
    cout<<"p   mop   remainingmemo"<<endl;
    for(int i = 0 ; i < end ; i++) {
        if(remainingmemo[i] < 0) remainingmemo[i] = 0;
        cout<<i+1 <<"  "<<memory_for_each_process[i]<<"  "<<remainingmemo[i]<<endl;
    }
    if(end < n) {
        cout<<"external frag occured of size " <<external_fragmentation<<"MB"<<endl;
    } else {
        cout<<"external frag does not occured and processes are ended"<<endl;
    }
}