/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:33:38 by echerell          #+#    #+#             */
/*   Updated: 2021/07/02 22:55:47 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_thread	*lstnew_fd(int fd, char *buf)
{
	t_thread *new;

	new = (t_thread *)malloc(sizeof(t_thread));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->strs = buf;
	new->next = NULL;
	return (new);
}
