# Philosophers
The classic dining philosopher problem.

This problem states that N philosophers seated around a circular table with one fork between each pair of philosophers. A philosopher may eat if he can pick up the two forks adjacent to him. One fork may be picked up by any one of its adjacent followers but not both.

![68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f372f37622f416e5f696c6c757374726174696f6e5f6f665f7468655f64696e696e675f7068696c6f736f70686572735f70726f626c656d2e706e67](https://github.com/badi361/Philosophers/assets/115088616/c033530a-3092-45ae-8431-ccb8b52df74d)

Each time a philosopher finish eating, they will drop drop their forks and start sleeping. Once they have finished sleeping, the will start thinking and waiting to eat.

Simulation stops when a philosopher dies.

Every philosopher needs to eat and they should never starve.

Philosophers do not speak with each other.

Philosophers do not know when another philospher is about to die.

And of course, philosophers should avoid dying.

HOW TO USE

- Open the Terminal

- Clone the repo

> git clone https://github.com/YusufAnilTurgut/Philosophers.git
Go to philo folder and run make

> cd ./philo && make
Makefile rules: all, clean, fclean, re).

Usage

> ./philo [N PHILOS] [DIE TIME] [EAT TIME] [SLEEP TIME] (OPT)[PHILO EAT N TIMES]
last argument is optional.


Example

>> ./philo 4 800 200 200

<img width="1005" alt="image" src="https://github.com/badi361/Philosophers/assets/115088616/674d5e00-d78b-4be2-a43b-a1c6c3ec730d">

