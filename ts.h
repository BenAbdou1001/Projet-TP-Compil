#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definition des structures de données

typedef struct ElementNode {
    int state;
    char name[96];
    char code[20];
    char type[20];
    char val[20];
    char taille[20];
    char ligne[20];
    char colonne[20];
    char emplacement[20];
    char update[20];
    struct ElementNode* next;
} ElementNode;

typedef struct KeywordNode {
    int state;
    char name[20];
    char type[20];
    struct KeywordNode* next;
} KeywordNode;

typedef struct SeparatorNode {
    int state;
    char name[20];
    char type[20];
    struct SeparatorNode* next;
} SeparatorNode;

typedef struct SymbolTables {
    ElementNode* tab;
    KeywordNode* tabm;
    SeparatorNode* tabs;
} SymbolTables;

SymbolTables table; 

extern char save[20];

// Initialisation de l'état des cases des tables des symboles
void initialisation() {
    table.tab = NULL;
    table.tabm = NULL;
    table.tabs = NULL;
}

// Insertion des entités lexicales dans les tables des symboles
void inserer(char entite[], char code[], char type[], char val[],char taille[],char ligne[],char colonne[],char emplacement[], int y) {
    switch (y) {
        case 0: { // insertion dans la table des IDF et CONST
            ElementNode* newNode = (ElementNode*)malloc(sizeof(ElementNode));
            if (newNode == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            newNode->state = 1;
            strcpy(newNode->name, entite);
            
            strcpy(newNode->code," ");
            strcpy(newNode->type," ");
            strcpy(newNode->val," ");
            strcpy(newNode->taille," ");
            strcpy(newNode->ligne," ");
            strcpy(newNode->colonne," ");
            strcpy(newNode->emplacement," ");
            strcpy(newNode->update,"LEXICAL");
            
            if (strcmp(code,"-1")!=0){
                strcpy(newNode->code, code);
            }
            if (strcmp(type,"-1")!=0){
                strcpy(newNode->type, type);
            }
            if (strcmp(val,"-1")!=0){
                strcpy(newNode->val,val);
            }
            if (strcmp(taille,"-1")!=0){
                strcpy(newNode->taille,taille);
            }
            if (strcmp(ligne,"-1")!=0){
                strcpy(newNode->ligne,ligne);
            }
            if (strcmp(colonne,"-1")!=0){
                strcpy(newNode->colonne,colonne);
            }
            if (strcmp(emplacement,"-1")!=0){
                strcpy(newNode->emplacement,emplacement);
            }

            newNode->next = NULL; 
            if (table.tab == NULL) {
                table.tab = newNode;
            } else {
                ElementNode* current = table.tab;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }

            break;
        }

        case 1: { // insertion dans la table des mots clés
            KeywordNode* newNode = (KeywordNode*)malloc(sizeof(KeywordNode));
            if (newNode == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            newNode->state = 1;
            strcpy(newNode->name, entite);
            strcpy(newNode->type, code);
            
            newNode->next = NULL; 
            if (table.tabm == NULL) {
                table.tabm = newNode;
            } else {
                KeywordNode* current = table.tabm;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
            break;
        }

        case 2: { // insertion dans la table des séparateurs
            SeparatorNode* newNode = (SeparatorNode*)malloc(sizeof(SeparatorNode));
            if (newNode == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            newNode->state = 1;
            strcpy(newNode->name, entite);
            strcpy(newNode->type, code);

            newNode->next = NULL;  
            if (table.tabs == NULL) {
                table.tabs = newNode;
            } else {
                SeparatorNode* current = table.tabs;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
            break;
        }
    }
}

void miseajour(char entite[], char code[], char type[], char val[],char taille[],char ligne[],char colonne[],char emplacement[],char update[]) {

    ElementNode* current = table.tab;
    while (current != NULL) {
        if ( strcmp(entite, current->name) == 0 && (strcmp(emplacement,current->emplacement) == 0 || strcmp(emplacement,"-1") == 0)) {
            if (strcmp(code,"-1")!=0){
                strcpy(current->code, code);
                strcpy(current->update,update);
            }
            if (strcmp(type,"-1")!=0){
                strcpy(current->type, type);
                strcpy(current->update,update);
            }
            if (strcmp(val,"-1")!=0){
                strcpy(current->val,val);
                strcpy(current->update,update);
            }
            if (strcmp(taille,"-1")!=0){
                strcpy(current->taille,taille);
                strcpy(current->update,update);
            }
            if (strcmp(ligne,"-1")!=0){
                strcpy(current->ligne,ligne);
                strcpy(current->update,update);
            }
            if (strcmp(colonne,"-1")!=0){
                strcpy(current->colonne,colonne);
                strcpy(current->update,update);
            }
        }
        current = current->next;
    } 
}

// La fonction Rechercher permet de vérifier si l'entite existe deja dans la table des symboles
void rechercher(char entite[], char code[], char type[], char val[],char taille[],char ligne[],char colonne[],char emplacement[], int y) {

    switch (y) {
        case 0: // vérifier si la case dans la table des IDF et CONST est libre
        {
            ElementNode* current = table.tab;
            while (current != NULL && (strcmp(entite, current->name) != 0)) {
                current = current->next;
            }

            if (current == NULL) {
                inserer(entite, code, type, val,taille,ligne,colonne,emplacement,0);
            }
            else{
                if (strcmp(emplacement,current->emplacement)!=0){
                    current = current->next;
                    while (current != NULL && (strcmp(emplacement, current->emplacement) != 0)) {
                        current = current->next;
                    }
                    if(current == NULL){
                        inserer(entite, code, type, val,taille,ligne,colonne,emplacement,0);
                    }
                    else{
                        current = current->next;
                        while (current != NULL && (strcmp(entite, current->name) != 0)) {
                            current = current->next;
                        }
                        if (current == NULL) {
                            inserer(entite, code, type, val,taille,ligne,colonne,emplacement,0);
                        }
                    } 
                }
            }
            break;
        }

        case 1: // vérifier si la case dans la table des mots clés est libre
        {
            KeywordNode* current = table.tabm;
            while (current != NULL && (strcmp(entite, current->name) != 0)) {
                current = current->next;
            }

            if (current == NULL) {
                inserer(entite, code, type, val,taille,ligne,colonne,emplacement,1);
            } 
            break;
        }

        case 2: // vérifier si la case dans la table des séparateurs est libre
        {
            SeparatorNode* current = table.tabs;
            while (current != NULL && (strcmp(entite, current->name) != 0)) {
                current = current->next;
            }

            if (current == NULL) {
                inserer(entite, code, type, val,taille,ligne,colonne,emplacement,2);
            }
            break;
        }
        
        case 3: // mise a jour des idf des fonctions appelées et des messages
        {
            ElementNode* current = table.tab;
            while (current != NULL && (strcmp(entite, current->name) != 0) && (strcmp(code,current->code) != 0 && strcmp(emplacement,current->emplacement)!=0)) {
                current = current->next;
            }

            if (current != NULL) {
                if (strcmp(type,current->type) == 0)
                {
                    miseajour(entite,"Message de sortie","-1",val,taille,ligne,colonne,emplacement,"SYNTAXIQUE");
                }
                else{
                    miseajour(entite,"Appel fonction",type,val,taille,ligne,colonne,emplacement,"SYNTAXIQUE");
                }
            }
            break;
        }
    }
}

// verifier si l'idf existe dans la ts
bool idf_existe(char entite[],int emp,char code[]){
    char emplacement[20];
    ElementNode* current = table.tab;
    if(emp != -1){
        if (emp==0)
            strcpy(emplacement,"GLOBAL");
        else {
            sprintf(emplacement,"LOCAL %d",emp); 
        }
        while (current != NULL && (strcmp(entite, current->name) != 0 || strcmp(emplacement,current->emplacement) != 0 || strcmp(code,current->code) != 0)) {
            current = current->next;
        }
    }
    else {
        while (current != NULL && (strcmp(entite, current->name) != 0 || strcmp(code,current->code) != 0)) {
            current = current->next;
        }
    }
    if (current != NULL) {
        return true;
    }
    return false;
}

// retourner le type d'un idf
char* getType(char entite[],int emp,char code[]){
    char emplacement[20];
    ElementNode* current = table.tab;
    if(emp != -1){
        if (emp==0)
            strcpy(emplacement,"GLOBAL");
        else {
            sprintf(emplacement,"LOCAL %d",emp); 
        }
        while (current != NULL && (strcmp(entite, current->name) != 0 || strcmp(emplacement,current->emplacement) != 0 || strcmp(code,current->code) != 0)) {
            current = current->next;
        }
    }
    else {
        while (current != NULL && (strcmp(entite, current->name) != 0 || strcmp(code,current->code) != 0)) {
            current = current->next;
        }
    }
    if (current != NULL) {
        return current->type;
    }
    else{
        return "NULL";
    }
}

// verifie si l'indice du tableau existe selon sa dimension
bool verif_index(char entite[],int emp,char code[],char index[],char check[]){
    char emplacement[20];
    if (emp==0)
        strcpy(emplacement,"GLOBAL");
    else {
        sprintf(emplacement,"LOCAL %d",emp); 
    }
    ElementNode* current = table.tab;
    while (current != NULL && (strcmp(entite, current->name) != 0 || strcmp(emplacement,current->emplacement) != 0 || strcmp(code,current->code) != 0)) {
        current = current->next;
    }
    if (current != NULL) {
        if(atof(current->ligne)>=atof(index) && strcmp(check,"Ligne")==0)
            return true;
        if(atof(current->colonne)>=atof(index) && strcmp(check,"Colonne")==0)
            return true;
    }
    return false;
}

// compare la taille d'une var de type char dans la ts avec la taille d'une chaine en argument (char check[])
bool verif_char(char entite[],int emp,char code[],char check[]){
    char emplacement[20];
    if (emp==0)
        strcpy(emplacement,"GLOBAL");
    else {
        sprintf(emplacement,"LOCAL %d",emp); 
    }
    ElementNode* current = table.tab;
    while (current != NULL && (strcmp(entite, current->name) != 0 || strcmp(emplacement,current->emplacement) != 0 || strcmp(code,current->code) != 0)) {
        current = current->next;
    }
    if (current != NULL) {
        if(atof(current->taille)>=strlen(check)-2)
            return true;
    }
    return false;
}

bool verif_param(char entite[],int nb_param){
    char emplacement[20];
    ElementNode* current = table.tab;
    while (current != NULL && (strcmp(entite, current->name) != 0 ||  strcmp("Fonction",current->code) != 0)) {
        current = current->next;
    }
    if (current != NULL) {
        if(atof(current->taille)==nb_param)
            return true;
    }
    return false;
}

// L'affichage du contenu de la table des symboles
void afficher() {
    // Affichage de la table des symboles IDF et cst
    ElementNode* current = table.tab;
    printf("/*************************Table des symboles IDF et constantes*************************/\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________\n");
    printf("\t|\t\t   Nom_Entite    \t\t| \tCode_Entite\t| Type_Entite |  Val_Entite  |  Taille  |  Lignes  | Colonnes |  Emplacement |  Last update |\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________\n");

    while (current != NULL) {
        printf("\t| %45s |  %20s | %11s | %12s | %8s | %8s | %8s | %12s | %12s |\n", current->name, current->code, current->type, current->val,current->taille,current->ligne,current->colonne,current->emplacement,current->update);
        current = current->next;
    }

    // Affichage de la table des symboles mots clés
    KeywordNode* currentKeyword = table.tabm;
    printf("\n/*************************Table des symboles mots cles*************************/\n");
    printf("_____________________________________\n");
    printf("\t|  NomEntite  |  CodeEntite | \n");
    printf("_____________________________________\n");

    while (currentKeyword != NULL) {
        printf("\t|%12s |%12s | \n", currentKeyword->name, currentKeyword->type);
        currentKeyword = currentKeyword->next;
    }

    // Affichage de la table des symboles séparateurs
    SeparatorNode* currentSeparator = table.tabs;
    printf("\n/*************************Table des symboles separateurs*************************/\n");
    printf("___________________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("___________________________________\n");

    while (currentSeparator != NULL) {
        printf("\t|%10s |%12s | \n", currentSeparator->name, currentSeparator->type);
        currentSeparator = currentSeparator->next;
    }
}

//diviser une chaine en 2 parties avec le separateur "-" Exemple:(chaine="text-test" -> partie1="text" partie2="test")
void diviserChaine(const char *chaine, char *partie1, char *partie2) {
    // Recherche de la position du séparateur "-"
    const char *separateur = strchr(chaine, '-');

    if (separateur) {
        // Calcul de la longueur de la première partie
        size_t longueurPartie1 = separateur - chaine;

        // Copie de la première partie dans partie1
        strncpy(partie1, chaine, longueurPartie1);
        partie1[longueurPartie1] = '\0';  // Ajout du caractère de fin de chaîne

        // Copie de la deuxième partie dans partie2
        strcpy(partie2, separateur + 1);
    } else {
        // Si le séparateur n'est pas trouvé, partie1 reçoit la chaîne entière
        strcpy(partie1, chaine);
        partie2[0] = '\0';  // La deuxième partie est une chaîne vide
    }
}


