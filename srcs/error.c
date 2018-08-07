/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:33:02 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/02 18:13:44 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int 	e_move(int c)
{
	if (c)
		return (0);
	return (0);
}

static int	e_sense(int c)
{
	if (c == 10)	
		ft_printf("error: %d: failed to get board\n", c);
	else if (c == 11)
		ft_printf("error: %d: failed to get piece\n", c);
	else if (c == 12)
		ft_printf("error: %d: failed to validate\n", c);
	else if (c == 100)
		ft_printf("error: %d: failed to retrieve map dimensions\n", c);
	else if (c == 101)
		ft_printf("error: %d: failed to parse map\n", c);
	else if (c == 1000)
		ft_printf("error: %d: failed to locate 'Platue' token\n", c);
	return (0);
}

int			die(int c)
{
	int d;
	int val;

	c *= -1;
	if (c >= 1000)
		d = 4;
	else if (c >= 100)
		d = 3;
	else if (c >= 10)
		d = 2;
	else
		d = 1;
	val = ft_digslct(c, d);
	if (val == 1)
		e_sense(c);
	if (val == 2)
		e_move(c);
	return (0);
}
