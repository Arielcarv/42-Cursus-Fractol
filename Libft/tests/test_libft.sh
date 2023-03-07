#!/usr/bin/env bash

ABS_PATH=$(git rev-parse --show-toplevel)

## ft_isalpha.c
echo -e "1 - ft_isalpha TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_isalpha.c $ABS_PATH/tests/ft_isalpha_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_isdigit.c
echo -e "2 - ft_isdigit TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_isdigit.c $ABS_PATH/tests/ft_isdigit_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_isalnum.c
echo -e "3 - ft_isalnum TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_isalnum.c $ABS_PATH/tests/ft_isalnum_main.c $ABS_PATH/Libft/ft_isalpha.c $ABS_PATH/Libft/ft_isdigit.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_isacii.c
echo -e "4 - ft_isascii TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_isascii.c $ABS_PATH/tests/ft_isascii_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_isprint.c
echo -e "5 - ft_isprint TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_isprint.c $ABS_PATH/tests/ft_isprint_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_strlen.c
echo -e "6 - ft_strlen TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_strlen.c $ABS_PATH/tests/ft_strlen_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_memset.c
echo -e "7 - ft_memset TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_memset.c $ABS_PATH/tests/ft_memset_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_bzero.c
echo -e "\n8 - ft_bzero TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_bzero.c  $ABS_PATH/tests/ft_bzero_main.c
$ABS_PATH/out
rm $ABS_PATH/out


echo -e "\n9 - ft_memcpy TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_memcpy.c $ABS_PATH/Libft/ft_strlen.c $ABS_PATH/tests/ft_memcpy_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_strlcpy.c
echo -e "\n11 - ft_strlcpy TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_strlcpy.c $ABS_PATH/tests/ft_strlcpy_main.c $ABS_PATH/Libft/ft_strlen.c -lbsd
$ABS_PATH/out
rm $ABS_PATH/out

## ft_toupper.c
echo -e "13 - ft_toupper TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_toupper.c $ABS_PATH/tests/ft_toupper_main.c
$ABS_PATH/out
rm $ABS_PATH/out

## ft_tolower.c
echo -e "14 - ft_tolower TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_tolower.c $ABS_PATH/tests/ft_tolower_main.c
$ABS_PATH/out
rm $ABS_PATH/out


## PART 2
echo -e "26 - ft_strtrim TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_strtrim.c $ABS_PATH/tests/ft_strtrim_main.c $ABS_PATH/Libft/ft_strlen.c $ABS_PATH/Libft/ft_strchr.c $ABS_PATH/Libft/ft_substr.c $ABS_PATH/Libft/ft_strlcpy.c $ABS_PATH/Libft/ft_strdup.c $ABS_PATH/Libft/ft_memcpy.c
$ABS_PATH/out
rm $ABS_PATH/out

## PART 2
echo -e "27 - ft_split TEST"
cc -Wall -Wextra -Werror -o $ABS_PATH/out $ABS_PATH/Libft/ft_split.c $ABS_PATH/tests/ft_split_main.c $ABS_PATH/Libft/ft_calloc.c $ABS_PATH/Libft/ft_substr.c $ABS_PATH/Libft/ft_bzero.c $ABS_PATH/Libft/ft_strlen.c $ABS_PATH/Libft/ft_strdup.c $ABS_PATH/Libft/ft_strlcpy.c $ABS_PATH/Libft/ft_memcpy.c
$ABS_PATH/out
rm $ABS_PATH/out
