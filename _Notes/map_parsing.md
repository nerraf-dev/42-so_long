I have a map file , `test.ber`.
I have to:
Verify the file exists - exit if not.
If file exists:
Parse the file checking the follwoing rules:
- The map must contain **1 exit**, at least **1 collectible**, and **1 starting position** to
be valid.

- If the map contains a duplicates characters (exit/start), you should
display an error message.

- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return
an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map, as long as it respects the above rules.
- If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.

It is a 42  Network project, so_long, and so I ahve to respect the rules and only use a limted functioon set plus previous work which I have added as git submodules - libft, get_next_line.
External functs.
• open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded

I plan to use get_next_line (read as: gnl) to read line by line. I think I should count the lines in a file. Anything less than 3 lines will make it impossible to make a valid map (walls on line 1 and 3. Line 2 starts and ends with a wall and contains the start, end and collectable). I think that at this point when counting I should copy the line to an array of strings.

My initial plan:
* Initialise a set of variables as flags and counters.
	* Line count - store the number of lines in the file.
	* Line length - store the length of the first line. This becomes the standard for all other lines.
	* Start - boolean flag to indicate if the start character is present.
	* End - boolean flag to indicate if the end character is present.
	* Collectable - boolean flag to indicate if the collectable character is present.

* Open the file.
* Read the file line by line using gnl.
	* Count the lines.
	* Check the line length.
		* If the line length is not the same as the first line, exit with line length error.
	* Copy the line to an array of strings.
	* Check the first and last lines.
		* If the first and last lines are not all walls, exit with wall error.
	For each remaining line:
		* Check the first and last characters of the line.
			* If the first and last characters are not walls (not 1), exit with wall error.
		* Check the characters in between.
			* If the characters are not valid, exit with character error.
			* If the characters are valid:
				* If 'C', set the collectable flag.
				* If 'E', set the end flag.
				* If 'P', set the start flag.
			* If a flag is already true when trying to set, exit with duplicate + character error.
* Close the file.
* Check the flags.
	* If any flag is false, exit with missing flag error.
* Check the map for a valid path.
	* If there is no valid path, exit with no path error.
* If all checks pass, return 0.

