/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:20:39 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/19 17:05:32 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*srch_nl(char *buffer, ssize_t idx, ssize_t mxbuflen)
{
	char	*ptrtoret;

	while (idx < mxbuflen)
	{
		if (buffer[idx] = '\n')
			return (&buffer[idx]);
		idx++;
	}
	return (NULL);
}

char	*build_nl(char *oldline, char *buffer, ssize_t *idx, ssize_t *mxbuflen)
{
	char	*nl_toret;
	ssize_t nl_cursor;
	ssize_t nl_size;

	nl_size = 0;
	nl_cursor = 0;
	if (oldline)
	{
		while (oldline[nl_cursor] != '\n')
			nl_cursor++;
		nl_size = nl_cursor;
	}
	nl_size += (*mxbuflen - *idx + 1);
	nl_toret = malloc(nl_size);
	if (nl_toret)
	{
		nl_cursor = transfer(nl_toret, oldline);
		while (*idx < *mxbuflen)
			nl_toret[nl_cursor++] = buffer[*idx++];
		nl_toret[nl_cursor] = '\0';
	}
	return (nl_toret);
}

ssize_t	transfer(char *nwptr, char *oldptr)
{
	ssize_t	cursor;

	cursor = 0;
	if (oldptr)
	{
		while (oldptr[cursor] != '\0')
		{
			nwptr[cursor] = oldlptr[cursor];
			cursor++;
		}
		free(oldptr);
	}
	return (cursor);
}

char	*reseting(char *siso, int *a, int *b)
{
	*a = 0;
	*b = 0;
	return (siso);
}

char	*givline(char *buffer, ssize_t *idx, ssize_t *maxlen, int fd)
{
	char	*p_nl;
	char	*p_ret;

	p_nl = 0;
	p_ret = NULL;
	while (!p_nl)
	{
		p_nl = srch_nl(buffer, *idx, *maxlen);
		if (!p_nl)
		{
			if (*maxlen < BUFFER_SIZE)
			{
				p_ret = build_nl(p_ret, buffer, idx, maxlen);
				return(reseting (p_ret, *idx, *maxlen));
			}
			p_ret = build_nl(p_ret, buffer, idx, maxlen);
			if (*idx == BUFFER_SIZE)
				*mxbuflen = read(fd, buffer, BUFFER_SIZE);
			if (!p_ret)
				return (NULL);
		}
		if (p_nl)
			p_ret = build_nl(p_ret, buffer, idx, (ssize_t)(p_nl - p_ret + 1));
	}
	return (ptr_toret);
}
