%{
	#include "syntaxique.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern int nb_line;
	extern int nb_character;
	extern char *file_name;
	extern YYSTYPE yylval;
	char x[20];
	extern int emp;
%}
letter [a-zA-Z]
number [0-9]
IDF {letter}({letter}|{number})*
integer [-]?{number}+
real [-]?{number}+"."{number}+
character "\"".+"\""
boolean "TRUE"|"FALSE"
commentaire %[^;]+;
%%

PROGRAM { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwPROGRAM;}
END { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwEND;}
ROUTINE {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwROUTINE;}
ENDR { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwENDR;}
CALL { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwCALL;}
CHARACTER {
	ECHO; 
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwCHARACTER;}
INTEGER {
	ECHO; 
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwINTEGER;}
REAL { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwREAL;}
LOGICAL { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwLOGICAL;}
READ { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwREAD;}
WRITE { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwWRITE;}
IF { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwIF;}
THEN { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwTHEN;}
ELSE { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwELSE;}
ENDIF { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwENDIF;}
DOWHILE {
	ECHO; 
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwDOWHILE;}
ENDDO { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwENDDO;}
EQUIVALENCE {
	ECHO; 
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwEQUIVALENCE;}
OR {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwOR;}
AND { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwAND;}
GT { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwGT;}
GE { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwGE;}
EQ {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwEQ;}
LE { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwLE;}
LT { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwLT;}
NE { 
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwNE;}
DIMENSION {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Mot cle","-1","-1","-1","-1","-1","-1",1);
	yylval.str=strdup(yytext);
	return kwDIMENSION;}

{boolean} {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Idf","LOGICAL","/","/","/","/","/",0);
	yylval.str=strdup(yytext);
	return boolean;
}
{real} {
	if (atof(yytext) >= -32768.32767 && atof(yytext) <= 32767.32767) {
		ECHO;
		nb_character += strlen(yytext);
		rechercher(yytext,"Cst","REAL","/","/","/","/","/",0);
		yylval.str=strdup(yytext);
		return real;
	}
	else{
		printf("File '%s', line %d, character %d: lexical error\n",file_name,nb_line,nb_character);
	}
}
{integer} {	
	if (atoi(yytext) >= -32768 && atoi(yytext) <= 32767) { 
		ECHO;
		nb_character += strlen(yytext);
		rechercher(yytext,"Cst","INTEGER","/","/","/","/","/",0);
		yylval.str=strdup(yytext);
		return integer;
    } 
	else{
		printf("File '%s', line %d, character %d: lexical error\n",file_name,nb_line,nb_character);
	}	
}
{character} {
	ECHO;
	nb_character += strlen(yytext);
	sprintf(x,"%d",strlen(yytext)-2);
	rechercher(yytext,"Idf","CHARACTER","/",x,"/","/","/",0);
	yylval.str=strdup(yytext);
	return character;
}
{IDF} {
	if(strlen(yytext)>10){		
		printf("File '%s', line %d, character %d: lexical error\n",file_name,nb_line,nb_character);
	}
	else{
		ECHO;
		nb_character += strlen(yytext);
		if (emp==0)
			rechercher(yytext,"Idf","-1","-1","-1","-1","-1","GLOBAL",0);
		else {
			sprintf(x,"LOCAL %d",emp); rechercher(yytext,"Idf","-1","-1","-1","-1","-1",x,0);
		}
		yylval.str=strdup(yytext);
		return idf;
	}
}

"+" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return plus;}
"-" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return minus;}
"*" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return mul;}
"/" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return divi;}
"=" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return aff;}
";" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return pvg;}
"(" {
    ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return po;}
")" {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return pf;}
"." {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return pt;}
"," {
	ECHO;
	nb_character += strlen(yytext);
	rechercher(yytext,"Separateur","-1","-1","-1","-1","-1","-1",2);
	yylval.str=strdup(yytext);
	return vg;}

{commentaire} {
	ECHO;
	nb_character += strlen(yytext);
}

[ \t] {
	ECHO;
	nb_character += strlen(yytext);
}

\n {ECHO; nb_line++; nb_character=0;}

. {
	nb_character += strlen(yytext);
	printf("File '%s', line %d, character %d: lexical error\n",file_name,nb_line,nb_character);
}


