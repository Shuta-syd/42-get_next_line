/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:07:18 by shogura           #+#    #+#             */
/*   Updated: 2022/04/18 22:00:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *read_and_check(int fd, bool *newline_b)
{
	//buf to return
	char *ret_line;
	//buf to read(2)
	char read_buf[BUFFER_SIZE + 1];
	// read bytes
	int read_byte;

	ret_line = NULL;
	memset(read_buf, 0, BUFFER_SIZE + 1);
	read_byte = read(fd, read_buf, BUFFER_SIZE);
	if (read_byte == -1 || read_byte == 0)
	{
		//printf("3.pass\n");
		return (NULL);
	} //reading error
	ret_line = ft_strdup(read_buf);
	if (ret_line == NULL) //malloc(3) error
		return (NULL);
	//printf("2.pass\n");
	if (ft_strchr(ret_line, '\n') != NULL) // if there is newline in ret_line
		*newline_b = true;
	return (ret_line);
}

char *read_and_join(int fd, char *line_buf, bool *newline_b)
{
	//buf to return
	char *ret_line;
	//buf to read(2)
	char read_buf[BUFFER_SIZE + 1];
	// read bytes
	int read_byte;

	ret_line = NULL;
	memset(read_buf, 0, BUFFER_SIZE + 1);
	read_byte = read(fd, read_buf, BUFFER_SIZE);
	if (read_byte == -1) //reading error
		return (NULL);
	else if (read_byte == 0) // end of file case
	{
		*newline_b = true;
		return (line_buf);
	}
	ret_line = ft_strjoin(line_buf, read_buf);
	free(line_buf);
	if (ret_line == NULL) //malloc(3) error
		return (NULL);
	if (ft_strchr(ret_line, '\n') != NULL) // if there is newline in ret_line
		*newline_b = true;
	return (ret_line);
}

char *get_next_line(int fd)
{
	//line buf(all str)
	char *line_buf;
	// to save after newline | static var is automatically initialized
	static char *save_buf;
	//bool var to check newline yes or no
	bool newline_b;
	//line to return
	char *ret_line;
	//len from 0 to '\n'
	size_t	len;
	// initialize vars
	len = 1;
	line_buf = NULL;
	newline_b = false;
	printf("(%s)", save_buf);
	// no newline
	if (newline_b == false && save_buf == NULL)
	{
		//printf("1.pass\n");
		//read and check '\n' in line_buf
		line_buf = read_and_check(fd, &newline_b);
		while (newline_b == false && line_buf != NULL)
		{
			// read and join line_buf and read_buf
			line_buf = read_and_join(fd, line_buf, &newline_b);
		}
	}
	else if (newline_b == false && save_buf != NULL)
	{
		line_buf = read_and_join(fd, save_buf, &newline_b);
		save_buf = NULL;
		while (newline_b == false && line_buf != NULL)
		{
			// read and join line_buf and read_buf
			line_buf = read_and_join(fd, line_buf, &newline_b);
		}
	}
	printf("[%s]", line_buf);
	if (line_buf == NULL)
	{
		return (NULL);
	} //eof case or error case
	//printf("4.pass\n");
	while (line_buf[len - 1] != '\0') // len to '\n'
		len++;
	ret_line = ft_substr(line_buf, 0, len); //grep from 0 to '\n'
	//printf("[%s]\n", ret_line);
	if (ret_line == NULL)
		return (NULL);
	printf("=%zu=+%zu+", ft_strlen(line_buf), len);
	if (ft_strlen(line_buf) - (len - 1) && ft_strlen(line_buf) != 1)
	{
		printf("6.pass\n");
		save_buf = ft_substr(line_buf, len, ft_strlen(line_buf) - len);
		if (save_buf == NULL)
		{
			free(line_buf);
			return (NULL);
		}
	}
	free(line_buf);
	return (ret_line);
}

//int main(void)
//{
//	int index; //読み込み回数を確認する用
//	int fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
//	int i= 5;
//	char *receiver = NULL;
//	index = 0;
//	while (1)
//	{
//		receiver = get_next_line(fd);
//		//printf("{10.pass}\n");
//		if (receiver == NULL)
//		{
//			//printf("aa");
//			printf("EOF or ERROR");
//			break;
//		}
//		printf("[%d] ->%s\n", index, receiver);
//		index++;
//		free(receiver);
//	}
//	system("leaks a.out");
//	close(fd);
//}
