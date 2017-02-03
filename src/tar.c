#include <stdio.h>
#include "tar.h"


struct posix_header tar_header;


void verbose()
{
  printf("Name: %s\n",tar_header.name);
  printf("Mode: %s\n",tar_header.mode);
  printf("Uid: %s\n",tar_header.uid);
  printf("Gid: %s\n",tar_header.gid);
  printf("Size: %s\n",tar_header.size);
  printf("Mtime: %s\n",tar_header.mtime);
  printf("Chksum: %s\n",tar_header.chksum);
  printf("Typeflag: %c\n",tar_header.typeflag);
  printf("Linkname: %s\n",tar_header.linkname);
  printf("Magic: %s\n",tar_header.magic);
  printf("Version: %s\n",tar_header.version);

}


int main (int argc,char *argv[])
{
  FILE *fp;
  unsigned short int i;
  int nb;

  if (argc!=2)
    return (1);
  fp=fopen(argv[1],"r");
  if (fp==NULL)
  {
    printf("Can't open %s\n",argv[1]);
    return(1);
  }	
  printf("Open\n");

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


   fread(&tar_header.name,100,1,fp);
   fread(&tar_header.mode,8,1,fp);
   fread(&tar_header.uid,8,1,fp);
   fread(&tar_header.gid,8,1,fp);
   fread(&tar_header.size,12,1,fp);
   fread(&tar_header.mtime,12,1,fp);
   fread(&tar_header.chksum,8,1,fp);
   fread(&tar_header.typeflag,1,1,fp);
   fread(&tar_header.linkname,100,1,fp);
   fread(&tar_header.magic,6,1,fp);
   fread(&tar_header.version,2,1,fp);
   fread(&tar_header.uname,32,1,fp);
   fread(&tar_header.gname,32,1,fp);
   fread(&tar_header.devmajor,8,1,fp);
   fread(&tar_header.devminor,8,1,fp);
   fread(&tar_header.prefix,155,1,fp);

   verbose();
}
