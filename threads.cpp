#include "threads.hpp"

// P(...) = sem_wait(...)
// v(...) = sem_post(...)

// Smoker threads

void* smoke_t(void* ptr)
{
	for(int i = 0; i < 3; i++)
	{
		sem_wait(&tobacco_sem);
		mout.write("Smoker T start\n");
		usleep(50000);
		sem_post(&agent);
		mout.write("Smoker T end\n");
	}

   pthread_exit(0);
}

void* smoke_m(void* ptr)
{   
	for(int i = 0; i < 3; i++)
	{
		sem_wait(&matches_sem);
		mout.write("Smoker M start\n");
		usleep(50000);
		sem_post(&agent);
		mout.write("Smoker M end\n");
	}

   pthread_exit(0);
}

void* smoke_p(void* ptr)
{   
	for(int i = 0; i < 3; i++)
	{
		sem_wait(&papers_sem);
		mout.write("Smoker P start\n");
		usleep(50000); 
		sem_post(&agent);
		mout.write("Smoker P end\n");
	}

   pthread_exit(0);
}


// Pusher threads

void* push_t(void* ptr)
{   
	for(int i = 0; i < 12; i++)
	{
		sem_wait(&tobacco);
		sem_wait(&mutex);
		mout.write("Pusha T start\n");

		if(table.papers)
		{
			table.papers = false;
			sem_post(&matches_sem);
		}
		else if(table.matches)
		{
			table.matches = false;
			sem_post(&papers_sem);
		}
		else
		{
			table.tobacco = true;
		}

		sem_post(&mutex);
		mout.write("Pusha T end\n");
	}

   pthread_exit(0);
}

void* push_m(void* ptr)
{   
	for(int i = 0; i < 12; i++)
	{
		sem_wait(&matches);
		sem_wait(&mutex);
		mout.write("Pusher M start\n");

		if(table.papers)
		{
			table.papers = false;
			sem_post(&tobacco_sem);
		}
		else if(table.tobacco)
		{
			table.tobacco = false;
			sem_post(&papers_sem);
		}
		else
		{
			table.matches = true;
		}

		sem_post(&mutex);
		mout.write("Pusher M end\n");
	}

   pthread_exit(0);
}

void* push_p(void* ptr)
{   
	for(int i = 0; i < 12; i++)
	{
		sem_wait(&papers);
		sem_wait(&mutex);
		mout.write("Pusher P start\n");

		if(table.tobacco)
		{
			table.tobacco = false;
			sem_post(&matches_sem);
		}
		else if(table.matches)
		{
			table.matches = false;
			sem_post(&tobacco_sem);
		}
		else
		{
			table.papers = true;
		}

		sem_post(&mutex);
		mout.write("Pusher P end\n");
	}

   pthread_exit(0);
}



// Agent threads

void* age_t(void* ptr)
{   
	for(int i = 0; i < 6; i++)
	{
		usleep(200000);
		sem_wait(&agent);
		mout.write("Agent T start\n");
		sem_post(&matches);
		sem_post(&papers);
		mout.write("Agent T end\n");
	}

   pthread_exit(0);
}

void* age_m(void* ptr)
{
	for(int i = 0; i < 6; i++)
	{
		usleep(200000);
		sem_wait(&agent);
		mout.write("Agent M start\n");
		sem_post(&tobacco);
		sem_post(&papers);
		mout.write("Agent M end\n");
	}

   pthread_exit(0);
}

void* age_p(void* ptr)
{
	for(int i = 0; i < 6; i++)
	{
		usleep(200000);
		sem_wait(&agent);
		mout.write("Agent P start\n");
		sem_post(&tobacco);
		sem_post(&matches);
		mout.write("Agent P end\n");
	}

   pthread_exit(0);
}