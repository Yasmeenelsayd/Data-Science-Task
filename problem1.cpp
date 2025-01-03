#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int getmax(vector<vector<int>>& grid, int n, int m)
{
    vector<long long> diagonal1(n + m - 1, 0);
    vector<long long> diagonal2(n + m - 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            diagonal1[i + j] += grid[i][j];
            diagonal2[i - j + m - 1] += grid[i][j];
        }
    }
    long long maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long sum = diagonal1[i, j] + diagonal2[i - j + m - 1] - grid[i][j];
            maxsum = max(maxsum, sum);
        }
    }

    return maxsum;

}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int> (m)) ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        cout << getmax(grid, n, m) << endl;
    }
}

