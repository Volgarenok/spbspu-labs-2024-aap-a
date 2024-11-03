#include <iostream>
#include <fstream>

void stackMatrixHandler(const char input[], const char output[]) {
    int mtx[100][100] = {};
    std::ifstream fin(input);
    int n = 0;
    fin >> n;
    int m = 0;
    fin >> m;
    
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            fin >> mtx[i][e];
        }
    }
    fin.close();
    int count = 1;
    int i = 0;
    int j = 0;
    for (int e = 0; e < (m >= n) ? (n) : (m); e++) {
        if (e % 2 == 0) {
            for (int z = 0; z < m - e - 1;z++) {
                mtx[i][j] -= count;
                count++;
                j++;
            }
            for (int z = 0; z < n - e - 1;z++) {
                mtx[i][j] -= count;
                count++;
                i++;
            }
        }
        else {
            for (int z = 0; z < m - e - 1;z++) {
                mtx[i][j] -= count;
                count++;
                j--;
            }
            for (int z = 0; z < n - e - 1;z++) {
                mtx[i][j] -= count;
                count++;
                i--;
            }
        }
    }
    std::ofstream fout(output);
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            fout << mtx[i][e] << ' ';
        }
    }
}

int main()
{
    int num = 0;
    std::cin >> num;
    char input[50] = {};
    std::cin >> input;
    char output[50] = {};
    std::cin >> output;

    if (num == 1) {
        stackMatrixHandler(input, output);
    }
    return 0;
}