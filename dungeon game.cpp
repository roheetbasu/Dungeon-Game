// dungeon game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
using namespace std;
int min(int a, int b) {
    return a <= b ? a : b;
}
int max(int a, int b) {
    return a <= b ? b : a;
}
class Solution {
public:
    void calculateMinimumHP(int *dp, int r, int c) {
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {

                if (i == r - 1 && j == c - 1)
                {
                    *(dp+i*c+j) = max(1, 1 -*(dp+i*c+j));
                }

                else if (i == r - 1)
                {
                    *(dp + i * c + j) = max(1,*(dp+i*c+(j+1)) - *(dp+i*c+j));
                }

                else if (j == c - 1)
                {
                    *(dp + i * c + j) = max(1,*(dp+(i+1)*c+j) - *(dp+i*c+j));
                }

                else
                {
                    *(dp+i*c+j) = max(1, min(*(dp+(i+1)*c+j),*(dp+i*c+(j+1))) - *(dp+i*c+j));
                }
            }
        }

        cout << "The minimumHp required is:" << *dp << endl;
        calculatePath((int *)dp, r, c);

    }
    void calculatePath(int *dp, int r, int c) {
        int i = 0,j=0,temp;
        cout << "Path to follow:"<<endl;
        do{
            if (i == r-1)
            {
                for (int a = j; a <c-1; a++) {
                    cout << "Right "<<endl;
                }
                i++;
            }
            else if (j == c-1)
            {
                for (int a = i; a <r-1; a++) {
                    cout << "Down  " << endl;
                }
                j++;
            }
            else {
                temp = min(*(dp + (i + 1) * c + j), *(dp + i * c + (j + 1)));

                if (temp == *(dp + (i + 1) * c + j))
                {
                    i++;
                    cout << "Down" << endl;
                }
                else
                {
                    j++;
                    cout << "Right" << endl;
                }
            }
        } while (i < r && j < c);
    }
};
int main() {
    Solution ob;
    int r, c;
    cout << "Enter the size for mage(matrix m*n):";
    cin >> r >> c;
    int* mat = new int[r * c];
    cout << "Enter the value for dungeon rooms:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "(" << i << "," << j << "):";
            cin >> *(mat+i*c+j);
        }
        cout << endl;
    }
    ob.calculateMinimumHP((int *)mat, r, c);
    delete[] mat;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
