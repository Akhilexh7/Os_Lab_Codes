#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cout<<"enter number of pages "<<endl;
    cin>>n;
    int pages[n];
    cout<<"enter the ref string "<<endl;
    for(int i = 0; i<n ; i++) {
        cin>>pages[i];
    }
    int frame;
    cout<<"enter number of frames: "<<endl;
    cin>>frame;

    vector<int>frames;
    int pg_flt = 0 ;
    int index_to_be_replaced = 0;
    for(int i = 0; i < n ; i ++) {

        //finding if its there 
        bool found = false;
        for(int j = 0 ; j < frames.size() ; j++) {
            if(frames[j] == pages[i]) {
                found = true;
            }
        }

        //pg falt condition
        if(found == false) {
            pg_flt++;
            if(frames.size() < frame) {
                frames.push_back(pages[i]);
            } else {
                frames[index_to_be_replaced] = pages[i];
                index_to_be_replaced = (index_to_be_replaced + 1) % frame;
            }
        }

        //print
        cout<<"curr page : " <<pages[i]<<endl;
        for(int k = 0 ; k < frames.size() ; k++) {
            cout<<frames[k] <<" ";
        }
        cout<<endl;
    }

    cout<<"no of pg flt : " <<pg_flt;
    
}