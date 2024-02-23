/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:15:38 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/23 19:09:19 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# ifndef STDLIB_H
#  include <stdlib.h>
#  define STDLIB_H
# endif
# ifndef UNISTD_H
#  include <unistd.h>
#  define UNISTD_H
# endif

struct	s_buffer
{
	long long int	idx;
	long long int	mxlen;
	char			buf[BUFFER_SIZE];
};

struct	s_nl
{
	long long int	o_size;
	long long int	nw_size;
	char			*o_ln;
	char			*nw_ln;
};

char	*get_next_line(int fd);
# define GET_NEXT_LINE_H
#endif
/*

   
	Function name:	get_next_line
	Prototype:		char *get_next_line(int fd);
	Usage:			Including in libraries with get_next_line.h
	Compiling:
					With CC **-D BUFFER_SIZE={size bytes}
					Implicit BUFFER_SIZE = 4096 bytes
				   			(stat -f %k /Users/lruiz-es)
		
	Parameters:		fd: The file descriptor to read from
	Return value:	Read line: correct behavior
					NULL: there is no nothing else to read, or an error ocurred

	Description: 	The function returns a line readed from a file descriptor
*/
