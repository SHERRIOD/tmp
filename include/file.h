#include "list.h"

#ifndef FILE_H
#define FILE_H

int         ReadFile(const char* file_path, List* list,
                                            void* list_type_value);
int         WriteFile(const char* file_path, List* list, 
                                            void* list_type_value);

int         LoadFromFile();
int         WriteToFile();

#endif