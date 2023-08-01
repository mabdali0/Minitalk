/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:30:20 by mabdali           #+#    #+#             */
/*   Updated: 2023/03/13 10:32:59 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getnbr(char *str)
{
	int	res;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	res = 0;
	while (*str)
	{
		res *= 10;
		res += *str - '0';
		str += 1;
	}
	return (res);
}

int	ft_str_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}
