#include "threads.hpp"

Table table;
M_out mout;
sem_t agent, mutex;
sem_t tobacco, matches, papers;
sem_t tobacco_sem, matches_sem, papers_sem;

int main(int argc, const char * argv[])
{

   for(int i = 0; i < argc; i++)
   {
      if(!strcmp(argv[i], "--quiet"))
         mout.enabled = false;
   }

   sem_init(&agent, 0, 1);
   sem_init(&mutex, 0, 1);
   sem_init(&tobacco, 0, 0);
   sem_init(&matches, 0, 0);
   sem_init(&papers, 0, 0);
   sem_init(&tobacco_sem, 0, 0);
   sem_init(&matches_sem, 0, 0);
   sem_init(&papers_sem, 0, 0);

   pthread_t smoker_t1, smoker_t2, agent_t, pusha_t;
   pthread_t smoker_m1, smoker_m2, agent_m, pusher_m;
   pthread_t smoker_p1, smoker_p2, agent_p, pusher_p;

   pthread_create(&agent_t, 0, age_t, 0);
   pthread_create(&agent_m, 0, age_m, 0);
   pthread_create(&agent_p, 0, age_p, 0);

   pthread_create(&pusha_t, 0, push_t, 0);
   pthread_create(&pusher_m, 0, push_m, 0);
   pthread_create(&pusher_p, 0, push_p, 0);

   pthread_create(&smoker_t1, 0, smoke_t, 0);
   pthread_create(&smoker_t2, 0, smoke_t, 0);
   pthread_create(&smoker_m1, 0, smoke_m, 0);
   pthread_create(&smoker_m2, 0, smoke_m, 0);
   pthread_create(&smoker_p1, 0, smoke_p, 0);
   pthread_create(&smoker_p2, 0, smoke_p, 0);

   pthread_join(smoker_t1, 0);
   pthread_join(smoker_t2, 0);
   pthread_join(smoker_m1, 0);
   pthread_join(smoker_m2, 0);
   pthread_join(smoker_p1, 0);
   pthread_join(smoker_p2, 0);

   pthread_join(agent_t, 0);
   pthread_join(agent_m, 0);
   pthread_join(agent_p, 0);

   pthread_join(pusha_t, 0);
   pthread_join(pusher_m, 0);
   pthread_join(pusher_p, 0);

   mout.write("\n>>> What time did you say Taco Bell was open 'till?\n\n");

   return 0;
}