// analex.cpp : Defines the entry point for the application.
//
#include <automate.h>


typedef enum TENUM_RESULTAT
{
  CERR_NO_ERROR,
  CERR_OUVERTURE_DE_FICHIER,
  CERR_TROP_DE_SYMBOLE,
  CERR_SYMBOLE_TROP_LONG
}TENUM_RESULTAT;

typedef enum TENUM_UNITE_LEX
{
  CUNITE_LEX_INCONNUE,
  CUNITE_LEX_ERRUNITE,
  CUNITE_LEX_ENTIER,
  CUNITE_LEX_DECIMALERR,
  CUNITE_LEX_DECIMAL,
  CUNITE_LEX_CHAINEERR,
  CUNITE_LEX_CHAINE,
  CUNITE_LEX_IDENTERR,
  CUNITE_LEX_IDENT
} TENUM_UNITE_LEX;

typedef struct stSYMBOLE
{
  char            sLibSymbole[96];
  TENUM_UNITE_LEX tTypeSymbole;
  UINT            ligne;
  UINT            colonne;
}stSYMBOLE;

#define MAX_NB_SYMBOLE   1024
#define MAX_LONG_SYMBOLE 96

//-------------------------------------------------------------------------------------
//contexte global de l'analyseur lexicale
typedef struct TSLEX_CONTEXT
{
  //contexte métier
  char             sNomS/***************************************************************************
*Programmeur	:   Mohamed KHADRAOUI
*Date			:     27 Octobre 2004
*Module		:     automate.cpp
*Commentaires  :	librairie de fonctions de base	de l'automate
***************************************************************************/
ourceFich[64];
  FILE*            pSourceFile;
  UINT             numLigne;
  UINT             numColonne;
  WORD   	       longSymboleCourant;       // Longuer courant du symbole en cours d'accumulation
  char             sLibSymboleCourant[MAX_LONG_SYMBOLE];       // buffeur d'accumulation du symb
  WORD   	       vNbSymbole;						 //	Nombre de symboles courant
  stSYMBOLE        tTabSymbole[MAX_NB_SYMBOLE];       // Table des symboles
  TENUM_RESULTAT    ResRetour;

  //contexte générique de l'automate
  HANDLE                   hCtxtMutexCL;      // Mutex de controle de coh d'accès sur l'automate
  TSUTI_CTXT_AUTO          *pCtxtAuto;        // contexte de l'automate attaché
  UINT			           vIdTimer;          // Timer de declenchement

} TSLEX_CONTEXT;
//-------------------------------------------------------------------------------------

void initContext(char *sNomFich);
void freeContext();
UCHAR getEvent(char cLu);
DWORD initAutomate (TSLEX_CONTEXT  *plCtxtModemCL);
UCHAR moteurAutomate (TSLEX_CONTEXT  *ppCtxtModemCL, TNUTI_EVTAUTO vp_EvtAuto, LPVOID ppParam);
void mettreAjourPosition(CHAR cLu);
TNUTI_ETATAUTO insererUniteLex(TENUM_UNITE_LEX uniteEnum, CHAR cLu);
char *getLibUniteLex(TENUM_UNITE_LEX eUniteLex);
char *getLibResultat(TENUM_RESULTAT eRes);

//fonctions exportées
extern void initLexParser(char *sNomFich);
extern void startLexParser();
extern void dumpLexParser(char *sNomFich);
extern void libererLexParser();
