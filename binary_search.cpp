#include<stdio.h>

int main(void)
{
    int count, search;
    int first, mid, last;

    printf("Enter the element you want? : ");
    scanf("%d", &count);

    int num[count];

    for ( int i = 0 ; i < count ; i++ )
    {
        printf("Enter your number [%02d] : ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("Enter the number that you are going to search : ");
    scanf("%d", &search);

    first = 0;
    last = count - 1;
    mid = (first + last) / 2;

    while ( first <= last )
    {
        int n = num[mid];

        if ( n < search )
        {
            first = mid + 1;
        }
        else if ( n == search )
        {
            printf("%d found in the number array at the location %d", search, mid + 1);
            break;
        }
        else
        {
            last = mid - 1;
        }

        mid = (first + last) / 2;
    }

    if ( first > last )
    {
        printf("%d not found in the number array", search);
    }

    return 0;
}