# ft_printf-tester

## Installation

```sh
git clone https://github.com/younesaassila/ft_printf-tester.git
cd ft_printf-tester
```

## Build

```sh
INCLUDE_DIR=../includes
LIBFT_DIR=../libft
make -C .. && make -C .. clean && cc -Wno-format -I$INCLUDE_DIR -I$LIBFT_DIR -o tester tester.c -L.. -lftprintf
```

## Usage

```sh
./tester
```
