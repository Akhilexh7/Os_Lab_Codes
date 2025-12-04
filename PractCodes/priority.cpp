#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[n], BT[n], PR[n], WT[n], TAT[n];

    // Input Priority and Burst Time
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "Enter Priority of Process " << p[i] << ": ";
        cin >> PR[i];
        cout << "Enter Burst Time of Process " << p[i] << ": ";
        cin >> BT[i];
    }

    // Sorting by priority (lower number = higher priority)
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(PR[i] > PR[j]) {

                swap(PR[i], PR[j]);
                swap(BT[i], BT[j]);
                swap(p[i], p[j]);
            }
        }
    }

    // Calculate Waiting Time & Turnaround Time
    WT[0] = 0;
    TAT[0] = BT[0];

    cout << "\nP   PR   BT   WT   TAT\n";
    cout << p[0] << "   " << PR[0] << "    " << BT[0] 
         << "    " << WT[0] << "    " << TAT[0] << endl;

    for(int i = 1; i < n; i++) {
        WT[i] = WT[i-1] + BT[i-1];
        TAT[i] = WT[i] + BT[i];

        cout << p[i] << "   " << PR[i] << "    " << BT[i] 
             << "    " << WT[i] << "    " << TAT[i] << endl;
    }

    return 0;
}
