#include<bits/stdc++.h>
using namespace std;
int main(){
    int total;
    cout<<"enter total memory avilable "<<endl;
    cin>>total;
    
    int mp = total-1;
    while(true){
        cout<<"memory for each process"<<endl;
        cin>>mp;
        if(total < mp){
            break;
        }
        total -= mp;
        cout<<"tatal avilable right now is- "<<total<<endl;
        cout<<"and "<<mp<<" size of memory allocated to a block"<<endl;
        cout<<endl;
        cout<<"want to continue ? , enter 1 to continue"<<endl;
        int i = 0;
        cin>>i;
        if(i != 1){
            break;
        }
        mp=0;
    }
    if(total < mp){
        cout<<"memory is full and,"<<endl;
        cout<<"the external fragmentation is "<<abs(total-mp)<<endl;
    } else{
        cout<<"memory allocated to the all processes"<<endl;
    }
    return 0;
}