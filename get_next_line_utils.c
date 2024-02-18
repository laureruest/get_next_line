/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:20:39 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/18 13:26:35 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*release(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*givline(char *buffer, ssize_t idx, ssize_t maxlen)
{
	char	*ptrj;

	ptrj = memchr(&buffer[idx], '\n', (maxlen - idx ));
	if (!ptrj)


}




