#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> cables;
int N, K;

bool C(double l)
{
    int s = 0;
    for(int i = 0; i < N; i++) {
        s += (int)(cables[i] / l);
    }
    return s >= K;
}

void solve()
{
    double lb = 0.0;
    double ub = *(max_element(cables.begin(), cables.end()));
    for(int i = 0; i < 100; i++) {
        double mid = (lb + ub) / 2.0;
        if(C(mid)) lb = mid;
        else ub = mid;
    }
    cout.setf(ios::fixed);
    cout << setprecision(2) << floor(ub * 100) / 100 << endl;
}

int main()
{
    cin >>  N >> K;
    cables.reserve(N);
    for(int i = 0; i < N; i++) cin >> cables[i];

    solve();
}