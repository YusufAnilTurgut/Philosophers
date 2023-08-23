#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				philo_id;
	int				meals;
	int				num_must_meals;
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
	int				philo_dead;
	int				thread_index;
	unsigned long	start_time;
	pthread_t		dead;
	pthread_mutex_t	mutex_util;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;

int					ft_atoi(const char *str);
unsigned long		get_time(void);
int					control(int ac, char **av);
int					get_data(t_data *data, char **av);
void				destroy(t_data *data);
void	mutex_init(t_data *data)


#endif