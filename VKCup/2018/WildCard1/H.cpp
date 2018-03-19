#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    vector<char> str(n);
    int k_orange = 0;
    int k_red = 0;
    int k_white = 0;
    for(int i = 0; i<n; i++) {
        cin >> str[i];
        if (str[i] == 'O') {
            k_orange += 1;
        } else {
            if(str[i] == 'R')
                k_red += 1;
            else
                k_white += 1;
        }
    }
    vector<int> orange(k_orange);
    vector<int> red(k_red);
    vector<int> white(k_white);
    k_orange = 0;
    k_red = 0;
    k_white = 0;
    for(int i = 0; i<n; i++) {
        if (str[i] == 'O') {
            orange[k_orange] = arr[i];
            k_orange += 1;
        } else {
            if(str[i] == 'R') {
                red[k_red] = arr[i];
                k_red += 1;
            } else {
                white[k_white] = arr[i];
                k_white += 1;
            }
        }
    }
    sort(orange.rbegin(), orange.rend());
    sort(red.rbegin(), red.rend());
    sort(white.rbegin(), white.rend());
    for (int i = 1; i < k_orange; i++) {
        orange[i] += orange[i - 1];
    }
    for (int i = 1; i < k_red; i++) {
        red[i] += red[i - 1];
    }
    for (int i = 1; i < k_white; i++) {
        white[i] += white[i - 1];
    }
    int ans = -1;
    for (int i = 1; i < k; i++) {
        if (k_orange >= i) {
            if (k_white + i >= k) {
                if (ans < orange[i - 1] + white[k - i - 1]) {
                    ans = orange[i - 1] + white[k - i - 1];
                }
            }
            if (k_red + i >= k) {
                if (ans < orange[i - 1] + red[k - i - 1]) {
                    ans = orange[i - 1] + red[k - i - 1];
                }
            }
        }
    }
    printf(%d, ans);
    return 0;
}
