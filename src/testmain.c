/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:27:32 by kweihman          #+#    #+#             */
/*   Updated: 2024/07/29 12:22:37 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	write_string(int fd, char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	write(fd, str, i);
}

int	ft_error_codes(int error_code)
{
	if (error_code == 1)
		printf("No or too many file names.\n");
	if (error_code == 2)
		printf("Cannot open file.\n");
	if (error_code == 3)
		printf("\nFunction returned NULL.\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		line_number;
	char	*next_line;

	if (argc != 2)
		return (ft_error_codes(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error_codes(2));
	line_number = 0;
	while (0 == 0)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
		{
			close(fd);
			return (ft_error_codes(3));
		}
		line_number++;
		printf("Line %d: %s", line_number, next_line);
		fflush(stdout);
		free(next_line);
	}
	close(fd);
}
