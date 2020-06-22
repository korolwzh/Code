#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "restart.h"
#include "fileio.h"
#include <string.h>

#if 1
#define VERBOSE(p) (p)
#else
#define VERBOSE(p) (0)
#endif

char* itoa(long value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

int file_read(char *path, int offset, void *buffer, size_t bufbytes)
{

	   if (!path || !buffer || bufbytes <1) return IOERR_INVALID_ARGS;
	   FILE *fp;
	   fp = fopen(path, "r+");
	   if(fp == NULL) return IOERR_INVALID_PATH;
	   if(fseek(fp,offset,SEEK_CUR)!=0) return IOERR_INVALID_ARGS;

	   char infor[bufbytes];
	   int c,n=0;
	   do  {
		   	   if(n>bufbytes) {
		   		   //infor[bufbytes-1]='\0';
		   		   strcpy((char*)buffer, infor);
		   		   return n-1;
		   	   }
	           c=getc(fp);
	           if (c == EOF) break;
	           infor[n]=(char)c;
	           n++;
	           }
	       while(1);
	    fclose(fp);
	    strcpy((char*)buffer, infor);

	return n;//IOERR_NOT_YET_IMPLEMENTED;
}

int file_info(char *path, void *buffer, size_t bufbytes)
{

    if (!path || !buffer || bufbytes < 1) return IOERR_INVALID_ARGS;

	int fd = open(path, O_RDWR, 0777);

    if (fd == -1) return IOERR_INVALID_ARGS;

	struct stat fileStat;
	if(fstat(fd,&fileStat) < 0) return IOERR_POSIX;

	char typ;
	if (S_ISREG(fileStat.st_mode) != 0) typ = 'f';// is a file
	if (S_ISDIR(fileStat.st_mode) != 0) typ = 'd'; // is a directory
	//"Size:NNN Accessed:NNN Modified:NNN Type X" itoa(num, snum, 10);"Size:%d Accessed:%d Modified:%d Type %s"
	char c1[]="Size:";
	char c2[5]; itoa(fileStat.st_size,c2,10);
	char c3[]=" Accessed:";
	char c4[15];itoa(fileStat.st_atime,c4,10);
	char c5[]=" Modified:";
	char c6[15];itoa(fileStat.st_mtime,c6,10);
	char c7[]=" Type ";


	int s = strlen(c1)+strlen(c2)+strlen(c3)+strlen(c4)+strlen(c5)+strlen(c6)+strlen(c7)+2;
	char infor[s];
	int j = 0;
	for (int i = 0;i<strlen(c1);i++){
		if (c1[i]=='\0') break;
		infor[j]=c1[i];
		j++;
	}
	for (int i = 0;i<strlen(c2);i++){
		if (c2[i]=='\0') break;
		infor[j]=c2[i];
		j++;
	}
	for (int i = 0;i<strlen(c3);i++){
		if (c3[i]=='\0') break;
		infor[j]=c3[i];
		j++;
	}
	for (int i = 0;i<strlen(c4);i++){
		if (c4[i]=='\0') break;
		infor[j]=c4[i];
		j++;
	}
	for (int i = 0;i<strlen(c5);i++){
		if (c5[i]=='\0') break;
		infor[j]=c5[i];
		j++;
	}
	for (int i = 0;i<strlen(c6);i++){
		if (c6[i]=='\0') break;
		infor[j]=c6[i];
		j++;
	}
	for (int i = 0;i<strlen(c7);i++){
		if (c7[i]=='\0') break;
		infor[j]=c7[i];
		j++;
	}
  infor[j] = typ;
  infor[j+1]='\0';
  close(fd);

  strcpy((char*)buffer, infor);

    return 0;//IOERR_NOT_YET_IMPLEMENTED;
}

int file_write(char *path, int offset, void *buffer, size_t bufbytes)
{

   if (!path || !buffer || bufbytes <1) return IOERR_INVALID_ARGS;

   FILE *fp;
   fp = fopen(path, "w");
   if(fp == NULL) return IOERR_INVALID_PATH;
   if(fseek(fp,offset,SEEK_CUR)!=0) return IOERR_INVALID_ARGS;

   char infor[bufbytes];
   strcpy(infor,(char*)buffer);
  int i;
  int c;
 for( i =0; i<bufbytes;i++){
	c=putc((int)(infor[i]),fp);
	if (c == EOF){
		break;
	}
 }
 fclose(fp);

	return i;//IOERR_NOT_YET_IMPLEMENTED;
}

int file_create(char *path, char *pattern, int repeatcount)
{
    if(!path || !pattern || repeatcount <1) return  IOERR_INVALID_ARGS;

    int len=strlen(pattern);

    char infor[len*repeatcount];
    int c=0;
    for(int i= 0; i<repeatcount;i++){
    	   	for(int j=0;j<len;j++){
    	   		infor[c] = pattern[j];
    	   		c++;
    	   	}
    }

    file_write(path,0, infor, len*repeatcount);

	return 0;//IOERR_NOT_YET_IMPLEMENTED;
}

int file_remove(char *path)
{
	if (!path) return IOERR_INVALID_ARGS;
		if (unlink(path) == -1) return IOERR_INVALID_PATH;
		return 0;//IOERR_NOT_YET_IMPLEMENTED;
}

int dir_create(char *path)
{
	if (!path) return IOERR_INVALID_ARGS;
		struct stat st = {0};

		if (stat(path, &st) == -1) {
			if (mkdir(path, 0700) == -1) return IOERR_INVALID_PATH;
			return 0;
		}

	    return IOERR_INVALID_PATH;//IOERR_NOT_YET_IMPLEMENTED;
}

int dir_list(char *path, void *buffer, size_t bufbytes)
{
    if(!path || !buffer || bufbytes <1) return IOERR_INVALID_ARGS;

    struct dirent *pDirent;
    DIR *pDir;
	int count  =0;
	pDir = opendir (path);
        if (pDir == NULL) {

            return IOERR_INVALID_PATH;
        }

        char infor[bufbytes];
        while ((pDirent = readdir(pDir)) != NULL) {
		   for(int i =0;i<strlen(pDirent->d_name);i++){
			 if(count > bufbytes) return IOERR_BUFFER_TOO_SMALL;

		     infor[count] = pDirent->d_name[i];
			 count++;
		   }
		   infor[count] = '\n';
		   count ++;
        }
        closedir (pDir);
        strcpy((char*)buffer,infor);
	return 0;//IOERR_NOT_YET_IMPLEMENTED;
}


int file_checksum(char *path)
{
	 if(!path) return IOERR_INVALID_ARGS;

		 FILE *fileptr;
		//char *buffer;
		long filelen;

		if ((fileptr = fopen(path, "r")) == NULL) return IOERR_INVALID_PATH;  // Open the file in binary mode
		fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
		filelen = ftell(fileptr);             // Get the current byte offset in the file
		fclose(fileptr); // Close the file
		char infor[filelen];
		file_read(path,0,infor,filelen);

	    return checksum(infor,filelen,0);//IOERR_NOT_YET_IMPLEMENTED;
}

int dir_checksum(char *path)
{
    if(!path) return IOERR_INVALID_ARGS;
    	int chuks=0;
    	int chukd=0;
        char path1[10000];
       strcpy(path1,path);
	   char infor[10000];
	   dir_list(path1, infor,sizeof(infor));
	   if(!memchr(infor, 0, sizeof(infor))) return -1;
	   char *next_line,*last;
	   next_line = strtok_r(infor, "\n", &last);
	   while (next_line) {

		 char tc[10000];
		 strcpy(tc,path1);

	  	int args_read;
	  	char name[256];
	  	int temp;
	  	args_read = sscanf(next_line, "%255s", name);
	  	if((strstr(name, "..")|| strstr(name, ".")) && !strstr(name, ".txt")) {next_line = strtok_r(NULL, "\n", &last);continue;}
	  	if(args_read != 1) break;
	  	strcat(tc, "/");
	  	strcat(tc, name);

	  	struct stat path_stat;
	    stat(tc, &path_stat);

	  	 char typ;
	  	 if (S_ISREG(path_stat.st_mode) != 0) typ = 'f';// is a file
	  	 if (S_ISDIR(path_stat.st_mode) != 0) typ = 'd'; // is a directory


	  	if (typ=='f'){
	  		temp=file_checksum(tc);
	  		chuks=temp+chuks;
	  	}else {

			if(typ=='d'){
				temp=dir_checksum(tc);
				chuks=temp+chuks+checksum(name,strlen(name),0);
			}
	  	}
	  	next_line = strtok_r(NULL, "\n", &last);
	  }



	return chuks;//IOERR_NOT_YET_IMPLEMENTED;
}
