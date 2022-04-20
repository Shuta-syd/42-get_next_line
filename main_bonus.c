/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:51 by shogura           #+#    #+#             */
/*   Updated: 2022/04/20 14:46:24 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void test(int fd)
{
	int index; //読み込み回数を確認する用
	char *receiver = NULL;
	index = 0;
	while (1)
	{
		receiver = get_next_line(fd);
		if (receiver == NULL)
		{
			printf("EOF or ERROR\n");
			break;
		}
		printf("[%d] -> %s\n", index, receiver);
		index++;
		free(receiver);
	}
}

int main(void)
{
	int	fd1;
	int fd2;
	int fd3;
	int fd4;

	char file_name[][100] = {
			"gnlTester/files/41_with_nl",
			"gnlTester/files/42_with_nl",
			"gnlTester/files/43_with_nl",
			"gnlTester/files/alternate_line_nl_with_nl",
	};

	fd1 = open(file_name[0], O_RDONLY);
	fd2 = open(file_name[1], O_RDONLY);
	fd3 = open(file_name[2], O_RDONLY);
	fd4 = open(file_name[2], O_RDONLY);
	printf("==========================MUSTIPLE==========================\n\n");
	test(fd1);
	test(fd2);
	test(fd3);
	test(fd4);
	printf("=============================END============================\n\n");
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return 0;
}
