#include <iostream>
#include <vector>
 
using namespace std;
 
int m, n, i, j;
vector <vector<int>> field;
 
void step(int a, int b, int count) {
    count++;
    if((a < n && b < m) && (a > -1 && b > -1))
        if(field[a][b] > count) {
            if(a == i && b == j){
                field[a][b] = count;
                return;
            }
            field[a][b] = count;
            step(a+2, b+1, count);
            step(a+2, b-1, count);
            step(a-2, b+1, count);
            step(a-2, b-1, count);
            step(a+1, b+2, count);
            step(a+1, b-2, count);
            step(a-1, b+2, count);
            step(a-1, b-2, count);
        }
}
 
int main() {
    cin >> n >> m >> i >> j;
    field.assign(n, vector<int>(m, 1488));
    step(0, 0, -1);
    if(field[i-1][j-1] == 1488) cout << "NEVAR";
    else cout << field[i-1][j-1];
    return 0;
}