/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:20:39 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/21 20:16:29 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*srch_nl(char *buffer, size_t idx, size_t mxbuflen)
{
	while (idx < mxbuflen)
	{
		if (buffer[idx] == '\n')
			return (&buffer[idx]);
		idx++;
	}
	return (NULL);
}

size_t	transfer(char *nwptr, char *oldptr)
{
	size_t	cursor;

	cursor = 0;
	if (oldptr)
	{
		while (oldptr[cursor] != '\0')
		{
			nwptr[cursor] = oldptr[cursor];
			cursor++;
		}
		free(oldptr);
	}
	return (cursor);
}

char	*build_nl(char *oldline, char *buffer, size_t *idx, size_t mxbuflen)
{
	char	*nl_toret;
	size_t	nl_cursor;
	size_t	nl_size;

	nl_size = 0;
	nl_cursor = 0;
	if (oldline)
	{
		while (oldline[nl_cursor] != '\n')
			nl_cursor++;
		nl_size = nl_cursor;
	}
	nl_size += (mxbuflen - *idx + 1);
	nl_toret = malloc(nl_size);
	if (nl_toret)
	{
		nl_cursor = transfer(nl_toret, oldline);
		while (*(idx) < mxbuflen)
			nl_toret[nl_cursor++] = buffer[*idx++];
		nl_toret[nl_cursor] = '\0';
	}
	return (nl_toret);
}

char	*reseting(char *siso, size_t *a, size_t *b)
{
	*a = 0;
	*b = 0;
	return (siso);
}

struct	s_nl
{
	long long int	o_size, nw_size;
	char			*o_ln, *nw_ln;
};
struct	s_buffer
{
	long long int	idx, mxlen;
	char			buf[BUFFER_SIZE];
};

char	*e_ln_n_null(struct s_nl *ln, struct s_buffer *bf)
{
	*ln.nw_ln = malloc(*ln.o_size + *bf.mxlen - *bf.idx);
	if (!*ln.nw_ln)
		return (NULL);
	*ln.nw_size = 0;
	while (*ln.o_size > 0)
		*ln.nw_ln[*ln.nw_size++] = *ln.o_ln[*ln.o_size--];
	if (*ln.o_ln)
		free (*ln.o_ln);
	while (*bf.idx < *bf.mxlen)
		*ln.nw_ln[ln.nw_size++] = *bf.buf[*bf.idx++];
	return (*ln.nw_ln);
}
// construir funciones ins_part_ln_r y e_ln_n
char	*givline(struct s_buffer *bf, int fd)
{
	struct s_nl	ln;
	char		*mark;

	ln.o_ln = NULL;
	ln.nw_ln = NULL;
	mark = NULL;
	while (!mark)
	{
		mark = srch_nl(bf);
		if (!mark)
		{
			if (*bf.mxlen < BUFFER_SIZE)
				return (e_ln_n_null(&ln, bf));
			if (*bf.idx == BUFFER_SIZE)
				ins_part_ln_r(&ln, bf, fd);
			if (!ln.o_ln)
				return (NULL);
		}
	}
	return (e_ln_n(&ln, bf, mark);
}
