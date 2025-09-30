#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define MAX_ETUDIANTS 100
#define MAX_NOM 50
#define MAX_PRENOM 50


char noms[MAX_ETUDIANTS][MAX_NOM];
char prenoms[MAX_ETUDIANTS][MAX_PRENOM];
int matricules[MAX_ETUDIANTS];
float Fnotes[MAX_ETUDIANTS], Anotes[MAX_ETUDIANTS], Inotes[MAX_ETUDIANTS], Dnotes[MAX_ETUDIANTS], Cnotes[MAX_ETUDIANTS], Enotes[MAX_ETUDIANTS];
int nbEtudiants = 0;

void affichermoyen(float c,float a,float b,float j,float k,float m );
void affichercolorFRAN(float s);
void affichercolorANG(float s );
void affichercolorINFO(float s );
void affichercolorELECTRI(float s );
void affichercolorCIRCUIT(float s );
void affichercolorDROIT(float s );
void afficherMenuPrincipal();
void afficherMenuGestion();
void ajouterEtudiant();
void modifierEtudiant();
void ajouterNotesEtudiant();
int rechercherEtudiant(int matricule);
void afficherEtudiant(int x);
void afficherMenuConsultation();
void noteparmatiere();
void bulletin();
void  bulletinparetudiant();


int main()
{
    int choix;

    do {
        afficherMenuPrincipal();

        textcolor(BROWN);
        cprintf("                Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                clrscr();
                afficherMenuGestion();
                break;

            case 2:
                clrscr();
                afficherMenuConsultation();
                break;

            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);

    return 0;
}

void afficherMenuPrincipal(){
    clrscr();

    textcolor(BLUE);
    cprintf("\n               Menu Principal :           \n\n");
    printf(" 1 - Gestion\n\n");
    printf("                                           2 - Consultation\n\n");
    printf("                                           3 - Quitter\n\n");

}


void afficherMenuConsultation()
{
    int choix;

    do {

        clrscr();
        textcolor(BLUE);
        cprintf("\n               Menu de consultation  :\n\n");
        printf("1 - Liste de notes par matière\n\n");
        printf("                                      2 - Bulletin par étudiant\n\n");
        printf("                                      3 - Quitter\n\n");
        printf("                                      4 - Retour\n\n");

        textcolor(BROWN);
        cprintf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                clrscr();
                noteparmatiere();
                break;

            case 2:
                clrscr();
                bulletin();
                break;

            case 3:
                printf("Au revoir !\n");
                break;
            case 4:
                return;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);
}

void afficherMenuGestion() {
    int choix;

    do {
        textcolor(BLUE);
        cprintf("\n               Menu Gestion :\n\n");
        printf("1 - Ajouter un étudiant\n\n");
        printf("                             2 - Modifier un étudiant\n\n");
        printf("                             3 - Ajouter des notes par étudiant\n\n");
        printf("                             4 - Quitter\n\n");
        printf("                             5 - Retour\n\n");
        textcolor(BROWN);
        cprintf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                clrscr();
                ajouterEtudiant();
                break;
            case 2:
                clrscr();
                modifierEtudiant();
                break;
            case 3:
                clrscr();
                ajouterNotesEtudiant();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            case 5:
                return;
            default:
              printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);
}

void ajouterEtudiant()
{
    int i;

    if (nbEtudiants == MAX_ETUDIANTS)
        {
        printf("La liste des étudiants est pleine. Impossible d'ajouter un nouvel étudiant.\n");
        return;
    }

    printf("Entrez le nom de l'étudiant : ");
    scanf("%s", noms[nbEtudiants]);

    printf("Entrez le prénom de l'étudiant : ");
    scanf("%s", prenoms[nbEtudiants]);

    printf(" le matricule de l'étudiant : ");
    scanf("%d", &matricules[nbEtudiants]);


    for (i = 0; i < nbEtudiants; i++)
    {
        if (matricules[i] == matricules[nbEtudiants])
        {
            printf("Le matricule %d existe déjà. Veuillez choisir un matricule unique.\n", matricules[nbEtudiants]);
            printf("\a");
            return;
        }
    }

    nbEtudiants++;
}

void modifierEtudiant()
{
    int matricule, x;

    printf("Entrez le matricule de l'étudiant à modifier : ");
    scanf("%d", &matricule);

    x = rechercherEtudiant(matricule);

    if (x == -1) {
        printf("Aucun étudiant avec le matricule %d n'a été trouvé.\n", matricule);
        return;
    }

    printf("Entrez le nouveau nom de l'étudiant : ");
    scanf("%s", noms[x]);

    printf("Entrez le nouveau prénom de l'étudiant : ");
    scanf("%s", prenoms[x]);

    printf("Modification de l'étudiant avec le matricule %d effectuée avec succès.\n", matricule);
}

void ajouterNotesEtudiant()
{
    int matricule, x;

    printf("Entrez le matricule de l'étudiant : ");
    scanf("%d", &matricule);

    x = rechercherEtudiant(matricule);

    if (x == -1)
    {
        printf("Aucun étudiant avec le matricule %d n'a été trouvé.\n", matricule);
        return;
    }
   do
   {
    printf(" La note de l'étudiant dans le FRANCAIS  : ");
    scanf("%f", &Fnotes[x]);
   if(Fnotes[x]<0 || Fnotes[x]>20)
   {
       printf("\a");
   }
   }while(Fnotes[x]<0|| Fnotes[x]>20);

   do
   {
    printf(" La note de l'étudiant dans  l'ANGLAIS  : ");
    scanf("%f", &Anotes[x]);
    if(Anotes[x]<0 || Anotes[x]>20)
   {
       printf("\a");
   }
   }while(Anotes[x]<0|| Anotes[x]>20);

    do{
    printf(" La note de l'étudiant dans l'INFORMATIQUE : ");
    scanf("%f", &Inotes[x]);
    if(Inotes[x]<0 || Inotes[x]>20)
   {
       printf("\a");
   }
    }while(Inotes[x]<0|| Inotes[x]>20);

    do
    {
    printf(" La note de l'étudiant dans le CIRCUIT NUMERIQUE  : ");
    scanf("%f", &Cnotes[x]);
    if(Cnotes[x]<0 || Cnotes[x]>20)
   {
       printf("\a");
   }
    }while(Cnotes[x]<0|| Cnotes[x]>20);
    do{
    printf(" La note de l'étudiant dans  l'ELECTRICITE : ");
    scanf("%f", &Enotes[x]);
    if(Enotes[x]<0 || Enotes[x]>20)
   {
       printf("\a");
   }
    }while(Enotes[x]<0|| Enotes[x]>20);
    do{
    printf(" La note de l'étudiant dans  Droit  : ");
    scanf("%f", &Dnotes[x]);
    if(Dnotes[x]<0 || Dnotes[x]>20)
   {
       printf("\a");
   }
    }while(Dnotes[x]<0|| Dnotes[x]>20);
}

int rechercherEtudiant(int matricule) {
    int i;
    for (i = 0; i < nbEtudiants; i++) {
        if (matricules[i] == matricule)
            {
            return i;
        }
    }

    return -1;
}

void affichercolorFRAN(float note )
{
    if(note<10)
    {
    textcolor(YELLOW);
    cprintf("|       Francais       |%.2f    |     1.5      |%.2f    |",note,note*1.5);
    printf("\n");
    }
    else
    {
     printf("|       Francais       |%.2f   |     1.5      |%.2f   |\n",note,note*1.5);
    }
}
void affichercolorANG(float note )
{
    if (note<10)
    {
      textcolor(YELLOW);
    cprintf("|       Anglais        |%.2f    |     1.5      |%.2f    |",note,note*1.5);
    printf("\n");
    }
    else
    {
     printf("|       Anglais        |%.2f   |     1.5      |%.2f   |\n",note,note*1.5);
    }
}
void affichercolorINFO(float note )
{
    if (note<10)
    {
      textcolor(YELLOW);
     cprintf("|     Informatique     |%.2f    |     3.0      |%.2f   |",note,note*3.0);
    printf("\n");
    }
    else
    {
    printf("|     Informatique     |%.2f   |     3.0      |%.2f   |\n",note,note*3.0);
    }
}
void affichercolorELECTRI(float note )
{
    if (note<10)
    {
      textcolor(YELLOW);
    cprintf("|     Eléctricité      |%.2f    |     2.0      |%.2f   |",note,note*2.0);
    printf("\n");
    }
    else
    {
     printf("|     Eléctricité      |%.2f   |     2.0      |%.2f   |\n",note,note*2.0);
    }
}

void affichercolorCIRCUIT(float note )
{
    if (note<10)
    {
      textcolor(YELLOW);
    cprintf("|  Circuit Numérique   |%.2f    |     2.0      |%.2f   |",note,note*2.0);
    printf("\n");
    }
    else
    {
     printf("|  Circuit Numérique   |%.2f   |     2.0      |%.2f   |\n",note,note*2.0);
    }
}
void affichercolorDROIT(float note )
{
    if (note<10)
    {
      textcolor(YELLOW);
      cprintf("|        Droit         |%.2f    |     1.0      |%.2f    |",note,note);
      printf("\n");
    }
    else
    {
     printf("|        Droit         |%.2f   |     1.0      |%.2f   |\n",note,note);
    }
}
void affichermoyen(float c,float a,float b,float j,float k,float m )
{
    int i;
   float moy,s;
    s=(c*1.5)+(j*1.5)+(a*3)+(b*2)+(m*2)+(k);
    moy=s/11;
    if (moy < 10)
    {
         for (i = 0; i <5; i++)
        {

        textcolor(RED);
        cprintf("\r\r             Moyenne                           |%.2f    |",moy);
        sleep(1);
        printf("\r                                                                                      ");  // Effacer le texte
        sleep(1);
        printf("\a");

        }

        textcolor(RED);
        cprintf("\r\r                        Moyenne                |%.2f    |",moy);
        printf("\n");
        printf("                                               |________|\n");
        textcolor(RED);
        cprintf("REDOUBLANT\n");

     }
    else
    {
     printf("|                    Moyenne                   |%.2f   |\n",moy);
     printf("                                               |________|\n");
      if (moy>10 && moy<12)
        {
         printf("\n");
         printf("\n");
         printf("PASSABLE\n");
        }
      if (moy>12 && moy<15)
        {
         printf("\n");
         printf("\n");
         printf("ASSEZ BIEN \n");
        }
      if (moy>15 && moy<16)
        {
         printf("\n");
         printf("\n");
         printf("BIEN \n");
        }
      if (moy>=16)
        {
         printf("\n");
         printf("\n");
         printf("TRES BIEN \n");
        }
    }
}

void afficherEtudiant(int x)
{
    int choix;

    do {  clrscr();
        printf("1 - Afficher le bulletin\n");
        printf("2 - Retour\n");
        printf("3 - Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                clrscr();

   printf("Nom : %s\t    Prénom : %s\t     Matricule : %d\n", noms[x], prenoms[x], matricules[x]);

   printf(" ______________________ ________ ______________ ________\n");
   printf("|                      |        |              |        |\n");
   printf("|       MATIERE        |  NOTE  | COEFFICIENT  |  NOTE  |\n");
   printf("|______________________|________|______________|________|\n");
   printf("|                      |        |              |        |\n");
   affichercolorFRAN(Fnotes[x]);
   printf("|______________________|________|______________|________|\n");
   printf("|                      |        |              |        |\n");
   affichercolorANG(Anotes[x]);
   printf("|______________________|________|______________|________|\n");
   printf("|                      |        |              |        |\n");
   affichercolorINFO(Inotes[x]);
   printf("|______________________|________|______________|________|\n");
   printf("|                      |        |              |        |\n");
   affichercolorELECTRI(Enotes[x]);
   printf("|______________________|________|______________|________|\n");
   printf("|                      |        |              |        |\n");
   affichercolorCIRCUIT(Cnotes[x]);
   printf("|______________________|________|______________|________|\n");
   printf("|                      |        |              |        |\n");
   affichercolorDROIT(Dnotes[x]);
   printf("|______________________|________|______________|________|\n");
   printf("                                               |        |\n");
   affichermoyen(Fnotes[x],Anotes[x],Inotes[x],Enotes[x],Cnotes[x],Dnotes[x] );

      getch();
                break;
            case 2:
                return;
                break;
            case 3:
                clrscr();
                printf("Au revoir !\n");
              break;
            default:
                printf("choix invalide");
        }
    } while (choix != 3);
}
void affichernotes(char noms[][MAX_NOM],char prenoms[][MAX_PRENOM],float *T, int n)
{
     float i;

    for (i = 0; i < n; i++)
    {
        printf(" %s  %s \t %.2f \t", noms[i],prenoms[i],T[i]);
        printf("\n");
    }
}
void noteparmatiere()
{
    int choix;

    do {

        printf("Entrez le numéro de la matière a afficher :\n");
        printf("1 - Français\n");
        printf("2 - Anglais\n");
        printf("3 - Informatique\n");
        printf("4 - Électricité\n");
        printf("5 - Droit\n");
        printf("6 - Circuit numerique\n");
        printf("Entrez votre choix : ");
        printf("7 - RETOUR\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                clrscr();
                printf("Notes en Français :\n");
                affichernotes(noms,prenoms, Fnotes, nbEtudiants);

                break;

            case 2:
                clrscr();
                printf("Notes en Anglais :\n");
                affichernotes(noms,prenoms,Anotes, nbEtudiants);

                break;

            case 3:
                clrscr();
                printf("Notes en Informatique :\n");
                affichernotes(noms,prenoms,Inotes, nbEtudiants);


                break;

            case 4:
                clrscr();
                printf("Notes en Électricité :\n");
              affichernotes(noms,prenoms,Enotes, nbEtudiants);


                break;

            case 5:
                clrscr();
                printf("Notes en Droit :\n");
                affichernotes(noms,prenoms,Dnotes, nbEtudiants);

                 break;
            case 6:
                clrscr();
                printf("Notes en Circuit numerique :\n");
                affichernotes(noms,prenoms,Cnotes, nbEtudiants);

                 break;

            default:
                clrscr();
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 7);
}

   void bulletinparetudiant()
 {
    int matricule, x;

    printf("Saisissez le matricule de l'étudiant : ");
    scanf("%d", &matricule);

    x = rechercherEtudiant(matricule);

    if (x == -1)
    {
        printf("Aucun étudiant avec le matricule %d n'a été trouvé.\n", matricule);
        return;
    }

    printf("Bulletin de l'étudiant avec le matricule %d :\n", matricule);
    afficherEtudiant(x);
}
void bulletin()
{
    int choix;
    do {
        printf("1 - bulletin par etudiant\n");
        printf("2 - RETOUR\n");
        printf("3 - QUITTER\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                clrscr();
                bulletinparetudiant();
                break;

            case 2:
                clrscr();
                return;

            case 3:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

    }while(choix!=3);
}
