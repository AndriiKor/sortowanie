#include <stdio.h>
#include <stdlib.h>

void Quicksort();
int main()
{
    int n;
    printf("Podaj rozmiar Tablicy: ");
    scanf("%d", &n);
    int i;
    int *T;
    T=(int*)malloc(300*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("Podaj T[%d]: ", i);
        scanf("%d", (T+i));
    };
    Quicksort(n, T);

    printf("\nPo przesortowaniu: \n");
    char str[12];
    int t = 0;
    for (i=0; i<n; i++)
    {
        printf("T[%d] = %d \n", i, *(T+i));
    };
    free(T);
    return 0;
}

void Quicksort(int n,int *T)
{
    int elpodst, liczbaZnalElem, i, temp, ppodst;
    if (n>1)
    {
        elpodst=T[0];
        ppodst=1;
        liczbaZnalElem=0;
        for(i=0; i<n; i++)
        {
            if (T[i]<elpodst)
            {
                temp=T[ppodst];
                T[ppodst]=T[i];
                T[i]=temp;
                ppodst++;
                liczbaZnalElem++;
            }
        }
        for (i=1; i<liczbaZnalElem+1; i++)
        {
            T[i-1]=T[i];
        }
        T[liczbaZnalElem]=elpodst;
        Quicksort(liczbaZnalElem, T);
        Quicksort(n-liczbaZnalElem-1, T+liczbaZnalElem+1);
    }
}


