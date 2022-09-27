#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sum(vector<vector<int>> mat, int k, int L)
{
    int r = 0;
    for (int i = 0; i < k; i++)
    {
        if (mat[i][i] < 0)
        {
            for (int j = 0; j < L; j++)
            {
                    r += mat[i][j];
            }
        }
    }
    return r;
}

int main()
{
    string s = "";
    ifstream file("/uploads/input.txt");
    vector<vector <int>> mat;
    int k = 0, L = 0, k1 = 0, s1 = 0, m = 0;
    while(getline(file, s))
    {
        cout<<s<<endl;
        if (k == 0)
        {
        L = s.length();
        for (int i: s)
            if (i == '-' or i == ' ')
                L--;
        }
        k++;
    }
    file.close();
    L--;

    mat.resize(k);
    for (int i = 0; i <= L; i++)
    mat[i].resize(L);

    ifstream file1("/uploads/input.txt");
    int i = 0;
    while(file1 >> s1)
    {
        if (k1 == L)
        {
            i++;
            k1 = 0;
        }
    mat[i][k1] = s1;
    k1++;
    }
    file1.close();
    s1 = sum(mat, k, L);
    cout <<endl<<"Summa elementov " << s1;
    return 0;
}
