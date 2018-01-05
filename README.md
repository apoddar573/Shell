# Shell
This is the implementation of a shell written in C language, performing the following tasks.

The main function in as1.c contains a while(1) loop which continously runs to take new inputs for the shell. When we input exit, the program breaks from this while loop and terminates the shell. We have implememnted the following functions here - 

	(a). `cd` - This command changes the current directory of the process. For example, if we need to go to home/new/old from home, we enter the command - cd new/old

	After this command is run, the shell prints the new current directory.

	(b). `ls` - This command lists all the files in the current directory. We use the DIR and dirent data structures to list the files. 

	(c). `rm` - This command is used to delete a file from the current directory. The format is rm <filename>. We use the remove command for this function.

	(d). `history n` - This command prints the last n commands entered in the shell. However, there is a bug here. To print all the commands in the session, we have to write history m, where m is a negative number. Here, we make a list of strings and store each input in this list. A variable, N stores the number of commands entered so far in the session. The maximum number of commands this can print is 300.

	(e). `issue n` - Lists the nth previous command entered in the shell. 

	(f). `<program_name> m` - To run a program(an executable c or c++ file) normally, we have to enter      <program_name> m, where is a negative number. 

	(g). `exit` - Breaks out of the while loop and exits the shell. 

	(h). `rmexcept <list_of_files>` - This function deletes all files except the ones mentioned in the list. The list is written as - 
	filename_1,filename_2,filename_3 with no whitespaces in between. Whitespaces may cause the program to work abnormally. 

	(i). `<program_name> m` - This command runs the program <program_name> and exits if the program does not finish executing in m seconds. This has been implemented through a system call.


Makefile - 

	(a). To run and execute the source code, type `make` command in the shell.

	(b). To clean all the executable and object files, type 'make clean' command in the shell. Make sure to clean the directory before executing the source code.