/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:51 by shogura           #+#    #+#             */
/*   Updated: 2022/04/20 11:19:03 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

//void test(int fd)
//{
//	int index; //読み込み回数を確認する用
//	char *receiver = NULL;
//	index = 0;
//	while (1)
//	{
//		receiver = get_next_line(fd);
//		if (receiver == NULL)
//		{
//			printf("\nEOF or ERROR");
//			break;
//		}
//		printf("[%d] -> %s", index, receiver);
//		index++;
//		free(receiver);
//	}
//}

//int main(void)
//{
//	int fd = open("test_files/empty", O_RDONLY);
//	printf("\x1b[34mempty\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/onlynl", O_RDONLY);
//	printf("\x1b[34m\nonlynl\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/36_no_nl", O_RDONLY);
//	printf("\x1b[34m\n36_no_nl\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/36_with_nl", O_RDONLY);
//	printf("\x1b[34m\n36_with_nl\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/alter_nl_line", O_RDONLY);
//	printf("\x1b[34m\nalter_nl_line\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/bigline_only_nl", O_RDONLY);
//	printf("\x1b[34m\nbigline_only_nl\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/bigline_with_nl", O_RDONLY);
//	printf("\x1b[34m\nbigline_with_nl\n\033[m");
//	test(fd);
//	close(fd);
//	fd = open("test_files/bigline_no_nl", O_RDONLY);
//	printf("\x1b[34m\nbigline_no_nl\n\033[m");
//	test(fd);
//	close(fd);
//}
//#include <stdio.h>
//#include <stdlib.h>
//int main(int argc, char const *argv[])
//{
//	char *str = malloc(sizeof(char) * 10);
//	free(str);
//	str = NULL;
//	printf("%s", str);
//	system("leaks a.out");
//	return 0;
//}
