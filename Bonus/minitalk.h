/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:47:48 by mabdali           #+#    #+#             */
/*   Updated: 2023/03/13 14:32:59 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "get_next_line.h"

# define RESET "\033[m"
# define WHITE "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"

int		ft_getnbr(char *str);
int		ft_str_isnum(char *str);
char	*get_next_line(int fd);

#endif
