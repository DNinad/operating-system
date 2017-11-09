#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>
       #define SIZE 2
       int buf[SIZE],buf1=0;
       int main()
       {
           int pipefd[2],pipefd1[2],i;
           
           pid_t cpid;
          
           ssize_t r_rtrn,w_rtrn;
			
          if (pipe(pipefd) == -1)
           {
               perror("pipe");
               exit(EXIT_FAILURE);
           }
           
           if (pipe(pipefd1) == -1)//pipe 2nd 
           {
               perror("pipe");
               exit(EXIT_FAILURE);
           }
           for(i=0;i<=1;i++){
           
				scanf("%d",&buf[i]);
           
           }

           cpid = fork();
           if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (cpid == 0) {    /* Child reads from pipe */
         
            	ssize_t r_rtrn=read(pipefd[0], buf, 1);
            		if(r_rtrn == -1){
            			perror("read error");
            		} 
            		printf("value of buf in child before addition %d %d \n",buf[0],buf[1]); 
            		
            		buf1=buf[0]+buf[1];
            		
            		printf("sum  num1  num %d %d %d \n",buf1,buf[0],buf[1]);  
               		close(pipefd[0]);
               		
               		
               		ssize_t w_rtrn = write(pipefd1[1], &buf1, 1);
               		 	if(r_rtrn == -1){
            				perror("write error");
            			} 
               		close(pipefd1[1]);
               		
               		
             }

            else {            /* Parent writes argv[1] to pipe */
           
              ssize_t w_rtrn = write(pipefd[1], buf, 1);
              if(r_rtrn == -1){
            			perror("write error");
            		} 
               close(pipefd[1]); 
               
               ssize_t r_rtrn=read(pipefd1[0], buf, 1);
            		if(r_rtrn == -1){
            			perror("read error");
            		} 
               
               printf("sum in parent %d \n",buf[0]);  
               		close(pipefd1[0]);
               		
           }
           
       }

