#ifndef THREADS_HPP
#define THREADS_HPP

#include <iostream>
#include <cstring>
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

struct M_out
{
	M_out()
	: enabled(true)
	{}

	bool enabled;
	
	void write(std::string out)
	{
		if(enabled)
			std::cout << out;
	}
};

extern Table table;  
extern M_out mout;
extern sem_t agent, mutex;
extern sem_t tobacco, matches, papers;
extern sem_t tobacco_sem, matches_sem, papers_sem;

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