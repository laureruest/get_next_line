/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:50:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/24 15:03:50 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*givline(struct s_buffer *bf, int fd);

char	*get_next_line(int fd)
{
	static struct s_buffer	bf = {BUFFER_SIZE, BUFFER_SIZE, ""};
	char					*nwline;

	if ((fd < 0) || (fd == 1) || (fd == 2))
		return (NULL);
	if (bf.idx == bf.mxlen)
	{
		bf.mxlen = read(fd, &bf.buf[0], BUFFER_SIZE);
		if (bf.mxlen <= 0)
		{
			bf.idx = bf.mxlen;
			return (NULL);
		}
		bf.idx = 0;
	}
	nwline = givline(&bf, fd);
	return (nwline);
}
