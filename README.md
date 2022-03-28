<h1 align="center">
    <img alt="42Lausanne" title="42Lausanne" src="https://github.com/MarJC5/42/blob/main/42_logo.svg" width="140"> </br>
    Project n°9 - Philosophers
    <h4 align="center" style="width: 50%; margin: 2rem auto; font-weight: normal;">
     basics of threading a process, see how to create threads and discover mutexes.
    </h4>
</h1>

## Goals

Here are the things you need to know if you want to succeed this assignment:

- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
    1. While they are eating, they are not thinking nor sleeping;
    2. while thinking, they are not eating nor sleeping;
    3. and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!

## Rules

Program(s) should take the following arguments: **number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]**

- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

## Test

Here is the test values:

```shell
1 800 200 200 (die)
5 800 200 200 (no die)
5 800 200 200 10 (stop after each philo eat 10 times)
4 410 200 200 (no die)
4 310 200 200 (die)
```

## External functs

memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
