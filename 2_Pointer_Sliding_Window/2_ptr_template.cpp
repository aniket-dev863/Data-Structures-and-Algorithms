// Find the longest subarray of ones after atmost k flips .
// Example : n=6 k=2  { 1 , 0 , 1 , 0 , 1 , 0 } ;
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // Initialise the tail and Head
    // head should always start from before the head to start with a Zero Subarray
    int tail = 0;
    int head = -1;
    // DS to store the zeroCnt;
    int zerocnt = 0;
    // DS to store the ans
    int ans = 0;
    while (tail < n)
    {
        while (head < n && (zerocnt < k || v[head + 1] == 1))
        {
            head++;
            if (v[head] == 0)
            {
                zerocnt++;
            }
        }
        ans = max(ans, head - tail + 1);
        if (head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            if (v[tail] == 0)
                zerocnt--;
            tail++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

/*
    This is the general template to write a 2 pointer code in the Any situation .


 #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // head and tail
    int tail = 0, head = -1;

    // datastructure for the window
    int cntzero = 0;

    // answer maintain
    int ans = 0;

    while (tail < n)
    {
        while (// there is a next element to eat && we can eat)
        {
            head++;

            // include elemenet at head in the data structure
        }


        // update the answer for current start


        // move start one step forward.
        if (tail > head)    // keep it same for all question, it basically help to handle empty subarray
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            // change data  structure because removing tail element

            tail++;
        }
    }

    cout << ans << endl;
}

*/