/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:18:32 by mabdali           #+#    #+#             */
/*   Updated: 2023/03/13 14:53:37 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	serv_init(void)
{
	ft_printf(BOLD BLUE"\nThe PID is "RESET);
	ft_printf("%d\n", getpid());
	ft_printf("Waiting for a message ...\n\n");
}

void	ft_write(int to_put)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (to_put << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	sig(int sign)
{
	if (sign == SIGUSR1)
		ft_write(0);
	else if (sign == SIGUSR2)
		ft_write(1);
	else if (sign == SIGFPE)
		ft_printf("recu");
}

void	get_sig(void)
{
	if (signal(SIGUSR1, sig) == SIG_ERR)
		ft_printf("SIGUSR1 ERROR\n");
	if (signal(SIGUSR2, sig) == SIG_ERR)
		ft_printf("SIGUSR2 ERROR\n");
	if (signal(SIGFPE, sig) == SIG_ERR)
		ft_printf("SIGFPE ERROR\n");
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{		
		ft_printf(BOLD RED"\nNo parameters needed\n"RESET);
		ft_printf(RED"  Please try ./server\n"RESET);
	}
	else
	{
		serv_init();
		get_sig();
		while (1)
			pause();
		(void)av;
		return (0);
	}
}
