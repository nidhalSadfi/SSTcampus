#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexparser.h"

/***************************************************************************
*Programmeur	:   Mohamed KHADRAOUI
*Date			:   27 Octobre 2004
*Module		:       Campuslex
*Commentaires  :	analyseur lexicale
***************************************************************************/
//Function template
int lireFichier(char sFichier[], char fstr[]);
///////////////////////////////////////////////
int main()
{
      char sFichierProg[256];
      //lecture du fichier source
      printf("veuillez introduire votre fichier programme :");
      scanf("%s",sFichierProg);
      char strSource[1024];
      int ret = lireFichier(sFichierProg,strSource);
      if (ret != 0)
        return -1;
      //amorcer analyseur lexical
      initLexParser(sFichierProg);
      startLexParser();

      //demander la génération
      char sFichierOut[256];
      sprintf(sFichierOut,"%s%s","output_",sFichierProg);
      dumpLexParser(sFichierOut);
      char cRet[4];
      //arrêter l'analyseur lexical
      libererLexParser();
      printf("Analyse léxicale terminée \nVoulez vous consulter le fichier (O/N):%s =>",sFichierOut);
      scanf("%s",cRet);
      printf("%s\n",cRet);
      if ((cRet[0] == 'o')||(cRet[0] == 'O'))
	  {
         char strDest[4096];
         lireFichier(sFichierOut,strDest);
         printf("Résulat de compilation :\n%s",strDest);
	  }
    return 0;
}

/***************************************************************************
***
*** Nom de fonction: lireFichier char strSource[1024];
***
*** Description:     lecture d'un fichier et sauvegarde du contenu dans un
***                  buffeur
*** Param sortie:    buffeur de caractères lus
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
int lireFichier(char sFichier[], char fstr[])
{
    char filename[256];
    //strcpy(filename, __FILE__);
    strcpy(filename, sFichier);
    FILE *fh;
    //open and get the file handle
    fh = fopen(filename, "r");

//check if file exists
    if (fh == NULL)
    {
        printf("file does not exists %s", filename);
        return 1;
    }


//read line by line
    const size_t line_size = 300;
    char* line = malloc(line_size);
    strcpy(fstr,"");
    while (fgets(line, line_size, fh) != NULL)
    {
        strcat(fstr,line);
    }
    free(line);    // dont forget to free heap memory
    fclose(fh);
    return 0;
}
