/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:12:08 by mabdali           #+#    #+#             */
/*   Updated: 2023/03/13 15:55:13 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_sign(int pid, int nb)
{
	if (nb == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf(RED BOLD"ERROR : cannot send SIGUSR1\n"RESET);
			exit(1);
		}
	}
	if (nb == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf(BOLD RED"ERROR : cannot send SIGUSR2\n"RESET);
			exit(1);
		}
	}
}

void	sign(int pid, char to_send)
{
	char	c;
	int		nb;

	c = 0;
	while (c < 8)
	{
		nb = (to_send >> c++) & 1;
		usleep(800);
		s_sign(pid, nb);
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		sign(pid, str[i]);
	sign(pid, 0);
}

int	main(int ac, char **av)
{
	pid_t	pid_serv;

	if (ac != 3)
	{
		ft_printf(BOLD RED"Wrong parameters\n"RESET);
		ft_printf(RED"Please try ./client <PID> <message>\n"RESET);
		return (0);
	}
	if (ft_str_isnum(av[1]) == 0)
		pid_serv = ft_getnbr(av[1]);
	else
		ft_printf(RED BOLD"ERROR : First arguments must be a number\n"RESET);
	if (pid_serv <= 1)
		ft_printf(RED BOLD"Bad PID\n"RESET);
	send_str(pid_serv, av[2]);
	return (0);
}
