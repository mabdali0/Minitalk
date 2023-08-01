/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:34:15 by mabdali           #+#    #+#             */
/*   Updated: 2023/02/20 10:00:37 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_sc
{
	int	len;
	int	width;
}				t_sc;

size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_hex_len(unsigned long nbr);
void		ft_print_hexa(unsigned long nbr, char format);
void		ft_put_x(unsigned int nbr, char format, t_sc *sc);
void		ft_put_p(unsigned long nbr, t_sc *sc);
void		ft_put_c(char c, int fd, t_sc *sc);
void		ft_put_s(char *s, int fd, t_sc *sc);
void		ft_put_percent(int fd, t_sc *sc);
int			ft_int_len(int nbr);
int			ft_uint_len(unsigned int nbr);
void		ft_putunsigned_fd(unsigned int nbr, int fd);
void		ft_put_di(int nbr, int fd, t_sc *sc);
void		ft_put_u(unsigned int nbr, int fd, t_sc *sc);
const char	*ft_search_arg(va_list arg, const char *format, t_sc *sc);
int			ft_printf(const char *format, ...);

#endif
