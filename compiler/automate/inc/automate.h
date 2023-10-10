#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED

typedef unsigned char UCHAR;
typedef char CHAR;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned int AUTOWORD;
typedef void AUTOVOID;
typedef void* LPVOID;
typedef long LONG;
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef int BOOL;

/***************************************************************************
*Programmeur	:   Mohamed KHADRAOUI
*Date			:     27 Octobre 2004
*Module		:     automate.h
*Commentaires  :	librairie de fonctions d'export de l'automate
***************************************************************************/



/***************************************************************************
***
*** Projet:   ESTI
***
*** Module:   automate.h
***
*** Description:  constantes, definition de types, variables globales a:
***                     - DLL UTILITAIRE,
***
*** HISTORIQUE:
***
*** Modifications:  <Date>  <Auteur>  <nom fonction>
***
****************************************************************************/

// definition des différentes valeurs résultat
#define CNUTI_RES_OK                      10  // resultat correct de cmd
#define CNUTI_RES_INITAUTO                40  // erreur initialisation automate
#define CNUTI_RES_STOPAUTO                41  // erreur arret automate
#define CNUTI_RES_MOTEURAUTO              42  // erreur moteur automate
#define CNUTI_RES_MOTEURAUTO              42  // erreur moteur automate
#define CNUTI_RES_EXECAUTO                43  // erreur dans l'execution d'une fonction automate

// constantes automate
#define CNUTI_AUTO_ETAT_FINAL      (TNUTI_ETATAUTO) 0x7E
#define CNUTI_AUTO_ETAT_INIT       (TNUTI_ETATAUTO) 0
#define CNUTI_AUTO_NO_CHG_ETAT     (TNUTI_ETATAUTO) 0x7F
#define CNUTI_AUTO_LGNOM_REFAUTO   (UCHAR) 30

// contexte d'un automate
typedef UCHAR    TCUTI_REFAUTO [CNUTI_AUTO_LGNOM_REFAUTO];
typedef UCHAR   TNUTI_ETATAUTO;
typedef UCHAR   TNUTI_EVTAUTO;
typedef struct  TSUTI_CTXT_AUTO
  {
  TNUTI_ETATAUTO   vEtat;                // etat courant de l'automate
  TNUTI_EVTAUTO    vEvt;                 // evenement a traiter
  UCHAR            *pSaut;                        // pointeur sur la table des sauts
  TNUTI_ETATAUTO   (**pAction) (struct TSUTI_CTXT_AUTO *, void *); // pointeur sur la table des actions
  TCUTI_REFAUTO    tRefAuto; // reference (nom) de l'automate
  void            *pCtxtUti;                     // pointeur sur le contexte d'execution utilisateur
  } TSUTI_CTXT_AUTO;


/***************************************************************************
***
***            PROTOTYPES DES FONCTIONS LIBRAIRIE EXPORTEES
***
***************************************************************************/


DWORD UTI_InitAutomate      (TSUTI_CTXT_AUTO *, UCHAR *,
                                           TNUTI_EVTAUTO (**) (TSUTI_CTXT_AUTO * , void *),
                                           UCHAR *, UCHAR *);
LONG UTI_ArretAutomate     (TSUTI_CTXT_AUTO *);
UCHAR UTI_MoteurAutomate    (TSUTI_CTXT_AUTO *, TNUTI_EVTAUTO, void *);
TNUTI_EVTAUTO UTI_EtatAutomate  (TSUTI_CTXT_AUTO *);



#endif // AUTOMATE_H_INCLUDED
