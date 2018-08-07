/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstringe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:30:11 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/07 12:33:08 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	these functions stdin for map dimensions and grid
*/

int	get_dimensions(t_board *board)
{
	char	*idx;
	char	*line;

	while (get_next_line(0, &line) == 1 && *line != 'P')
		free(line);
	if (*line != 'P')
	{
		free(line);
		return (die(-1001));
	}
	idx = line;
	while (*idx && !ft_isdigit(*idx))
		idx++;
	board->height = ft_atoi(idx);
	idx = ft_strchr(idx, ' ') + 1;
	board->width = ft_atoi(idx);
	ft_memdel((void**)&line);
	return (1);
}

int	get_map(t_board *board)
{
	int		i;
	char 	*line;

	board->map = ft_memalloc(sizeof(char*) * board->height + 1);
	board->map[board->height] = NULL;
	get_next_line(0, &line);
	i = -1;
	while (get_next_line(0, &line) == 1 && ft_isdigit(*line))
	{
		board->map[++i] = ft_strdup(ft_strchr(line, ' ') + 1);
		free(line);
	}

	/* test */
	i = -1;
	while (board->map[++i])
		ft_printf("%s\n", board->map[i]);
	/* end test */
	return (1);
}	


int	get_board(t_board *board)
{
	char *line;

	line = NULL;
	if (!get_dimensions(board))
		return (die(-100));
	if (!get_map(board))
		return (die(-102));
	return (1);
}

int valid(t_board *board)
{
	if (board)
		return (0);
	return (0);
}

/*
**	parse piece dimensions and shap from stdin
*/

int get_piece(t_piece *piece)
{
	if (piece)
		return (0);
	return (0);
}

/*
**	here the bot takes in the neccessary information from stdin required to
**	compute a move
*/

int	sense(t_game *game)
{
	if (!get_board(game->board))
		return (die(-10));
	if (!valid(game->board))
		return (die(-12));
	if (!get_piece(game->piece))
		return (die(-11));
	return (1);
}

/*
**	computes an optimal range of moves
*/

int	get_range(t_game *game)
{
	if (game)
		return (0);
	return (0);
}

/*
**	itterates over positions within the optimal range
*/

int	itterate_range(t_game *game)
{
	if (game)
		return (0);
	return (0);
}

/*
**	the bot first attempts to find a range of agressive moves, if the range
**	is too small, it will instead try to find a range of encapsulating moves,
**	if this proves infeasable it will return a range of fortifying moves. Once
** 	a range has been selected, the bot will itterate over that range attempting
**	to place the piece.
*/

int move(t_game *game)
{
	if (!get_range(game))
		return (die(-20));
	if (!itterate_range(game))
		return (die(-21));	
	return (1);
}

/*
**	right now this function is only responsible for returning the move to
**	stdout.
*/

int	output(t_piece *piece)
{
	ft_printf("%d %d\n", piece->x, piece->y);
	return (1);
}

/*
**	each move, the bot collects information about its environment,
**	uses that information to compute a move, and returns that move to
**	standard output
*/

int	filler(t_game *game)
{
	if (!sense(game))
		return (die(-1));
	if (!move(game))
		return (die(-2));
	if (!output(game->piece))
		return (die(-3));
	return (1);
}

t_game	*init_game(void)
{
	t_game *game;

	game = ft_memalloc(sizeof(t_game));
	game->board = ft_memalloc(sizeof(t_board));
	game->piece = ft_memalloc(sizeof(t_piece));
	return (game);
}

int main(void)
{
	t_game *game;

	game = init_game();
	while (filler(game) > 0);
	return (die(filler(game)));
}
