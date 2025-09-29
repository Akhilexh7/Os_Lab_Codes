#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    int empty ;
    int item ;
    int item1 ;
    int buffer [20];
    int in = 0;
    int out = 0;
    int mutex = 1;
    int full = 0;

    void wait  (int s)
    {
        while(s<0)
        {
            cout<<"cant add item"<<endl;
            exit(0);
        }
        s--;
    }

    void signal (int s)
    {
        s++;
    }
    void produce()
    {
        wait (empty);
        wait(mutex);
        cout<<"enter item"<<endl;
        cin>> item;
        in = item1;
        signal (mutex);
        signal (full);
    }
    while(in<n);

    void consumer ()
    {
        do
        {
           wait(full);
           wait(mutex);
           item1 = buffer[out];
           cout<<"consumed"<item<<endl;
        } while (out<n);
        
    }
    void main()
    {
        cout<<"enter value of n"<<endl;
        cin>>n;
        empty= n ;
        while(in<n)
        {
            produce();
            while(in!=out)
            {
                consumer();
            }
        }
    }
}