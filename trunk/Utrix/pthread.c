/*
 *  pthread.c
 *  Utrix
 *
 *  Created by Matteo Casenove on 10/07/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "pthread.h"
#include "pth_struct.h"
#include  "pth_stack.s"

/* Modificare con il tid del processo? in esecuzione */

/**********************************************/
//ATTENZIONE AL CONTROLLO DEGLI ERRORI MALLOC
//GUARDA MATTI CHE HO CAMBIATO IL TCB IL TEXT STAVA GIA DENTRO CONTEXT_T SAREBBE RIDONDANTRE//
/*******************************************/
#define CREATE_TID(tcb_n,pfun) tcb_t tcb=(tcb_t)malloc(sizeof(tcb_s)); \
								tcb.tid_f=ESECUTION_TID; \ 
								tcb.tid=tcb_n; \
								tcb.text=pfun; \
								tcb.prior=DEFAULT_PRIOR; \
								tbl_field_t tblx=(tbl_filed_t)malloc(sizeof(tbl_field_s)); \
								tblx.tcb=tcb; \
								tblx.next=pth_prior_table[PRIOR(DEFAULT_PRIOR)]; \
								pth_prior_table[PRIOR(DEFAULT_PRIOR)]=tblx;
								
/*funzione assembler che permette di individuare lo sp della funzione precedente*/
void getPrisp(char** sp);

//int main(void); /* Dichiaration of main */


//context_t* thread_init ( void (*f) (void*), void*  arg);

//thread_start(context_t*old , context_t* new);



int init(){
	pthread_t tid = tcb_n;
	tcb_t tcb=(tcb_t)malloc(sizeof(tcb_s));
	tcb.tid_f=NULL;
	tcb.tid=tcb_n;
	tcb.text=main;
	tcb.prior=DEFAULT_PRIOR;
	tbl_field_t tblx=(tbl_filed_t)malloc(sizeof(tbl_field_s));
	tblx.tcb=tcb;
	tblx.next=pth_prior_table[PRIOR(DEFAULT_PRIOR)]=NULL;
	pth_prior_table[PRIOR(DEFAULT_PRIOR)]=tblx;
}


int pthread_create(pthread_t *pth, const pthread_attr_t * att, void *(*fun)(void *) , void * param){
    
	/*MATTEO QUESTE DUE LE DEVI FAR ESEGUIRE SOLO SE VIENE ESEGUITA INIT()*/
	//prendo lo sp del main
	getPrisp(&globalSp);
	
	
	if( pth == NULL || att != NULL || fun == NULL || param == NULL )
		return FALSE;
	pth=++tcb_n;
	CREATE_TID(pth,fun)
	
	
	
	
}






