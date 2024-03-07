for j in $(cat ./input_commands.txt);
do
	while read i;
	do
		echo -e "$j" | valgrind --leak-check=full --error-exitcode=42 ./checker  "$i"
		retVal=$?
		if [ $retVal -ne 0 ]; then
			echo "[Error code=$retVal] in_cmd=$j input=$i"
			exit
		fi
		output="$(echo -e "$j" | ./checker "$i")"
		valid_output="$(echo -e "$j" | ./../checker_linux "$i")"
		if [ "$output" != "$valid_output" ]; then
			echo "[Error output] in_cmd=\"$j\" input=\"$i\" output=\"$output\" valid_output=\"$valid_output\"" >> error_output3.txt
			#exit
		fi
	done < ./input_sample.txt
done
