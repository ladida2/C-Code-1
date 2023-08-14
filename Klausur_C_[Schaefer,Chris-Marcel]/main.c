#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ANZAHL 5
int oberunter();
void tauschen( int*, int*);
int countCapitals(char*);
void sortNumbers();

void firmendings();

struct Firma
{
   char Firmenname[66];
   char  Firmenort [66];
   int Gruendungsjahr;
   double Umsatz;
};

typedef struct Firma firma;
int main()
{
    bool weiter = true;
    char arr[] = "Hallo Welt";
    int wahl;


    do{

            printf("\nWahl zwischen \n1.Oberunter:\n2.countCapitals:\n3.Firma\n4.Sortierung\nFuer Ende 0\n");
            scanf("%d",&wahl);

        if(wahl == 1)
        {
            oberunter();
            weiter = true;
        }else
            if (wahl==2)
                {
                    countCapitals(arr);
                    printf("Anzahl Grossbuchstaben: %d\n",countCapitals(arr));
                    weiter = true;
                }else
                    if(wahl==3)
                        {
                            firmendings();
                            weiter = true;
                        }else
                            if (wahl==4)
                            {
                                 sortNumbers();
                                weiter = true;
                            }
                               else
                                    weiter = !true;
    }while (weiter ==true);
    return 0;
}
void sortNumbers()
{
    int arr[ANZAHL];
    int helfer;
    int getauscht= 1;
    int anzahl = sizeof(arr)/sizeof(int);


    int min = INT_MAX;
    int max = INT_MIN;

    for( int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d. Zahl: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for( int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        if( min > arr[i])
            min = arr[i];
        if( max > arr[i])
            max = arr[i];
        printf("%d\n",arr[i]);
    }
    while(getauscht==1)
    {
        getauscht =0;
        for(int i = 0; i<anzahl-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                helfer = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=helfer;
                getauscht = 1;
            }
        }


    }
    for (int i= 0;i<anzahl;i++)
        printf("\n%d ",arr[i]);
        printf("\n");
}

void firmendings()
{
    firma fir;

    printf("Firmenname:");
        scanf("%s",fir.Firmenname);
    printf("Firmenort:");
        scanf("%s",fir.Firmenort);
    printf("Gruendungsjahr:");
        scanf("%d",&fir.Gruendungsjahr);
    printf("Umsatz:");
        scanf("%lf",&fir.Umsatz);

   printf("\nFirmenname:%s\nFirmenort:%s\nGruendungsjahr:%d\nUmsatz:%.2lf\n",fir.Firmenname,fir.Firmenort,fir.Gruendungsjahr,fir.Umsatz);


}
int countCapitals(char *parr)

{

    char *poi;
    int zaehler = 0;

    for( poi = parr; *poi != '\0'; poi++)
    {
        if(*poi >='A' && *poi <='Z')
            zaehler++;
    }

    return zaehler;


}
int oberunter()

{
    int unter;
    int ober;
    int summe;


    printf("Unter: ");
    scanf("%d", &unter);

    printf("Ober: ");
    scanf("%d", &ober);

    tauschen( &unter, &ober);

    for( ++unter; unter < ober; unter++)
    {
         summe +=unter;
        if( unter % 2)
            printf("\n%d ungerde\n", unter);
            else
                printf("\n%d gerade\n", unter);
    }

printf("\nSummer der Zahlen: %d\n", summe);
}
void tauschen( int *unter, int *ober )
{
    int helferlein;

    if( *unter > * ober)
    {
        helferlein = *unter;
        *unter = *ober;
        *ober = helferlein;
    }
}
