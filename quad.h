#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int qc; 

typedef struct qdr  
{
	char operation[100]; // l'operation
	char opr1[100];     // 1er operande
	char opr2[100];    // 2eme operande
	char tempo[100];  // temporaire 
} qdr;

qdr quad[100]; 

// creation et remplissage du quadruplet
void remplir_quad(char opr[], char opr1[], char opr2[], char tempo[]) 
{
	strcpy(quad[qc].operation, opr); 
	strcpy(quad[qc].opr1, opr1);
	strcpy(quad[qc].opr2, opr2);
	strcpy(quad[qc].tempo, tempo);

	qc++;  
}

// mise a jour d'une colonne du quadruplet
void mise_jr_quad(int num_quad, int colonne_quad, char val[]) // au lieu de QUAD(num_quad)=(val,colone)
{
	if (colonne_quad == 1)
		strcpy(quad[num_quad].operation, val); // remplir la 1ere colonne 
	else if (colonne_quad == 2)
		strcpy(quad[num_quad].opr1, val); // remplir la 2eme colonne 
	else if (colonne_quad == 3)
		strcpy(quad[num_quad].opr2, val); // remplir la 3eme colonne 
	else if (colonne_quad == 4)
		strcpy(quad[num_quad].tempo, val); // remplir la 4eme colonne 
}

void affiche_quad()
{
	printf("\n~~~~~~~~~~~~~~~~~~~~ Les Quadruplets ~~~~~~~~~~~~~~~~~~~~\n");

	int i;

	for (i = 0; i < qc; i++) 
	{

		printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )", i, quad[i].operation, quad[i].opr1, quad[i].opr2, quad[i].tempo);
		printf("\n--------------------------------------------\n");
	}
}
