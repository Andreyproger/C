#include <stdio.h>
#include <stdlib.h>


struct Book
{
    char author[100], title[1000];
    int  count_of_pages;
};


void Sort_by_author(struct Book *books, int n)
{
    int i, j;
    struct Book t;
    for (j=0; j<n-1; j++)
        for (i=0; i<n-1; i++)
            if ( strcmp(books[i].author, books[i+1].author) > 0)
            {
                t = books[i];
                books[i] = books[i+1];
                books[i+1] = t;
            }
}

void Sort(struct Book *books, int n)
{
    int i, j;
    struct Book t;
    for (i=0; i<n; i++)
        for (j=0; j<n-i-1; j++)
            if ( books[j].count_of_pages > books[j+1].count_of_pages)
            {
                t = books[j];
                books[j] = books[j+1];
                books[j+1] = t;
            }
}

double Median(struct Book *books, int n)
{
    if (n % 2 == 0)
        return (double)(books[n/2-1].count_of_pages+books[n/2].count_of_pages)/2;
    else
        return (double)(books[n/2].count_of_pages);
}

void FindTheBestAuthor(struct Book *books, int n, char *r)
{
    char res[100]="", prev[100]="";
    int i, t=1, max=0;
    strcpy(prev, books[0].author);
    for (i = 1; i < n; i++)
    {
        if (strcmp(prev, books[i].author) == 0)
            t++;
        else
        {
            if (t>max)
            {
                max = t;
                strcpy(res, prev);
            }
            t = 1;
            strcpy(prev, books[i].author);
        }
    }
    if (t>max)
    {
        max = t;
        strcpy(res, prev);
    }
    strcpy(r, res);
}

int main()
{
    struct Book books[1000];
    FILE *mf;
    char r[100];
    int i = 0, k=0;
    mf = fopen("books.txt", "r");
    if (mf == NULL) {printf("error");return -1;}
    fscanf(mf, "%d\n", &k);
    for (i=0; i<k; i++)
    {
        fgets(books[i].author, 100, mf); books[i].author[strlen(books[i].author)-1]=0;
        fgets(books[i].title, 1000, mf); books[i].title[strlen(books[i].title)-1]=0;
        fscanf(mf, "%d\n", &books[i].count_of_pages);
    }

    printf("---- Data: ----\n");

    for (i = 0; i < k; i++)
        printf("%s %s %d\n", books[i].author, books[i].title, books[i].count_of_pages);

    printf("---- Sort by pages ----\n");

    Sort(books, k);

    for (i = 0; i < k; i++)
        printf("%s %s %d\n", books[i].author, books[i].title, books[i].count_of_pages);

    printf("Median of pages is %f\n", Median(books, k));

    /*printf("РЈ СЌС‚РѕРіРѕ Р°РІС‚РѕСЂР° Р±РѕР»СЊС€Рµ РІСЃРµРіРѕ РєРЅРёРі: ");*/

    printf("---- Sort by author ----\n");

    Sort_by_author(books, k);

    for (i = 0; i < k; i++)
        printf("%s %s %d\n", books[i].author, books[i].title, books[i].count_of_pages);

    FindTheBestAuthor(books, k, r);
    printf("РЈ СЌС‚РѕРіРѕ Р°РІС‚РѕСЂР° Р±РѕР»СЊС€Рµ РІСЃРµРіРѕ РєРЅРёРі РІ РґР°РЅРЅРѕРј РЅР°Р±РѕСЂРµ: %s\n", r);

    return 0;
}
