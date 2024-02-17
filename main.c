/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:14:31 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/17 16:06:39 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int narg, **sarg)
{
	int		fd;
	int		wtn;
	char	*ptr;
	
	ptr = 1;
	if (narg != 2)
		return (-1);
	fd = open(sarg[1]);
	if (fd < 0)
		return (-1);
	while (ptr)
	{
		ptr = get_next_line(fd);
		if (ptr)
			wtn = write(0, ptr, BUFFER_SIZE);
	}
}
