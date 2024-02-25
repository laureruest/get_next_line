/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:20:39 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/25 14:30:14 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long int	srch_nl(struct s_buffer *bf)
{
	long long int	cur;

	cur = bf->idx;
	while (cur < bf->mxlen)
	{
		if (bf->buf[cur] == '\n')
			return (cur);
		cur++;
	}
	return (-1);
}

void	ins_part_ln_r(struct s_nl *ln, struct s_buffer *bf, int fd)
{
	long long int	idx;

	ln->nw_ln = malloc(ln->o_size + BUFFER_SIZE);
	if (ln->nw_ln)
	{
		idx = 0;
		ln->nw_size = 0;
		while (ln->o_size > 0)
		{
			ln->nw_ln[ln->nw_size++] = ln->o_ln[idx++];
			ln->o_size--;
		}
		if (ln->o_ln)
			free (ln->o_ln);
		while (bf->idx < BUFFER_SIZE)
			ln->nw_ln[ln->nw_size++] = bf->buf[bf->idx++];
		ln->o_size = ln->nw_size;
		bf->idx = 0;
		bf->mxlen = read(fd, &bf->buf[0], BUFFER_SIZE);
	}
	ln->o_ln = ln->nw_ln;
}

char	*e_ln_n(struct s_nl *ln, struct s_buffer *bf, long long int nll_mark)
{
	long long int	idx;

	ln->nw_ln = malloc(ln->o_size + 2 + nll_mark - bf->idx);
	if (!ln->nw_ln)
		return (NULL);
	ln->nw_size = 0;
	idx = 0;
	while (ln->o_size > 0)
	{
		ln->nw_ln[ln->nw_size++] = ln->o_ln[idx++];
		ln->o_size--;
	}
	if (ln->o_ln)
		free(ln->o_ln);
	while (bf->idx <= nll_mark)
		ln->nw_ln[ln->nw_size++] = bf->buf[bf->idx++];
	ln->nw_ln[ln->nw_size] = '\0';
	return (ln->nw_ln);
}

char	*e_ln_n_n(struct s_nl *ln, struct s_buffer *bf)
{
	long long int	idx;
	long long int	limit;

	limit = ln->o_size + 1 + bf->mxlen - bf->idx;
	ln->nw_ln = malloc(ln->o_size + 1 + bf->mxlen - bf->idx);
	if (!ln->nw_ln)
		return (NULL);
	ln->nw_size = 0;
	idx = 0;
	while (ln->o_size > 0)
	{
		ln->nw_ln[ln->nw_size++] = ln->o_ln[idx++];
		ln->o_size--;
	}
	if (ln->o_ln)
		free (ln->o_ln);
	while (bf->idx < bf->mxlen)
		ln->nw_ln[ln->nw_size++] = bf->buf[bf->idx++];
	if (ln->nw_size < limit)
		ln->nw_ln[ln->nw_size] = '\0';
	return (ln->nw_ln);
}

char	*givline(struct s_buffer *bf, int fd)
{
	struct s_nl		ln;
	long long int	id_mrk;

	ln.nw_ln = NULL;
	ln.o_ln = NULL;
	ln.o_size = 0;
	ln.nw_size = 0;
	id_mrk = -1;
	while (id_mrk == -1)
	{
		id_mrk = srch_nl(bf);
		if (id_mrk == -1)
		{
			if (bf->mxlen < BUFFER_SIZE)
				return (e_ln_n_n(&ln, bf));
			if (bf->mxlen == BUFFER_SIZE)
				ins_part_ln_r(&ln, bf, fd);
			if (bf->mxlen < 1)
				return (e_ln_n_n(&ln, bf));
			if (!ln.o_ln)
				return (NULL);
		}
	}
	return (e_ln_n(&ln, bf, id_mrk));
}
