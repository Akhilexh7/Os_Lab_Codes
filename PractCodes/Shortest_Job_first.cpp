#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[n], BT[n], WT[n], TAT[n];

    for(int i = 0; i < n; i++){
        p[i] = i + 1;
        cout << "Enter Burst Time for Process " << p[i] << ": ";
        cin >> BT[i];
    }

    // Sort by burst time (SJF)
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(BT[i] > BT[j]){

                swap(BT[i], BT[j]);
                swap(p[i], p[j]); 
            }
        }
    }

    WT[0] = 0;
    TAT[0] = BT[0];

    cout << "P   BT   WT   TAT\n";
    cout << p[0] << "   " << BT[0] << "    " << WT[0] << "    " << TAT[0] << endl;

    for(int i = 1; i < n; i++){
        WT[i] = WT[i-1] + BT[i-1];
        TAT[i] = WT[i] + BT[i];

        cout << p[i] << "   " << BT[i] << "    " << WT[i] << "    " << TAT[i] << endl;
    }

    return 0;
}
