#include <bits/stdc++.h>
using namespace std;

void knapsack(int n, float wt[], float pf[], float capacity)
{
    float rem_wt = capacity;
    int i = 0;
    float total_pf = 0;

    while (rem_wt > 0)
    {

        if (wt[i] <= rem_wt)
        {
            total_pf = total_pf + pf[i];
            rem_wt = rem_wt - wt[i];
            i++;
        }
        else
        {
            total_pf = total_pf + pf[i] / wt[i] * rem_wt;
            rem_wt = 0;
        }
    }
    cout << "maximum profit :" << total_pf;
}

int main()
{
    int n;
    cout << "enter number of items :";
    cin >> n;
    float wt[n];
    float pf[n];
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        cout << "enter weight of item:";
        cin >> wt[i];
        cout << "enter value of item:";
        cin >> pf[i];
    }
    float capacity;
    cout << "enter capacity of knapsack :";
    cin >> capacity;
    float retio[n];
    for (i = 0; i < n; i++)
    {
        retio[i] = pf[i] / wt[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (retio[i] < retio[j])
            {
                temp = retio[j];
                retio[j] = retio[i];
                retio[i] = temp;

                temp = wt[j];
                wt[j] = wt[i];
                wt[i] = temp;

                temp = pf[j];
                pf[j] = pf[i];
                pf[i] = temp;
            }
        }
    }
    
    knapsack(n, wt, pf, capacity);
    return 0;
}
