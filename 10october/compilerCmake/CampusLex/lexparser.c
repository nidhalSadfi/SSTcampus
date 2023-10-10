/***************************************************************************
/Programmeur	:   Mohamed KHADRAOUI
/Date			:     27 Octobre 2004
/Module		:     lexparser.c
/Commentaires  :	module de parsing de l'application estilex
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#ifdef _WINDOWS
#include <windows.h>
#endif // _WINDOWS

#include "lexparser.h"


/** Etats de l'automate  **/
#define   C_ETATAUTO_ECHAP        (TNUTI_ETATAUTO)0
#define   C_ETATAUTO_ENTIER       (TNUTI_ETATAUTO)1
#define   C_ETATAUTO_IDENT        (TNUTI_ETATAUTO)2
#define   C_ETATAUTO_IDENTERR     (TNUTI_ETATAUTO)3
#define   C_ETATAUTO_APRESVIRG    (TNUTI_ETATAUTO)4
#define   C_ETATAUTO_DECIMAL      (TNUTI_ETATAUTO)5
#define   C_ETATAUTO_DECIMERR     (TNUTI_ETATAUTO)6
#define   C_ETATAUTO_CHAINE       (TNUTI_ETATAUTO)7
#define   C_ETATAUTO_ERRUNITE     (TNUTI_ETATAUTO)8

/** Evenements de l'automate  **/
#define   C_EVTAUTO_CHIFFRE         (TNUTI_EVTAUTO)0
#define   C_EVTAUTO_LETTRE          (TNUTI_EVTAUTO)1
#define   C_EVTAUTO_POINTDEC        (TNUTI_EVTAUTO)2
#define   C_EVTAUTO_GUILLEMET       (TNUTI_EVTAUTO)3
#define   C_EVTAUTO_SEPARATEUR      (TNUTI_EVTAUTO)4
#define   C_EVTAUTO_RETCHARIOT      (TNUTI_EVTAUTO)5
#define   C_EVTAUTO_EOF             (TNUTI_EVTAUTO)6
#define   C_EVTAUTO_INCONNUE        (TNUTI_EVTAUTO)7

/** Déclaration des actions de l'automate  **/
TNUTI_ETATAUTO   LEX_AUTOEchappement    (TSUTI_CTXT_AUTO *, LPVOID); // A0
TNUTI_ETATAUTO   LEX_AUTOCumul          (TSUTI_CTXT_AUTO *, LPVOID); // A1
TNUTI_ETATAUTO   LEX_AUTOTraitEntier    (TSUTI_CTXT_AUTO *, LPVOID); // A2
TNUTI_ETATAUTO   LEX_AUTOTraitIdentif   (TSUTI_CTXT_AUTO *, LPVOID); // A3
TNUTI_ETATAUTO   LEX_AUTOTraitIdentifErr(TSUTI_CTXT_AUTO *, LPVOID); // A4
TNUTI_ETATAUTO   LEX_AUTOTraitDecimal   (TSUTI_CTXT_AUTO *, LPVOID); // A5
TNUTI_ETATAUTO   LEX_AUTOTraitDecimalErr(TSUTI_CTXT_AUTO *, LPVOID); // A6
TNUTI_ETATAUTO   LEX_AUTOTraitChaine    (TSUTI_CTXT_AUTO *, LPVOID); // A7
TNUTI_ETATAUTO   LEX_AUTOTraitChaineErr (TSUTI_CTXT_AUTO *, LPVOID); // A8
TNUTI_ETATAUTO   LEX_AUTOTraitErrUnite  (TSUTI_CTXT_AUTO *, LPVOID); // A9

/** tableau d'appel indirect (générique) des actions de l'automate  **/
TNUTI_ETATAUTO (*tgActionAnalex[])(TSUTI_CTXT_AUTO *, void *) =
{
   LEX_AUTOEchappement            ,   // A0
   LEX_AUTOCumul                  ,   // A1
   LEX_AUTOTraitEntier            ,   // A2
   LEX_AUTOTraitIdentif           ,   // A3
   LEX_AUTOTraitIdentifErr        ,   // A4
   LEX_AUTOTraitDecimal           ,   // A5
   LEX_AUTOTraitDecimalErr        ,   // A6
   LEX_AUTOTraitChaine            ,   // A7
   LEX_AUTOTraitChaineErr         ,   // A8
   LEX_AUTOTraitErrUnite              // A9
};

/** Matrice de transition de l'Automate **/
UCHAR tgTableSautAnalex[] =  // definition de la table des sauts
{
// max evt, max etat
   8,       9,

//    0      1       2       3        4          5       6        7       8
// ECHAP  ENTIER   IDENT  IDENTERR APRESVIRG  DECIMAL DECIMERR CHAINE  ERRUNITE
   1, 1,    1, 1,   1, 2,   1, 3,    1, 5,     1, 5,    1, 6,   1, 7,   1, 8,  //CHIFFRE
   1, 2,    1, 3,   1, 2,   1, 3,    1, 6,     1, 6,    1, 6,   1, 7,   1, 8,  //LETTRE
   0, 0,    1, 4,   1, 3,   1, 3,    1, 6,     1, 6,    1, 6,   1, 7,   1, 8,  //POINTDEC
   0, 7,    2, 7,   3, 7,   4, 7,    6, 7,     5, 7,    6, 7,   7, 0,   9, 7,  //GILLEMET
   0, 0,    2, 0,   3, 0,   4, 0,    6, 0,     5, 0,    6, 0,   1, 7,   9, 0,  //SEPARATEUR
   0, 0,    2, 0,   3, 0,   4, 0,    6, 0,     5, 0,    6, 0,   8, 0,   9, 0,  //RETCHARIOT
   0, 0,    2, 0,   3, 0,   4, 0,    6, 0,     5, 0,    6, 0,   8, 0,   9, 0,  //EOF
   1, 8,    1, 8,   1, 8,   1, 8,    1, 8,     1, 8,    1, 8,   1, 7,   1, 8   //INCONNUE
};

/** Variable Contexte globale  **/
TSLEX_CONTEXT	      tAnalLexContext;


/***************************************************************************
***                  Corps des actions de l'automate
***************************************************************************/


/***************************************************************************
***
*** Nom de fonction: LEX_AUTOEchappement
***
*** Description:     ignore le caratère lu sans changer l'état et
***                    met à jour simplement la position dans le fichier
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOEchappement (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 0
   mettreAjourPosition((CHAR)pParam);
   return CNUTI_AUTO_NO_CHG_ETAT;
}

/***************************************************************************
***
*** Nom de fonction: LEX_AUTOCumul
***
*** Description:     accumule le caratère lu dans la structure du symbole en cours
***                  et met à jour la position dans le fichier
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOCumul (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 1
  if (tAnalLexContext.longSymboleCourant < MAX_LONG_SYMBOLE)
  {
    tAnalLexContext.sLibSymboleCourant[tAnalLexContext.longSymboleCourant] = (CHAR)pParam;
    tAnalLexContext.longSymboleCourant++;

    mettreAjourPosition((CHAR)pParam);
    return CNUTI_AUTO_NO_CHG_ETAT;
  }else
  {
    tAnalLexContext.ResRetour = CERR_SYMBOLE_TROP_LONG;
    mettreAjourPosition((CHAR)pParam);

    return CNUTI_AUTO_ETAT_FINAL;
  }
}

/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitEntier
***
*** Description:     reconnait le symbole entier et demande son insertion dans
***                  la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitEntier (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 2
  return insererUniteLex(CUNITE_LEX_ENTIER, (CHAR)pParam);
}

/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitIdentif
***
*** Description:     reconnait le symbole identificateur et demande son insertion dans
***                  la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitIdentif (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 3
  return insererUniteLex(CUNITE_LEX_IDENT, (CHAR)pParam);
}
/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitIdentifErr
***
*** Description:     reconnait le symbole identificateur erroné et demande
***                  son insertion dans la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitIdentifErr (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 4
  return insererUniteLex(CUNITE_LEX_IDENTERR, (CHAR)pParam);
}
/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitDecimal
***
*** Description:     reconnait le symbole décimal et demande son insertion dans
***                  la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitDecimal (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 5
  return insererUniteLex(CUNITE_LEX_DECIMAL, (CHAR)pParam);

}
/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitDecimalErr
***
*** Description:     reconnait le symbole decimal erroné et demande son insertion dans
***                  la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitDecimalErr (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 6
  return insererUniteLex(CUNITE_LEX_DECIMALERR, (CHAR)pParam);
}
/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitChaine
***
*** Description:     reconnait le symbole chaine et demande son insertion dans
***                  la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitChaine (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 7
  return insererUniteLex(CUNITE_LEX_CHAINE, (CHAR)pParam);
}
/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitChaineErr
***
*** Description:     reconnait le symbole d'une chaine ouverte et demande son insertion dans
***                  la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitChaineErr (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 8
  return insererUniteLex(CUNITE_LEX_CHAINEERR, (CHAR)pParam);
}
/***************************************************************************
***
*** Nom de fonction: LEX_AUTOTraitErrUnite
***
*** Description:     reconnait le symbole d'unité lexical erronée et demande
***                  son insertion dans la table des symboles
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO   LEX_AUTOTraitErrUnite (TSUTI_CTXT_AUTO *c, LPVOID pParam)
{ // action 9
  return insererUniteLex(CUNITE_LEX_ERRUNITE, (CHAR)pParam);
}

/***************************************************************************
***
*** Nom de fonction: insererUniteLex
***
*** Description:     enregistre le symbole en cours dans la table des symboles,
***                  purge la structure du symbole en cours
***                  et met à jour la position dans le fichier
*** Param sortie:    nouvel état de transition
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_ETATAUTO insererUniteLex(TENUM_UNITE_LEX uniteEnum, char cLu)
{
  if ( tAnalLexContext.vNbSymbole < MAX_NB_SYMBOLE )
  {  //rensigenment (insertion) dans la table des symboles

    memcpy(tAnalLexContext.tTabSymbole[tAnalLexContext.vNbSymbole].sLibSymbole,tAnalLexContext.sLibSymboleCourant,tAnalLexContext.longSymboleCourant);
    tAnalLexContext.tTabSymbole[tAnalLexContext.vNbSymbole].sLibSymbole[tAnalLexContext.longSymboleCourant] = 0;
    tAnalLexContext.tTabSymbole[tAnalLexContext.vNbSymbole].tTypeSymbole = uniteEnum;
    tAnalLexContext.tTabSymbole[tAnalLexContext.vNbSymbole].ligne = tAnalLexContext.numLigne;
    tAnalLexContext.tTabSymbole[tAnalLexContext.vNbSymbole].colonne = tAnalLexContext.numColonne - tAnalLexContext.longSymboleCourant + 1;

    tAnalLexContext.vNbSymbole ++;
    //RAZ de la chaine d'accumulation courante
    memset(tAnalLexContext.sLibSymboleCourant,0,tAnalLexContext.longSymboleCourant);
    tAnalLexContext.longSymboleCourant = 0;

    mettreAjourPosition(cLu);
    return CNUTI_AUTO_NO_CHG_ETAT;
  }else
  {
    tAnalLexContext.ResRetour = CERR_SYMBOLE_TROP_LONG;
    mettreAjourPosition(cLu);
    return CNUTI_AUTO_ETAT_FINAL;
  }
}

/***************************************************************************
***
*** Nom de fonction: mettreAjourPosition
***
*** Description:     met à jour le numérode colonne et le nuémaro de ligne si
***                  RC renconté
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void mettreAjourPosition(char cLu)
{
   if (cLu == '\n')
   {
     tAnalLexContext.numLigne++;
     tAnalLexContext.numColonne = 0;
   }else
    tAnalLexContext.numColonne++;
}
/***************************************************************************
***                  Corps des actions de l'automate
***************************************************************************/




/***************************************************************************
***                  Fonctions de l'analyseur lexical
***************************************************************************/

/***************************************************************************
***
*** Nom de fonction: initContext
***
*** Description:     initialise le contexte mémoire de l'analyseur lexical
***
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void initContext(char *sNomFich)
{
	//initailiser le contexte global de l'analyseur
    strcpy(tAnalLexContext.sNomSourceFich,sNomFich);
    tAnalLexContext.pSourceFile = NULL;
    tAnalLexContext.numLigne = 1;
    tAnalLexContext.numColonne = 1;
    tAnalLexContext.ResRetour = CERR_NO_ERROR;
    tAnalLexContext.vNbSymbole = 0;
    strcpy(tAnalLexContext.sLibSymboleCourant ,"");
    tAnalLexContext.longSymboleCourant = 0;
    int i;
    for (i = 0 ; i <= MAX_NB_SYMBOLE ; i++)
    {
      strcpy(tAnalLexContext.tTabSymbole[i].sLibSymbole ,"");
      tAnalLexContext.tTabSymbole[i].tTypeSymbole = CUNITE_LEX_INCONNUE;
    }
}

/***************************************************************************
***
*** Nom de fonction: freeContext
***
*** Description:     libérer le contexte mémoire de l'analyseur lexical
***
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void freeContext()
{
   //libération du contexte mémoire de l'automate
   free (tAnalLexContext.pCtxtAuto);
}

/***************************************************************************
***
*** Nom de fonction: freeContext
***
*** Description:     initialiser le contexte global de l'analyseur lexical
***
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void initLexParser(char *sNomFich)
{
  initContext(sNomFich);
  initAutomate(&tAnalLexContext);
}

/***************************************************************************
***
*** Nom de fonction: libererLexParser
***
*** Description:     libérer le contexte global de l'analyseur lexical
***
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void libererLexParser()
{
  freeContext();
}


/***************************************************************************
***
*** Nom de fonction: startLexParser
***
*** Description:     lancer l'analyse lexical proprement dit
***
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void startLexParser()
{
  FILE *fSourceFile;
  fSourceFile = fopen(tAnalLexContext.sNomSourceFich,"r");
  if (fSourceFile == NULL)
  {//problème d'ouverure de fichier
      tAnalLexContext.ResRetour = CERR_OUVERTURE_DE_FICHIER;
  }else
  {//corps pricipal de l'analyseur lexical
    tAnalLexContext.pSourceFile = fSourceFile;
    char cLu;
    UCHAR uEtat = CNUTI_AUTO_ETAT_INIT;
    do
    {
      cLu = getc(tAnalLexContext.pSourceFile);
      uEtat = moteurAutomate(&tAnalLexContext,getEvent(cLu),(LPVOID)cLu);
      printf("cLu=%c(%d) ",cLu,cLu);
    }while ((cLu != (UCHAR)EOF)&&(uEtat != CNUTI_AUTO_ETAT_FINAL)&&(cLu!=-1));

    //fin de l'analyse => fermeture du fichier source
    fclose(tAnalLexContext.pSourceFile);
  }
}

/***************************************************************************
***
*** Nom de fonction: dumpLexParser
***
*** Description:     étape de génération de l'analyse lexical
***
*** Param sortie:    néant
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
void dumpLexParser(char *sNomFichierDest)
{
  FILE *fDestFile;
  fDestFile = fopen(sNomFichierDest,"w");
  if (fDestFile == NULL)
  {//problème d'ouverture du fichier destination
      return;
  }else
  {
    //ecriture de l'entête
    fprintf(fDestFile,"Campus 2004/2005 - SST \n Résultat de l'Analyse Lexical sur le source:%s\n",
                              tAnalLexContext.sNomSourceFich);
    fprintf(fDestFile,"-----------------------------------------------------------------\n\n");
    fprintf(fDestFile,"%s...\n",getLibResultat(tAnalLexContext.ResRetour));
    int i;
    for (i= 0; i < tAnalLexContext.vNbSymbole; i++)
    {//parcours de la table des symboles
      fprintf(fDestFile,"%04d: <%s | %s> - L%d C%d\n", i,
                    tAnalLexContext.tTabSymbole[i].sLibSymbole,
                    getLibUniteLex(tAnalLexContext.tTabSymbole[i].tTypeSymbole),
                    tAnalLexContext.tTabSymbole[i].ligne,
                    tAnalLexContext.tTabSymbole[i].colonne);
    }
    fclose(fDestFile);
  }
}

/***************************************************************************
***
*** Nom de fonction: initAutomate
***
*** Description:     appel de la fonction d'initialisation de l'automate
***
*** Param sortie:    résultat de l'opération (0 si OK)
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
DWORD  initAutomate (TSLEX_CONTEXT  *plCtxtAnalex)
{
  TCUTI_REFAUTO    clRefAuto;
  DWORD             vlResult;

  plCtxtAnalex->pCtxtAuto = (TSUTI_CTXT_AUTO *) malloc(sizeof (TSUTI_CTXT_AUTO));
  if (plCtxtAnalex->pCtxtAuto == NULL)
    return -1;

  //Initialisation de l'automate CL
  vlResult = UTI_InitAutomate(plCtxtAnalex->pCtxtAuto,           // adresse automate a initialiser
                              tgTableSautAnalex,                 // table des sauts
                              tgActionAnalex,                    // table des actions
                              clRefAuto,                          // nom automate
                              NULL);                               // adresse contexte utilisateur
  if (vlResult != CNUTI_RES_OK)
  {
    free(plCtxtAnalex->pCtxtAuto);
    return vlResult;
  }

  //Initialisation du contexte utilisateur
  plCtxtAnalex->pCtxtAuto->pCtxtUti = (TSLEX_CONTEXT *)plCtxtAnalex;

  return 0;
}

/***************************************************************************
***
*** Nom de fonction: moteurAutomate
***
*** Description:     appel de la fonction démarage de l'automate
***                  le mutext sert pour protéger le contexte de l'automate
***                  contre les accès concurrents via des thread
*** Param sortie:    résultat de l'opération (0 si OK)
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
UCHAR moteurAutomate (TSLEX_CONTEXT  *plCtxtAnalex, TNUTI_EVTAUTO vp_EvtAuto, LPVOID ppParam)
{
   //prise du mutex sur le contexte du CL
   #ifdef _WINDOWS
   WaitForSingleObject(plCtxtAnalex->hCtxtMutexCL, INFINITE);
   #endif // _WINDOWS
   UCHAR vRes;

   if (plCtxtAnalex->pCtxtAuto != NULL)
    vRes = UTI_MoteurAutomate (plCtxtAnalex->pCtxtAuto, vp_EvtAuto, ppParam);

   //Libeartion du mutex sur le contexte
   #ifdef _WINDOWS
    ReleaseMutex(plCtxtAnalex->hCtxtMutexCL);
   #endif

   return vRes;
}


/***************************************************************************
***
*** Nom de fonction: getEvent
***
*** Description:     fonction de traduction du carctère lu en un evenement
***                   de l'automate
*** Param sortie:    évenement automate
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
UCHAR getEvent(char c)
{
  if (c == EOF)
    return C_EVTAUTO_EOF;

  if (c >= '0' && c <= '9')
    return C_EVTAUTO_CHIFFRE;

  if ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c == '_'))
    return C_EVTAUTO_LETTRE;

  if ((c == ' ')||(c == '\t'))
    return C_EVTAUTO_SEPARATEUR;

  if (c == '\n')
    return C_EVTAUTO_RETCHARIOT;

  if ((c == '"'))
    return C_EVTAUTO_GUILLEMET;

  if ((c == '.'))
    return C_EVTAUTO_POINTDEC;

  //autre caractère : + - * / = : ; , ...
  return C_EVTAUTO_INCONNUE;
}

/***************************************************************************
***
*** Nom de fonction: getLibUniteLex
***
*** Description:     dictionnaire de traduction du symbole lu en une chaine
***                   pour la génération
*** Param sortie:    chaine de caratère
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
char *getLibUniteLex(TENUM_UNITE_LEX eUniteLex)
{

    switch(eUniteLex)
    {
      case CUNITE_LEX_ENTIER:
         return "Entier";
      case CUNITE_LEX_IDENT:
         return "Identificateur";
      case CUNITE_LEX_IDENTERR:
         return "Identificateur Erroné";
      case CUNITE_LEX_DECIMAL:
         return "Décimal";
      case CUNITE_LEX_DECIMALERR:
         return "Décimal Erroné";
      case CUNITE_LEX_CHAINE:
         return "Chaine";
      case CUNITE_LEX_CHAINEERR:
         return "Chaine Erronée";
      case CUNITE_LEX_ERRUNITE:
         return "Erreur Lexical";
      case CUNITE_LEX_INCONNUE:
         return "Inconnu";
      default:
         return "Inconnu";
    }
    return "Inconnu";
}

/***************************************************************************
***
*** Nom de fonction: getLibResultat
***
*** Description:     dictionnaire de traduction des codes d'erreurs en une chaine
***
*** Param sortie:    chaine de caratère
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
char *getLibResultat(TENUM_RESULTAT eRes)
{
    switch(eRes)
    {
      case CERR_NO_ERROR:
         return "Pas d'erreurs";
      case CERR_OUVERTURE_DE_FICHIER:
         return "Prob d'ouverture de fichier source";
      case CERR_TROP_DE_SYMBOLE:
         return "Trop de symboles";
      case CERR_SYMBOLE_TROP_LONG:
         return "Symbole trop long";
      default:
         return "Inconnu";
    }
    return "Inconnu";
}
