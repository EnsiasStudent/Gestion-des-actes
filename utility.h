#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED
	
			// On a besoin de ces fonctions pour les opérations de tri au niveau de la permutaion entre pointeur //
void char_permute(char a[],char b[])
{  char c[15]="\0";
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}
	       // on a besoin de ces fonctions pour les opérations de tri  au niveau de la permutation entre caracteres //
void int_permute(int *a, int *b)
{
    int c=0;
    c=*a;
    *a=*b;
    *b=c;

}

#endif // UTILITY_H_INCLUDED
