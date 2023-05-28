#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include<stdio.h>

/*int compare(const void* a, const void* b);
void createDir(const char* dir_path);
void renameAndMoveFile(char* newPath, char* oldPath, char* filename, const char* extention);
void createFileWithNewExtention(char* newPath, char* oldPath, const char* fileName, const char* extention);*/

void changeExtention(char* fileName, char* newFileName, char* extention);
void changeExtentionAndPath(char* fileName,char* newPathFile, char* extention, char* path);

void createDirs();
void scanDir(); 



#endif

