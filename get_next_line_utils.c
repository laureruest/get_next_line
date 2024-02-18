/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:20:39 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/18 19:04:28 by lruiz-es         ###   ########.fr       */
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
		{
			nl_toret[nl_cursor] = buffer[*idx];
			*idx++;
			nl_cursor++;
		}
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

char	*givline(char *buffer, ssize_t *idx, ssize_t *maxlen)
{
	char	*ptr_nl;
	char	*ptr_toret;

	ptr_nl = 0;
	ptr_toret = NULL;
	while (!ptr_nl)
	{
		ptr_nl = srch_nl(buffer, *idx, *maxlen);
		if (!ptrnl)
		{
			if (*maxlen < BUFFER_SIZE)
			{
				prt_toret = build_nl(ptr_toret, buffer, idx, maxlen);
				*idx = 0;
				*maxlen = 0;
				return (ptr_toret);
			}
			ptr_toret = build_nl(ptr_toret, buffer, idx, maxlen);
			//hay que llenar el buffer
			if (!ptr_toret)
				return (NULL);
		}
		// aqui va el caso para ultimo trozo de la linea cuando encuentras NULL
	}
	return (ptr_toret);
}
