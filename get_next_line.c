/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:13:38 by echerell          #+#    #+#             */
/*   Updated: 2021/07/02 23:48:18 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// temporarily
#include "stdio.h"

/*static void	check(t_thread *threads)
{
	//t_thread *save;

	//save = *threads;
	while (threads->next)
	{
		printf("fd = %d\nstring = %s\n", threads->fd, threads->strs);
		threads = threads->next;
	}
}*/

static int	first_read(t_thread *thread, int fd, char *buf)
{
	int	read_ret;

	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret == -1)
	{
		free(buf);
		return (-1);
	}
	if (read_ret == 0)
		return (0);
	thread = lstnew_fd(fd, buf);
	if (!thread)
		return (-1);
	return (1);
}

static int	goto_fd(t_thread **threads, t_thread *save, int fd, char *buf)
{
	save = *threads;
	if (!(*threads))
		return (first_read(*threads, fd, buf));
	while (save->next && save->fd != fd)
		save = save->next;
	if (save->fd == fd)
		return (1);
	return (first_read(save->next, fd, buf));
}

int	get_next_line(int fd, char **line)
{
	static t_thread	*threads;
	t_thread		*save;
	int				ret;
	char			*buf;

	buf = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (BUFFER_SIZE < 1 || fd < 0 || !line || !buf)
		return (-1);
	save = NULL;
	ret = goto_fd(&threads, save, fd, buf);
	printf("fd = %d\nstring = %s\n", threads->fd, threads->strs);
	return (ret);
}
