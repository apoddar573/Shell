#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>


int main() 
{
	char pwd[300];
	char input[300];
	char path[300];
	char list_of_inputs[300][300];
	int N = -1;

	getcwd(pwd, sizeof(pwd));
	printf("%s\n", pwd);		

	while(1) {
		printf(">>");
		scanf("%s", input);
		N += 1;
		strcpy(list_of_inputs[N], input);
		if( !( strcmp(input, "pwd")) ) {
			getcwd(pwd, sizeof(pwd));
			printf("%s\n", pwd);		
		} else if ( !(strcmp(input, "exit")) ) {
			break;
		} else if ( !(strcmp(input, "ls")) ) {
			DIR *d; 
			struct dirent * dir;
			d = opendir(".");
			if(d) {
				while( (dir = readdir(d)) != NULL ) {
					printf("%s\n", dir->d_name );
				}
				closedir(d);
			}
		} else if( !strcmp(input, "cd") ) {
			strcat(list_of_inputs[N], " ");
			scanf("%s", input);
			strcat(list_of_inputs[N], input);
			strcat(pwd, "/");
			strcat(pwd, input);
			chdir(pwd);
			getcwd(pwd, sizeof(pwd));
			printf("%s\n", pwd);			
		} else if ( !strcmp(input, "rm") ) {
			strcat(list_of_inputs[N], " ");
			scanf("%s", input);
			remove(input);	
		} else if ( !(strcmp(input, "history")) ) {
			strcat(list_of_inputs[N], " ");
			int n = N, i;
			scanf("%d", &n);
			if (n<0) {
				n = N;
			}
			for(i = N-1; i>N-n-1; i--) {
				printf("%s\n", list_of_inputs[i] );
			}
		} else if ( !(strcmp(input, "issue")) ) {
			strcat(list_of_inputs[N], " ");
			int n;
			scanf("%d", &n);
			printf("%s\n", list_of_inputs[N-n] );
		} else if ( !(strcmp(input, "rmexcept")) ){
			char list_except[50][100];
			int m=0, i=0, j = 0;
			char list[5000];
			scanf("%s", list);
			while( list[i] != '\0' ) {
				if(list[i] == ',') {
					list_except[m][j] = '\0';
					j = 0;
					m += 1;
				}
				else{
					list_except[m][j] = list[i];
					j++;
				}
				i++;
			}
			/*
			for(i = 0; i<=m; i++) {
				printf("%s\n", list_except[i]);
			}
			*/
			DIR *d; 
			struct dirent * dir;
			d = opendir(".");
			int flag = 0;
			if(d) {
				while( (dir = readdir(d)) != NULL ) {
					flag = 0;
					for(i = 0; i<=m; i++) {
						if ( !(strcmp(dir->d_name, list_except[i])) ) {
							flag = 1;
						}
					}
					if (flag == 0) {
						remove(dir->d_name);
					}
				}
				closedir(d);
			}

		} else {
			char fil[1024] = "";
			strcat(fil, "./");
			strcat(fil, input);
			int n;
			char sn[20];
			scanf("%d", &n);
			if(n < 0) {
				system(fil);
			}
			else {
				sprintf(sn, "%d", n);
				char command[100] = "";
				strcat(command, "timeout ");
				strcat(command, sn);
				strcat(command, "s ");
				strcat(command, fil);
				system(command);
			}
		}

	}
}
