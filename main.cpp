#include <iostream>
#include <stdlib.h>

int main()
{

    FILE *fptr;
    if ((fptr = fopen("input-2.txt", "r")) == NULL)
    {

        printf("Error in opening file\n");
        exit(1);
    }
    int N, T; // N is the number of different pipe sizes, T is the size of each pipe produced
    fscanf(fptr, "%d %d\n", &N, &T);
    int lengths[N + 1];
    int values[N + 1];
    int opt[N + 1][T + 1]; // 2D array holding optimal values
    int l, v;              // temporary values for reading
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
    int excluded = 0;
    for (int n = 0; n <= N; n++)
    {
        for (int t = 0; t <= T; t++)
        {

            if (n == 0 || t == 0)
            {
                opt[n][t] = 0;
                continue;
            }
            if (lengths[n] > t)
            {
                opt[n][t] = opt[n - 1][t];
                
            }
            else
            {
                included = values[n] + opt[n - 1][t - lengths[n]];
                excluded = opt[n - 1][t];
                opt[n][t] = included > excluded ? included : excluded;
            }
        }
    }
    std::cout << "Max value " << opt[N][T] << "\n";
    return 0;
}
