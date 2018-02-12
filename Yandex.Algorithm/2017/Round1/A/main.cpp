#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> letters;
    int n, a, b;
    cin >> n >> a >> b;
    while (n-- > 0) {
        int temp;
        cin >> temp;
        letters.push(temp);
    }
    queue<int> answer;
    answer.push(letters.front());
    letters.pop();
    int to_ans = answer.front() + b;
    int time = answer.front();
    while (!answer.empty() || !letters.empty()) {
        while (!letters.empty() && letters.front() <= time) {
            answer.push(letters.front());
            letters.pop();
        }
        if (!answer.empty()) {
            if (time >= answer.front() + b || answer.size() >= a) {
                int ssize = answer.size();
                ssize = ssize / 2 + ssize % 2;
                while (ssize-- > 0) {
                    cout << time << " ";
                    answer.pop();
                }
            }
        }
        ++time;
    }
    return 0;
}