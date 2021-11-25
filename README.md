# Philosophers

This project focuses on the basics of threading a process and mutexes. Philo_two focuses on forking and semaphores.

## Learning goals

- Multithreading
- Mutexes
- Forking
- Semaphores

## Project description

This is the Codam approach to the classic philosophers multithreading problem. The problem is about philosophers who are sitting at a round table with a fork to the left and right. They are either eating, sleeping or thinking. However, they can only eat whilst holding two forks. After a certain amount of time has passed, philosophers die from starvation. All philosophers represent a thread in the philo_one or a fork in philo_two, and forks a mutex or semaphore, respectively.

## Usage

1. Clone this repository
   ```console
   git clone https://github.com/rutgercap/philo.git
   ```
2. Run with 

   ```console
   make run
   ```
