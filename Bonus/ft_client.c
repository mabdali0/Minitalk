/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:12:08 by mabdali           #+#    #+#             */
/*   Updated: 2023/03/14 13:13:34 by mabdali          ###   ########.fr       */
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
		usleep(1000);
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

void	client_init(int pid_serv)
{
	ft_printf(BLUE BOLD"Connection with the server at the PID "RESET);
	ft_printf(WHITE BOLD"%d"RESET, pid_serv);
	ft_printf(" ...\n");
	sleep(1);
	ft_printf(GREEN BOLD"Done.\n"RESET);
	ft_printf(WHITE BOLD"\nWelcome,press CTRL + C to quit client"RESET);
	ft_printf(BOLD WHITE"\nEnter message here :\n"RESET);
}

int	main(int ac, char **av)
{
	pid_t	pid_serv;
	char	*mess;

	if (ac != 2)
	{
		ft_printf(BOLD RED"Error ,please try ./client <PID>\n"RESET);
		return (0);
	}
	if (ft_str_isnum(av[1]) == 0)
		pid_serv = ft_getnbr(av[1]);
	if (pid_serv <= 1)
		ft_printf(RED BOLD"Bad PID\n"RESET);
	client_init(pid_serv);
	mess = get_next_line(0);
	while (mess != NULL)
	{
		ft_printf(GREEN"Your message has been sent and received !\n"RESET);
		ft_printf(BOLD WHITE"\nEnter message here :\n"RESET);
		send_str(pid_serv, mess);
		free(mess);
		mess = get_next_line(0);
	}
	return (0);
}
