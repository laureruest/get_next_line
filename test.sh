# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 12:53:43 by lruiz-es          #+#    #+#              #
#    Updated: 2024/02/25 17:58:34 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sh ./test.sh
#Coment when finished
DEBUG=
#test from console

for s in BUFFER_SIZE=1 BUFFER_SIZE=2 BUFFER_SIZE=3 BUFFER_SIZE=4 BUFFER_SIZE=9 BUFFER_SIZE=10 BUFFER_SIZE=11 BUFFER_SIZE=20 BUFFER_SIZE=15 BUFFER_SIZE=30 BUFFER_SIZE=42 BUFFER_SIZE=4096
	do
		echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK
		echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		echo $s $s $s $s $s $s $s $s $s $s $s $s $s
		echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		cc -Wall -Werror -Wextra -D $s *.c *.h
		mv a.out x_toleaks;
		cc -fsanitize=address -Wall -Werror -Wextra -D $s *.c *.h
		mv a.out x_to_ov;
		echo Standard Input;
		cd ./test_input_files
		for f in *;
			do
				cat $f | ../x_to_ov > ../user_output/${f%.*}.out;
				echo "Test for the input file" $f "coming from std input fd0";
				echo;
			hexdump ../user_output/${f%.*}.out > ../user_output/${f%.*}.output;
			diff --suppress-common-lines -y ../test_output_files/${f%.*}.dump ../user_output/${f%.*}.output;

			done;
		echo Input From Files;
		for f in *;
			do
				../x_to_ov $f > ../user_output/${f%.*}.out;
		    hexdump ../user_output/${f%.*}.out > ../user_output/${f%.*}.output;
			echo "Test for the input file:  ./test_input_files/" $f;
			diff --suppress-common-lines -y ../test_output_files/${f%.*}.dump ../user_output/${f%.*}.output; 
			echo;
			echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO;
			echo OOOOOOOOOOOOPRUEBA DE LEAKSOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO;
			echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO;
			leaks --atExit -- ../x_toleaks $f;
			done;
	cd ..
	done;
