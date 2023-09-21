/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:00:00 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 11:00:00 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tester.h"
#include <stdio.h>

TESTER("yaassila's ft_printf tester", {
	group("%c", { test(printf("Hello, %c!\n", 'Y') == ft_printf("Hello, %c!\n",
				'Y')); });
	group("%s", {
		test(printf("Hello, %s!\n", "World") == ft_printf("Hello, %s!\n",
				"World"));
		test(printf("Hello, %s!\n", NULL) == ft_printf("Hello, %s!\n", NULL));
	});
	group("%p", {
		int *ptr = 42;
		char *str = "Hello, World!";

		test(printf("Address: %p\n", ptr) == ft_printf("Address: %p\n", ptr));
		test(printf("Address: %p\n", str) == ft_printf("Address: %p\n", str));
		test(printf("Address: %p\n", NULL) == ft_printf("Address: %p\n", NULL));
	});
	group("%d", {
		test(printf("Hello, %d!\n", 213) == ft_printf("Hello, %d!\n", 213));
		test(printf("Hello, %d!\n", -213) == ft_printf("Hello, %d!\n", -213));
		test(printf("Hello, %d!\n", 2147483647) == ft_printf("Hello, %d!\n",
				2147483647));
		test(printf("Hello, %d!\n", -2147483648) == ft_printf("Hello, %d!\n",
				-2147483648));
		test(printf("Hello, %d!\n", 0) == ft_printf("Hello, %d!\n", 0));
	});
	group("%i", {
		test(printf("Hello, %i!\n", 213) == ft_printf("Hello, %i!\n", 213));
		test(printf("Hello, %i!\n", -213) == ft_printf("Hello, %i!\n", -213));
		test(printf("Hello, %i!\n", 2147483647) == ft_printf("Hello, %i!\n",
				2147483647));
		test(printf("Hello, %i!\n", -2147483648) == ft_printf("Hello, %i!\n",
				-2147483648));
		test(printf("Hello, %i!\n", 0) == ft_printf("Hello, %i!\n", 0));
	});
	group("%u", {
		test(printf("Hello, %u!\n", 213) == ft_printf("Hello, %u!\n", 213));
		test(printf("Hello, %u!\n", -213) == ft_printf("Hello, %u!\n", -213));
		test(printf("Hello, %u!\n", 2147483647) == ft_printf("Hello, %u!\n",
				2147483647));
		test(printf("Hello, %u!\n", -2147483648) == ft_printf("Hello, %u!\n",
				-2147483648));
		test(printf("Hello, %u!\n", 0) == ft_printf("Hello, %u!\n", 0));
	});
	group("%x", {
		test(printf("Hello, %x!\n", 213) == ft_printf("Hello, %x!\n", 213));
		test(printf("Hello, %x!\n", -213) == ft_printf("Hello, %x!\n", -213));
		test(printf("Hello, %x!\n", 2147483647) == ft_printf("Hello, %x!\n",
				2147483647));
		test(printf("Hello, %x!\n", -2147483648) == ft_printf("Hello, %x!\n",
				-2147483648));
		test(printf("Hello, %x!\n", 0) == ft_printf("Hello, %x!\n", 0));
	});
	group("%X", {
		test(printf("Hello, %X!\n", 213) == ft_printf("Hello, %X!\n", 213));
		test(printf("Hello, %X!\n", -213) == ft_printf("Hello, %X!\n", -213));
		test(printf("Hello, %X!\n", 2147483647) == ft_printf("Hello, %X!\n",
				2147483647));
		test(printf("Hello, %X!\n", -2147483648) == ft_printf("Hello, %X!\n",
				-2147483648));
		test(printf("Hello, %X!\n", 0) == ft_printf("Hello, %X!\n", 0));
	});
	group("%%", {
		test(printf("%%\n") == ft_printf("%%\n"));
		test(printf("%%, %s\n", "TEST") == ft_printf("%%, %s\n", "TEST"));
	});
	group("Mix", { test(printf("%s%d%c\n", "John", 42,
				'J') == ft_printf("%s%d%c\n", "John", 42, 'J')); });
	group("WTF", {
		test(printf("%?   d\n", 123) == ft_printf("%?   d\n", 123));
		test(printf("%%%\n") == ft_printf("%%%\n"));
	});
	group("`write` error handling", {
		int status;

		dup2(STDOUT_FILENO, 3);
		close(STDOUT_FILENO);
		status = ft_printf("Hello World\n");
		dup2(3, STDOUT_FILENO);
		close(3);
		test(status == -1);
	});
});
