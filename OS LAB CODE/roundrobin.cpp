#include <bits/stdc++.h>
using namespace std;
int n, qt, current_time, completed, tot_wt;
struct schedule
{
    int pid, at, bt, remaining_bt, wt;
};
schedule p[100];
bool compare(schedule a, schedule b)
{
    if (a.at < b.at)
        return 1;
    return 0;
}
int main()
{
    cin >> n;
    cout << "Number of processes: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i + 1;
        p[i].remaining_bt = p[i].bt;
    }
    cin >> qt;
    cout << "Quantam Time: " << qt << endl;
    sort(p, p + n, compare);
    cout << "\n-------------------Gantt Chart-------------------\n";
    while (completed < n) //jtokhn prjnto shb task shesh nah hoy
        for (int i = 0; i < n; i++)
        {
            if (p[i].remaining_bt != 0)
                cout << "||" << current_time << "->P";
            if (p[i].at <= current_time && p[i].remaining_bt > 0)
            {
                if (p[i].remaining_bt <= qt)
                {
                    completed++; //ekta process cmplt
                    current_time += p[i].remaining_bt;
                    p[i].wt = current_time - p[i].at - p[i].bt;
                    tot_wt += p[i].wt;
                    p[i].remaining_bt = 0;
                    cout << i + 1 << "<-" << current_time;
                }
                else
                {
                    current_time += qt;
                    p[i].remaining_bt -= qt;
                    cout << i + 1 << "<-" << current_time;
                }
            }
        }
    cout << "\n\nP.No\t\tArrival\t\t\tBurst\t\tWaiting\t" << endl;
    for (int i = 0; i < n; i++)
        cout << "P" << p[i].pid << "\t\t" << p[i].at << "\t\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t" << endl;
    cout << "\nAverage Waiting Time = " << tot_wt / (n * 1.0) << endl;
    return 0;
}
/*
4
0 53
1 17
2 68
3 24
20
*/

