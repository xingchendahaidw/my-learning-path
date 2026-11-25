#include <stdio.h>
#include <math.h>

int main()
{
    int n, start_id;
    scanf("%d %d", &n, &start_id);

    double score[1000];
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &score[i]);
        sum += score[i];
    }

    double avg = sum / n;
    double min_diff = fabs(score[0] - avg);
    for (int i = 1; i < n; i++)
    {
        double diff = fabs(score[i] - avg);
        if (diff < min_diff)
        {
            min_diff = diff;
        }
    }
    printf("%.1f\n", avg);
    for (int i = 0; i < n; i++)
    {
        if (fabs(score[i] - avg) == min_diff)
        {
            printf("%d\n", start_id + i);
        }
    }

    return 0;
}
