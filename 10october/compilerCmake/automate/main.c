
/***************************************************************************
*Programmeur	:   Mohamed KHADRAOUI
*Date			:     27 Octobre 2004
*Module		:     automate.c
*Commentaires  :	librairie de fonctions de base	de l'automate
***************************************************************************/

#include "stdio.h"
#include "inc/automate.h"

/** Variables **/
#define CNUTI_TAILLEPATH     250
#define CNUTI_LONGUEURLIGNE  250

char      cUTI_CurrentDirectory[CNUTI_TAILLEPATH];
HANDLE    hUTI_SemErr;        // semaphore pour les messages d'erreurs
HANDLE    hUTI_SemTra;        // semaphore pour la gestion des traces


/***************************************************************************
***
*** Nom de fonction: UTI_InitAutomate
***
*** Description:     Initialisation du contexte d'un automate
***
*** Param sortie:    structure contexte de l'automate initialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
DWORD UTI_InitAutomate(
             TSUTI_CTXT_AUTO *ppCtxt, // pointeur sur structure contexte de service de l'automate
             UCHAR           *ppSaut, // pointeur sur table des sauts
             UCHAR           (**ppAction)(TSUTI_CTXT_AUTO *, void *), // pointeur sur table des actions
             UCHAR           *ppRefAuto, // reference de l'automate
             UCHAR           *ppCtxtUti) // pointeur sur le contexte d'execution utilisateur
{
  // test existence contexte automate
  if (ppCtxt == NULL)
    return(CNUTI_RES_INITAUTO);

  // mettre a jour les differents champs du contexte
  ppCtxt->vEtat = 0;
  ppCtxt->pSaut = ppSaut;
  ppCtxt->pAction = ppAction;
  ppCtxt->pCtxtUti= ppCtxtUti;

  return(CNUTI_RES_OK);
  } // fin UTI_InitAutomate


/***************************************************************************
***
*** Nom de fonction: UTI_ArretAutomate
***
*** Description:     Arret d'un automate
***
*** Param sortie:    structure contexte de l'automate reinitialisee
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
LONG UTI_ArretAutomate(TSUTI_CTXT_AUTO *ppCtxt) // pointeur sur contexte automate
{
  // test existence contexte automate
  if(ppCtxt == NULL)
    return(CNUTI_RES_INITAUTO);

  // mettre les pointeurs du contexte a NULL et l'etat a "final"
  ppCtxt->pSaut = NULL;
  ppCtxt->pAction = NULL;
  ppCtxt->vEtat = CNUTI_AUTO_ETAT_FINAL;

  return(CNUTI_RES_OK);
} // fin UTI_ArretAutomate


/***************************************************************************
***
*** Nom de fonction: UTI_MoteurAutomate
***
*** Description:     moteur de l'automate: recherche de l'action associee
***                  a un couple (evt, etat) puis transition à la nouvelle
***                  état
*** Param sortie:    structure automate mise a jour
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
UCHAR UTI_MoteurAutomate(
             TSUTI_CTXT_AUTO *ppCtxt,     // pointeur sur contexte automate
             TNUTI_EVTAUTO   vpEvt,       // evenement a traiter
             void            *ppCtxtExec) // pointeur sur contexte execution
{
  USHORT vli;                        // indice de table
  UCHAR  vlNumEvt;                   // numero d'evenement a traiter
  UCHAR  vlNumEtat;                  // numero d'etat courant
  UCHAR  vlNumTrait;                 // numero du traitement a executer
  UCHAR  vlMaxEvt;                   // nombre max d'evenement de l'automate
  UCHAR  vlMaxEtat;                  // nombre max d'etat de l'automate
  UCHAR  vlNouvelEtat;               // numero du nouvel etat apres le traitement
  UCHAR  (*plTrt)(TSUTI_CTXT_AUTO *, void *);// adresse du traitement a executer


  // test du Ptr Ctxt
  if (ppCtxt == NULL)
    return(CNUTI_RES_INITAUTO);
  // test des pointeurs
  if (ppCtxt->pSaut == NULL || ppCtxt->pAction == NULL)
    return(CNUTI_RES_INITAUTO);

  // initialisation
  vlNumEvt = ppCtxt->vEvt = vpEvt;
  vlNumEtat = ppCtxt->vEtat;
  vlMaxEvt = ppCtxt->pSaut[0];
  vlMaxEtat = ppCtxt->pSaut[1];

  // test validite couple (evt,etat)
  if (vlNumEvt >= vlMaxEvt || vlNumEtat >= vlMaxEtat)
    return(CNUTI_RES_MOTEURAUTO);

  // recherche de l'adresse de traitement a executer
  vli = vlNumEvt * vlMaxEtat;
  vli <<= 1;
  vlNumEtat <<= 1;
  vli += vlNumEtat + 2;
  vlNumTrait = ppCtxt->pSaut[vli];
  plTrt = ppCtxt->pAction[vlNumTrait];

  // execution du traitement et mise a jour de l'etat du contexte de l'automate
  vlNouvelEtat = (*plTrt)(ppCtxt, ppCtxtExec); //IoC
  if (vlNouvelEtat == CNUTI_AUTO_NO_CHG_ETAT) // il n'y a pas de changement d'etat dans le traitement
    ppCtxt->vEtat = ppCtxt->pSaut[vli+1];
  else
    ppCtxt->vEtat = vlNouvelEtat;

  return(CNUTI_RES_OK);
  } // fin UTI_MoteurAutomate



/***************************************************************************
***
*** Nom de fonction: UTI_EtatAutomate
***
*** Description:     rend l'etat de l'automate
***
*** Param entree:    pointeur automate
***
*** Modifications:  <Date>  <Auteur>  <description modif>
***
****************************************************************************/
TNUTI_EVTAUTO UTI_EtatAutomate(TSUTI_CTXT_AUTO *ppCtxt) // pointeur sur l'automate
{
  return ppCtxt->vEvt;
}
