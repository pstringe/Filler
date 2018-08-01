/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:32:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/01 15:47:16 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define MAX_RANGE
# include "libft.h"

typedef struct	s_piece
{
	char	*shape;
	int		width;
	int		height;
}				t_piece;			

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
}				t_map;

typedef struct	s_game
{
	struct	s_map;:tb
	struct	s_piece;
}				t_game;

#endif
