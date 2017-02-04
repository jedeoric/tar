#include <stdio.h>
#include "tar.h"
#include <string.h>


extern void print(char *);
extern void returnline();

int read (int fd, void* buf, unsigned count);
unsigned int size;

struct posix_header tar_header;

  char verbose=0;
  char debug=0;
  char extract=0;

char buffer_file_to_extract[20000];
  
void version()
{
	printf("tar 0.0.1\n");
}

void usage()
    {
	// Why print instead of printf ? Because it's a lot quicker !
	print("usage: ");
	returnline();
    print("tar [x][v][d] FILENAME");
	returnline();
	print("tar --version");
	returnline();
	print("Options : ");
	returnline();
	print("x : extract");
	returnline();
	print("v : verbose");
	returnline();
	print("d : debug");
	returnline();
	print("--version : print version");
	returnline();
    return;
    }


	
void print_debug()
{

//  char mode[8];                 /* 100 */
//  char uid[8];                  /* 108 */
//  char gid[8];                  /* 116 */
//  char size[12];                /* 124 */
//  char mtime[12];               /* 136 */
//  char chksum[8];               /* 148 */
//  char typeflag;                /* 156 */
//  char linkname[100];           /* 157 */
//  char magic[6];                /* 257 */
//  char version[2];              /* 263 */
//  char uname[32];               /* 265 */
//  char gname[32];               /* 297 */
//  char devmajor[8];             /* 329 */
//  char devminor[8];             /* 337 */
//  char prefix[155];             /* 345 */
                                /* 500 */
	
  printf("Name: %s\n",tar_header.name);
  printf("Mode: %s\n",tar_header.mode);
  printf("Uid: %s\n",tar_header.uid);
  printf("Gid: %s\n",tar_header.gid);
 

  printf("Size: %d\n",size);
  
  printf("Mtime: %s\n",tar_header.mtime);
  printf("Chksum: %s\n",tar_header.chksum);
  printf("Typeflag: %c\n",tar_header.typeflag);
  if (tar_header.typeflag==REGTYPE) printf("  Regular file\n");
  if (tar_header.typeflag==DIRTYPE) printf("  Folder\n");
  printf("Linkname: %s\n",tar_header.linkname);
  printf("Magic: %s\n",tar_header.magic);
  printf("Version: %s\n",tar_header.version);
  printf("Uname: %s\n",tar_header.uname);
  printf("Gname: %s\n",tar_header.gname);
  printf("Devmajor: %s\n",tar_header.devmajor);
  printf("Devminor: %s\n",tar_header.devminor);
  printf("Prefix: %s\n",tar_header.prefix);
}


void extract_files(FILE *fp)
{
	int nb;
	int i;
	printf("fileno : %d\n",fileno(fp));
	if (feof(fp))
		printf("Fp is eof");
	nb=fread(&tar_header,sizeof(tar_header),1,fp);
	if (feof(fp))
		printf("Fp is eof");	
	printf("fileno : %d\n",fileno(fp));
	printf("Bytes read : %d\n",nb);
	size=tar_header.size[11]+tar_header.size[10]*255;
	if (verbose==1)
	  printf("Extracting %s\n",tar_header.name);
    if (debug==1)
     print_debug();
  
	//nb=fread(&buffer_file_to_extract, size , 1, fp);
	nb=read(fp,&buffer_file_to_extract,size);
	printf("Demande : %d recu : %d\n",size,nb);
	//printf("%d",fp->fd);
   	//for (i=0;i<size;++i)
		//printf("%c",buffer_file_to_extract[i]);

  }

 char manage_option(char *opt)
{
	unsigned char i;
	for (i=0;i<strlen(opt);i++)
	{
		if (opt[i]=='v') verbose=1;
		if (opt[i]=='d') debug=1;
		if (opt[i]=='x') extract=1;
	}
	return 0;
}


int main (int argc,char *argv[])
{
  FILE *fp;
  int i;
  
  int nb;
  char ret;

 	if (argc==2 && strcmp(argv[1],"--version")==0)
	{
		version();
		return (1);
	}
	
	ret=manage_option(argv[1]);
    if (argc!=3 || ret!=0)
    {
        usage();
        return(1);
    }
  
  if (strlen(argv[2])==0)
  {
     usage();
     return(1);	  
  }
  

  
  fp=fopen(argv[2],"r");
  if (fp==NULL)
  {
    printf("Can't open %s\n",argv[2]);
    return(1);
  }	

  
  if (extract==1)
  {
   extract_files(fp);
   

  
  
  }
	
	//nb=read(fp,&buffer_file_to_extract, size);

    fclose(fp);
  
}
