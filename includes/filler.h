/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:32:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/07 11:50:53 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define MAX_RANGE
# include <assert.h>
# include "../libft/libft.h"

typedef struct	s_piece
{
	char	*shape;
	int		width;
	int		height;
	int		x;
	int		y;
}				t_piece;			

typedef struct	s_board
{
	char	**map;
	int		width;
	int		height;
}				t_board;

typedef struct	s_game
{
	struct	s_board *board;
	struct	s_piece *piece;
}				t_game;

int			die(int c);
#endif
