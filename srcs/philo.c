/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:27:28 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/18 18:13:32 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*make_thread(void *param)
{
	printf("Holis");
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_t hilo;
	
/* 	if (argc < 5 || argc > 6)
	{
		printf("Error");
		return (1);
	} */
	pthread_create(&hilo, NULL, make_thread, NULL);
	pthread_join(hilo, NULL);
}