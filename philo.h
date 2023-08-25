#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
# include <pthread.h>
#include <unistd.h>

typedef struct s_philo
{
	int				philo_id;
	int				meals;
	unsigned long	last_eat;
	pthread_t		thread;
}					t_philo;


typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				is_philo_dead;
	int				thread_index;
	unsigned long	start_time;
	pthread_t		dead;
	pthread_mutex_t	mutex_util;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;

int				ft_atoi(const char *str);
unsigned long	get_time(void);
int				control(int ac, char **av);
int				get_data(t_data *data, char **av);
void			destroy(t_data *data);
void			mutex_init(t_data *data);
void			philo_init(t_data *data);
unsigned long	get_passed_time(unsigned long begin);
void			join_threads(t_data *data);
void			threads_init(t_data *data);
void* 			only_one_philo(void *void_data);
int				print_action(t_data *data, int index, char *str);
void			smart_sleep(int time);
void			thread_init(t_data *data);
void			*routine(void *void_data);
int				eating(t_data *data, int index);
int				sleeping(t_data *data, int index);
int				thinking(t_data *data, int index);
int				is_death(t_data *data);
void			*death(void *void_data);
int				all_philos_eat(t_data *data);

#endif