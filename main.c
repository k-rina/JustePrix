#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int justeprix()
{
    //cr�ation du nombre � trouver
    int randomValue;
    srand(time(NULL));
randomValue = rand() % 100+1;

return randomValue;
}
int verifprix(int prixjuste)
{
  int  nb_essaies=0;
    int nombre=0;
while(nombre!=prixjuste)
{


//on demande � l'utilisateur le noombre � trouver
    printf("Donnez un nombre compris entre 0 et 100 \n");
    scanf("%d",&nombre);
    //on incr�mente le nombre d'essaies
    nb_essaies++;
    // on v�rifie si le prix trouv� est �gal au justeprix
    if(nombre>prixjuste)
        printf("Le juste prix est inferieur au nombre donne\n");
    if(nombre<prixjuste)
        printf("Le juste prix est superieur au nombre donne\n");
}
printf("Bravo , vous avez trouve le juste prix qui est %d\n",prixjuste);
printf("Vous avez trouve avec %d essaies\n",nb_essaies);
return  nb_essaies;
}
int main()
{
     FILE* fichier = NULL;
    int prixjuste;
    int reponse=1;
    int nombre_dessai=0;

   while(reponse!=0)
   {
        printf("Voulez vous jouer 0 pour non , 1 pour oui\n");
      scanf("%d",&reponse);
     switch (reponse)
      {

      case 0: break;
      case 1:
        {
      prixjuste= justeprix();

      nombre_dessai=verifprix(prixjuste);

        }
      default :
{
    printf("Voulez vous jouer 0 pour non , 1 pour oui\n");
      scanf("%d",&reponse);
}


   }
   }


  fichier= fopen("ScoreJustePrix.txt", "a");
          fprintf(fichier, "Le juste prix �tait %d et vous l'avez trouv� en %d essaies ! \n", prixjuste,nombre_dessai);

  fclose(fichier);

    return 0;
}

