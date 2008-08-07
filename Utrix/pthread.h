/*
 *  pthread.h
 *  Utrix
 *
 *  Created by Matteo Casenove on 10/07/08.
 *  Copyright 2008 Utrix. All rights reserved.
 *
 */

/*Librerie necessarie*/
#include<stddef.h>
#include<stdlib.h>
#include<time.h>


typedef unsigned int pthread_t;

extern int       pthread_create(pthread_t *,/* const pthread_attr_t*,*/ void* (*)(void *), void *);
extern int       pthread_detach(pthread_t);
extern int       pthread_yield(void);

extern void      pthread_exit(void *);
extern int       pthread_join(pthread_t, void **);
extern int       pthread_kill(pthread_t, int);
extern pthread_t pthread_self(void);/*Ritorna il tid del thread che la chiama ho pensato di aggiungerla perchè utile che ne dite?*/






