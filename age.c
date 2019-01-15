# include <stdio.h>
# include <time.h>
# include <windows.h>
# include "structures.h"

void age(Personne p)
{

    int age,jour,mois,annee;
    SYSTEMTIME t;
    GetSystemTime(&t);

    jour=p.date_de_naissance[0];
    mois=p.date_de_naissance[1];
    annee=p.date_de_naissance[2];
    age=t.wYear;
    printf("Votre age est :\n");
    if (mois>t.wMonth)
    {
    	age=age-annee-1;
    	printf("%d\n",age);
    }
    else if (mois<t.wMonth)
    {
    	age=age-annee;
    	printf("%d\n",age);
    }
    else
    {
    	if (jour<t.wDay)
    	{
    		age=age-annee;
    		printf("%d\n",age);
    	}
    	else if (jour>t.wDay)
    	{
    		age=age-annee-1;
    		printf("%d\n",age);
    	}
    	else
    	{
      		age=age-annee;
    		printf("%d\n",age);
    		printf("Happy Birthday !!\n");
    	}
    }
}
