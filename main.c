/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:14:31 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/18 09:59:55 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

void	display(ptr)
{
}

int	main(int narg,char **sarg)
{
	int		fd;
	int		wtn;
	size_t	len;
	char	*ptr;
	char	*end;
	
	ptr = 1;
	if (narg == 1)
	{
		while (ptr)
		{
			ptr = get_next_line(0);
			if (ptr)
				display(ptr);
		}
	return (0);
	}
	if (narg == 2)
	{
		fd = open(sarg[1]);
		if (fd < 0)
			return (-1);
		while (ptr)
		{
			ptr = get_next_line(fd);
			if (ptr)
				display(ptr);
		}
		return (0);
	}
}
