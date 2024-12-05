#include <iostream>
#include <string>
using namespace std;

int main()
{
    int card;
    cin >> card;

    int*ary_1 = new int[card];
    int*ary_2 = new int[card];
    bool*full = new bool[card];

    for(int i = 0; i < card; i++)
    {
        ary_1[i] = card - i;
        full[i] = false;
    }

    for(int i = 0; i < card; i++)
    {
        int act;
        cin >> act;
        if(act == 1)
        {
            int a = 0;
            while(a < card && full[a] == true)
            {
                a++;
            }
            if(a < card){
            ary_2[a] = ary_1[i];
            full[a] = true;}
        }
        else if(act == 2)
        {
            int a = 0;
            while(a < card && full[a])
            {
                a++;
            }
            int b = a + 1;
            while(b < card && full[b])
            {
                b++;
            }
            if(b < card){
            ary_2[b] = ary_1[i];
            full[b] = true;}
        }
        else if(act == 3)
        {
            int c = card - 1;
            while(c >= 0 && full[c])
            {
                c--;
            }
            if(c >= 0){
            ary_2[c] = ary_1[i];
            full[c] = true;}
        }
    }

    for(int i = 0; i < card; i++)
    {
        cout << ary_2[i] << " ";
    }

    delete[] ary_1;
    delete[] ary_2;
    delete[] full;
}