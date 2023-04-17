#include <iostream>
#include <stdlib.h>
#include <vector>
int main()
{
    FILE *fptr;
    if ((fptr = fopen("input-3.txt", "r")) == NULL)
    {

        printf("Error in opening file\n");
        exit(1);
    }
    int N, T; // N is the number of different pipe sizes, T is the size of each pipe produced
    fscanf(fptr, "%d %d\n", &N, &T);
    int lengths[N + 1];
    int values[N + 1];
    std::vector<int> opt(T + 1, 0); //1D array to hold optimal values
    int l, v;       // temporary values for reading
    for (int i = 0; i <= N; i++)
    {
        if (i == 0)
        {
            lengths[i] = 0;
            values[i] = 0;
        }
        else
        {
            fscanf(fptr, "%d %d\n", &l, &v);
            lengths[i] = l;
            values[i] = v;
        }
    }
    fclose(fptr);
    int included = 0;
    int repeated = 0;
    for (int t = 0; t <= T; t++)
    {
        for (int n = 0; n <= N; n++)
        {
            if (lengths[n] <= t)
            {
                included = values[n] + opt[t - lengths[n]];
                repeated = opt[t];
                opt[t] = included > repeated ? included : repeated;
            }
                    
        }
    }
    std::cout << opt[T] << "\n";
    return 0;
}