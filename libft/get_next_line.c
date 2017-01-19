/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:59:48 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/11 15:58:01 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_st(char **line, char *buff, char *st)
{
	char	*tmp;
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	c = ft_strnew(1);
	while (buff[i])
	{
		*c = buff[i++];
		if (buff[i - 1] == '\n')
		{
			while (buff[i])
				st[j++] = buff[i++];
			st[j] = '\0';
			free(c);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(*line, c);
		free(tmp);
	}
	free(c);
	return (0);
}

char	*ft_readline(int const fd, int *flag, char *st, char *buff)
{
	int		ret;
	char	*line;

	line = ft_strnew(0);
	if ((*flag = ft_check_st(&line, st, st)) == 1)
		return (line);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((*flag = ft_check_st(&line, buff, st)) == 1)
			return (line);
	}
	if (ret == -1)
		*flag = (-1);
	else if (*line != '\0')
		*flag = 2;
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	static char	*st[MAX_FD];
	char		*buff;
	int			flag;

	if (fd < 0 || line == NULL || fd > MAX_FD)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (st[fd] == NULL)
		st[fd] = ft_strnew(BUFF_SIZE);
	flag = 0;
	*line = ft_readline(fd, &flag, st[fd], buff);
	free(buff);
	if (flag == -1)
		return (-1);
	else if (flag == 2)
		st[fd][0] = '\0';
	else if (flag == 0)
		return (0);
	return (1);
}
