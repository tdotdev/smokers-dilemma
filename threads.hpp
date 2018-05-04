#ifndef THREADS_HPP
#define THREADS_HPP

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

struct Table
{
   Table() 
      : tobacco(false)
      , matches(false)
      , papers(false) 
   {}

   bool tobacco;
   bool matches;
   bool papers;
};

extern Table table;  
extern sem_t agent, mutex;
extern sem_t tobacco, matches, papers;

void* smoke_t(void*);
void* smoke_m(void*);
void* smoke_p(void*);
void* push_t(void*);
void* push_m(void*);
void* push_p(void*);
void* age_t(void*);
void* age_m(void*);
void* age_p(void*);

#endif