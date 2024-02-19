/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:50:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/19 19:36:09 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*givline(char *buffer, size_t *idx, size_t *maxlen, int fd);

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*nwline;
	static size_t	*mxbuflen;
	static size_t	*idx;

	mxbuflen = malloc(1);
	idx = malloc(1);
	*mxbuflen = BUFFER_SIZE;
	*idx = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE);
	if (buffer)
	{
		if (*idx > (*mxbuflen - 1))
		{
			*idx = 0;
			*mxbuflen = read(fd, buffer, BUFFER_SIZE);
			if (*mxbuflen <= 0)
				return (NULL);
		}
		nwline = givline(buffer, idx, mxbuflen, fd);
		return (nwline);
	}
	return (NULL);
}
