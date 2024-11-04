#include <iostream>
#include <fstream>

void autoMatrixHandler(char input[],char output[]) {
    int mtx[10000] = {};
    std::ifstream fin(input);
    int n = 0;
    fin >> n;
    int m = 0;
    fin >> m;
    
    for (int i = 0; i < n*m; i++) {
        fin >> mtx[i];
    }
    fin.close();
    int count = 1;
    
    int e = n;
    int r = m;
    int a = -1;
    while (e * r != 0)
    {
        for (int i = 0; i < r; i++)
        {
            a++;
            mtx[a] -= count;
            count++;
        }
        if (e * r == 0)
        {
            break;
        }
        e--;
        for (int i = 0; i < e; i++)
        {
            a += m;
            mtx[a] -= count;
            count++; 
        }
        if (e * r == 0)
        {
            break;
        }
        r--;
        for (int i = 0; i < r; i++)
        {
            a--;
            mtx[a] -= count;
            count++;
        }
        if (e * r == 0)
        {
            break;
        }
        e--;
        for (int i = 0; i < e; i++)
        {
            a -= m;
            mtx[a] -= count;
            count++;
        }
        if (e * r == 0)
        {
            break;
        }
        r--;
    }
    std::ofstream fout(output);
    fout << n << ' ' << m << ' ';
    for (int i = 0; i < n * m; i++) {
        fout << mtx[i] << ' ';
    }
}

void dynamicalMatrixHandler(char input[],char output[]) {
    std::ifstream fin(input);
    int n = 0;
    fin >> n;
    int m = 0;
    fin >> m;
    fin.close();
    
    int* mtx = new int[m * n];

    for (int i = 0; i < n * m; i++) {
        fin >> mtx[i];
    }
    
}

int main(int argc, char** argv)
{
    if (argv[0] == "1")
    {
        autoMatrixHandler(argv[1], argv[2]);
    }
    else if (argv[0] == "2")
    {
        dynamicalMatrixHandler(argv[1], argv[2]);
    }
    return 0;
}