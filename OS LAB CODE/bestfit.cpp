#include<bits/stdc++.h>
using namespace std;
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int b,p,i;
    printf("Enter the number of Block    Size : ");
    scanf("%d",&b);
    printf("Enter the number of Process  Size : ");
    scanf("%d",&p);
    int blockSize[b+5],processSize[p+5];
    cout<<"Enter the Blocks  Size : ";

 for(i=0; i<b; i++)
        cin>>blockSize[i];
    cout<<"Enter the Process  Size : ";

for(i=0; i<p; i++)
        cin>>processSize[i];

 bestFit(blockSize, b, processSize, p);
    return 0 ;

}

/*
5
4
100 500 200 300 600
212 417 112 426
*/
