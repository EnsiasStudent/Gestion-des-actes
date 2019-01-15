# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <windows.h>
# include <time.h>
# include "utility.h"
# include "structures.h"
# include "afficher.c"
# include "ajouter.c"
# include "trie.c"
# include "chercher.c"
# include "fichiers.c"
# include "supprimer.c"
# include "modifier.c"
# include "age.c"
# include "the MENU.c"
# include "generer_acte.c"
# include "login.c"

int main()
{

        system("cls");
        printf("\n\t#############################################################################");
        printf("\n\t#                                                                           #");
        printf("\n\t#                           BIENVENUE                                       #");
        printf("\n\t#                                                                           #");
        printf("\n\t#############################################################################\n");
        Liste *liste=malloc(sizeof(Liste));
        lire(liste);
        login();
		menu(liste);

        getchar();

return 0;
}
