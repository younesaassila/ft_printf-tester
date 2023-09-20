# ft_printf-tester

## Installation

```sh
git clone https://github.com/younesaassila/ft_printf-tester.git
make all
make clean
cd ft_printf-tester
```

## Build

```sh
INCLUDE_DIR=../includes
LIBFT_DIR=../libft
cc -Wall -Wextra -Werror -I$INCLUDE_DIR -I$LIBFT_DIR -L.. -lftprintf -o tester tester.c
```

## Usage

```sh
./tester
```
