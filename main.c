/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:14:31 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/25 14:35:22 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

/*int	main(void)
{
	int		fd;
	char	*ptr;

	ptr = (void *) 1;
	fd = open("test_input_files/read_error.input", O_RDONLY);
	if (fd < 3)
		return (-1);
	while (ptr)
	{
		ptr = get_next_line(fd);
		if (ptr)
		//{
		//	write(1, ptr, strlen(ptr));
			free(ptr);
		//	write(1, "!!!!!!!!!!!!!HA ESCRITO UNA LINEA!!!!!!!!!!!!!!", 47);
		//}
		if (!ptr)
			write(1, "!!!!!!!!!!!!!!!!!HA DEVUELTO NULL!!!!!!!!!!!!!!", 47);
	}
	return (close(fd));
}*/

void	lnprint(char *ptr)
{
	char	*endcur;

	if (ptr)
	{
		endcur = memchr(ptr, '\n', strlen(ptr));
		if (endcur)
			write(1, ptr, (endcur - ptr + 1));
		if (!endcur)
			write(1, ptr, strlen(ptr));
	}
}

int	main(int narg, char **sarg)
{
	int		fd;
	char	*ptr;

	ptr = (void *) 1;
	if (narg == 1)
	{
		while (ptr)
		{
			ptr = get_next_line(0);
			if (ptr)
			{
				lnprint(ptr);
				free(ptr);
			}
//			if (!ptr)
//				write(1, "HA DEVUELTO NULL", 15);
		}
		return (0);
	}
	if (narg == 2)
	{
		fd = open(sarg[1], O_RDONLY);
		if (fd < 3)
			return (-1);
		while (ptr)
		{
			ptr = get_next_line(fd);
			if (ptr)
			{
				lnprint(ptr);
				free(ptr);
			}
//			if (!ptr)
//				write(1, "HA DEVUELTO NULL", 15);
		}
		return (close(fd));
	}
}
