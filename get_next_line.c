/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:50:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/21 20:16:35 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct	s_buffer
{
	long long int	idx, mxlen;
	char			buf[BUFFER_SIZE];
};

char	*givline(struct s_buffer *bf, int fd);

char	*get_next_line(int fd)
{
	static struct s_buffer	bf = {BUFFER_SIZE, BUFFER_SIZE, ""};
	char			*nwline;

	if (bf.idx == bf.mxlen)
		{
			bf.idx = 0;
			bf.mxlen = read(fd, &bf.buf[0], BUFFER_SIZE);
			if (bf.mxlen <= 0)
				return (NULL);
		}
	nwline = givline(&bf, fd);
	return (nwline);
}
