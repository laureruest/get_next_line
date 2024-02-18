/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:50:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/18 13:26:42 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer = malloc(BUFFER_SIZE);
	static ssize_t	mxbuflen = BUFFER_SIZE
	static ssize_t	idx = BUFFER_SIZE;

	if (buffer)
	{
		if (idx > (mxbuflen - 1))
		{
			idx = 0;
			mxbuflen = read(fd, buffer, BUFFER_SIZE);
			if (mxbuflen <= 0)
				buffer = release(buffer);
		}
		if (!buffer)
			return (buffer);
		//CODE
		}
	return (NULL);
}
