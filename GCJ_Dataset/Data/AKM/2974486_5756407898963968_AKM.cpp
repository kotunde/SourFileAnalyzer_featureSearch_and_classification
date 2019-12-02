#include <iostream>

using namespace std;

int a[10][10], b[10][10];
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int r1;
        cin >> r1;
        r1--;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> a[i][j];
        int r2;
        cin >> r2;
        r2--;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> b[i][j];
        int ans, anscnt = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (a[r1][i] == b[r2][j])
                {
                    ans = a[r1][i];
                    anscnt++;
                }
        cout << "Case #" << tc << ": ";
        if (anscnt > 1)
            cout << "Bad magician!" << endl;
        else if (anscnt == 1)
            cout << ans << endl;
        else
            cout << "Volunteer cheated!" << endl;
    }
}
