# Philosophers

This is the Codam approach to the classic philosophers multithreading problem. This project focuses on the basics of threading a process and mutexes. Philo_bonus solves the same problem, except with forking and semaphores. 

## Learning goals

- Multithreading
- Mutexes
- Forking
- Semaphores

## Project description

The problem is about philosophers who are sitting at a round table with a fork to their left and right. They are either eating, sleeping or thinking. However, they can only eat whilst holding two forks and no two philosophers can hold the same fork. After a certain amount of time has passed without eating, philosophers die from starvation. All philosophers represent a thread in philo_one or a fork in philo_two, and forks represent a mutex or semaphore.

## Usage

1. Clone this repository
   ```console
   git clone https://github.com/rutgercap/philo.git
   ```
2a. Run with 

   ```console
   make run
   ```
2b. Or run it as ./philo time_to_die_in_ms time_to_eat_in_ms time_to_sleep_in_ms [philosophers_n]

   ```console
   ./philo 10 400 200 200
   ```
   
### Special rules

The program doesn't work with too many philosophers.
