/*
 Program Name: ls.c
 Author: Ankur Patel
 Program Intent: Prints files in the current directory
 */

#include <dirent.h>
#include <stdio.h>

int main() 
{
  unsigned char isFolder =0x4;
  DIR *dir;
  struct dirent *dirEntry;
  dir = opendir(".");
    
  while (dirEntry = readdir(dir)) {
    if (dirEntry->d_type == isFolder) {
      printf("%s\n", dirEntry->d_name);
    } else {
      printf("%s\n", dirEntry->d_name);
    }
  }

  closedir(dir);

  return 0;
}
