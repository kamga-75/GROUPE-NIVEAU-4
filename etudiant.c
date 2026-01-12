//c'est ici que chacun colle son bout de code
#include <stdio.h>
#include <string.h>
#include "etudiant.h"

void viderBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// FONCTION 1 : AJOUTER UN ÉTUDIANT


void ajouter(Etudiant etudiants[], int *nb) {
    if (*nb >= MAX_ETUDIANTS) {
        printf("Le tableau est plein !\n");
        return;
    }
    
    printf("\n AJOUT D'UN ETUDIANT \n");
    
    printf("Nom : ");
    scanf("%s", etudiants[*nb].nom);
    
    printf("Prenom : ");
    scanf("%s", etudiants[*nb].prenom);
    
    printf("Jour de naissance : ");
    scanf("%d", &etudiants[*nb].date_naissance.jour);
    
    printf("Mois de naissance : ");
    scanf("%d", &etudiants[*nb].date_naissance.mois);
    
    printf("Annee de naissance : ");
    scanf("%d", &etudiants[*nb].date_naissance.annee);
    
    printf("Departement : ");
    scanf("%s", etudiants[*nb].departement);
    
    printf("Filiere : ");
    scanf("%s", etudiants[*nb].filiere);
    
    printf("Matricule : ");
    scanf("%s", etudiants[*nb].matricule);
    
    printf("Region d'origine : ");
    scanf("%s", etudiants[*nb].region_origine);
    
    (*nb)++;
    printf("\nEtudiant ajoute avec succes !\n");
}
// FONCTION 2 : MODIFIER UN ÉTUDIANT


void modifier(Etudiant etudiants[], int nb) {
    char mat[20];
    Etudiant *p = NULL;  
    
    printf("\n MODIFICATION \n");
    printf("Matricule de l'etudiant : ");
    scanf("%s", mat);
    
    // Recherche de l'étudiant avec pointeur
    for (int i = 0; i < nb; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
            p = &etudiants[i];  // Le pointeur pointe sur l'étudiant trouvé
            break;
        }
    }
    
    if (p == NULL) {
        printf("Etudiant non trouve !\n");
        return;
    }

// FONCTION 3 : RECHERCHER PAR MATRICULE



// FONCTION 4 : SUPPRIMER UN ÉTUDIANT
void supprimer(Etudiant etudiants[], int *nb) {
    char mat[20];
    int trouve = -1;
    
    printf("\n SUPPRESSION \n");
    printf("Matricule de l'etudiant a supprimer : ");
    scanf("%s", mat);
    
    for (int i = 0; i < *nb; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
            trouve = i;
            break;
        }
    }
    
    if (trouve == -1) {
        printf("Etudiant non trouvé !\n");
        return;
    }
    
    // Décalage des éléments
    for (int j = trouve; j < *nb - 1; j++) {
        etudiants[j] = etudiants[j + 1];
    }
    
    (*nb)--;
    printf("Etudiant supprime avec succes !\n");
}




// FONCTION 5 : TRIER PAR NOM
void trierNom(Etudiant etudiants[], int nb) {
    Etudiant temp;
    
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("\nListe trieé par nom !\n");
}


// FONCTION 6 : RECHERCHE DICHOTOMIQUE
void rechercheDicho(Etudiant etudiants[], int nb) {
    char mat[20];
    int debut = 0, fin = nb - 1, milieu;
    int trouve = -1;
    
    printf("\n RECHERCHE DICHOTOMIQUE \n");
    printf("Le tableau doit etre trie par matricule !\n");
    printf("Matricule à rechercher : ");
    scanf("%s", mat);
    
    while (debut <= fin && trouve == -1) {
        milieu = (debut + fin) / 2;
        
        int cmp = strcmp(etudiants[milieu].matricule, mat);
        
        if (cmp == 0) {
            trouve = milieu;
        } else if (cmp < 0) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
    
    if (trouve == -1) {
        printf("Etudiant non trouve !\n");
    } else {
        printf("Etudiant trouve : %s %s\n", 
               etudiants[trouve].nom, etudiants[trouve].prenom);
    }
}

// FONCTION 7 : CALCULER L'ÂGE
void calculerAge(Etudiant etudiants[], int nb) {
    char mat[20];
    int trouve = -1;
    
    printf("\n CALCUL DE L'AGE \n");
    printf("Matricule de l'etudiant : ");
    scanf("%s", mat);
    
    for (int i = 0; i < nb; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
            trouve = i;
            break;
        }
    }
    
    if (trouve == -1) {
        printf("Etudiant non trouve !\n");
    } else {
        int age = 2026 - etudiants[trouve].date_naissance.annee;
        printf("L'etudiant %s %s a %d ans\n", 
               etudiants[trouve].nom, 
               etudiants[trouve].prenom, 
               age);
    }
}

// FONCTION 8 : TRIER PAR FILIÈRE
void trierFiliere(Etudiant etudiants[], int nb) {
    Etudiant temp;
    
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcmp(etudiants[i].filiere, etudiants[j].filiere) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("\nListe trieé par filiere !\n");
}

// FONCTION 9 : AFFICHER TOUS LES ÉTUDIANTS
void afficher(Etudiant etudiants[], int nb) {
    if (nb == 0) {
        printf("\nAucun etudiant enregistre.\n");
        return;
    }
    
    printf("\n LISTE DES ETUDIANTS \n");
    printf("Nombre total : %d\n\n", nb);
    
    for (int i = 0; i < nb; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("  Nom         : %s\n", etudiants[i].nom);
        printf("  Prenom      : %s\n", etudiants[i].prenom);
        printf("  Date naissance. : %d/%d/%d\n", 
               etudiants[i].date_naissance.jour,
               etudiants[i].date_naissance.mois,
               etudiants[i].date_naissance.annee);
        printf("  Departement : %s\n", etudiants[i].departement);
        printf("  Filiere     : %s\n", etudiants[i].filiere);
        printf("  Matricule   : %s\n", etudiants[i].matricule);
        printf("  Region      : %s\n\n", etudiants[i].region_origine);
    }
}

// MENU
void menu() {
    printf("\n===== MENU =====\n");
    printf("1. Ajouter\n");
    printf("2. Modifier\n");
    printf("3. Rechercher\n");
    printf("4. Supprimer\n");
    printf("5. Trier par nom\n");
    printf("6. Recherche dichotomique\n");
    printf("7. Calculer age\n");
    printf("8. Trier par filiere\n");
    printf("9. Afficher tous\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}
