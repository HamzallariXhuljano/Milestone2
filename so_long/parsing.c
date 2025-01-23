/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:50:04 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/23 15:59:34 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(void)
{
	t_check	check;
	int	fd;
	size_t	j;
	char *line;

	(check.count)= 0;
	fd = open("txt.txt", O_RDONLY);
	if((line = get_next_line(fd)) != NULL)
	{
		j = ft_strlen(line);
		check.count++;
		free(line);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		if (ft_strlen(line) != j)
		{
			ft_printf("INVALID_MAP\nNot RECTANGULAR\n");
			return(free(line), -1);
		}
			check.count++;
			free(line);
	}
	close(fd);
	return(check.count);
}
void	free_mat(char **matrix, int j)
{
	while(j >= 0)
	{
		free(matrix[j]);
		j--;
	}
	return;
}
char	**store(t_check *check)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("txt.txt", O_RDONLY);
	check->matrix = malloc((check->count + 1) * sizeof(char *));
	if(!check->matrix)
		return(close(fd), NULL);
	while(i < check->count)
	{
		check->matrix[i] = get_next_line(fd);
		if (!check->matrix[i])
		{
			free_mat(check->matrix, i);
			close(fd);
			return(NULL);
		}
		i++;
	}
	check->matrix[check->count] = NULL;
	close(fd);
	return(check->matrix);
}



