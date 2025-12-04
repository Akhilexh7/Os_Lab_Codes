#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int totalmemo; 
    int each_block_memo;
    cout<<"enter total memory of the system "<<endl;
    cin>>totalmemo;
    cout<<"enter memory allocated for each block "<<endl;
    cin>>each_block_memo;
    int partition = totalmemo / each_block_memo;
    cout<<"there are "<<partition<<" partition can form by allocated memory"<<endl;
    int memo_proc[n];
    // int 
    for(int i = 0 ; i < partition ; i++){
        cout<<"enter memory required for "<<i+1<<"th process"<<endl;
        cin>>memo_proc[i]; //each process memo
    }

    int internal_frag_each[n]; //stores each block internal fragmentation

    ///blocksize - (memory req)
    for(int i = 0 ; i < partition ; i++){
        internal_frag_each[i] = each_block_memo - memo_proc[i];
    }

    //processes      //block size      //process size   //fragmentation
    cout<<"process  "<<"block size  "<<"process size  "<<"fragmentation   "<<endl;
    for(int i = 0 ; i <partition ; i++){
        cout<<i+1<<"         "<<each_block_memo<<"      "<<memo_proc[i]<<"       "<<internal_frag_each[i]<<endl;
    }

}