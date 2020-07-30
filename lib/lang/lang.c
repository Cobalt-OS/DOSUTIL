/* Wrapper for kitten library
   Copyright (C) 2004-2018 Free Software Foundation, Inc.
   This file is part of Base64.
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

/* Written by LiquidFox1776 2018*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "..\..\config.h"
#include "..\kitten\kitten.h"
#include "..\error.h"
#include "lang.h"

typedef struct NLS_CALL_STACK{
char *sub_directory[MAX_PATH];
char *file_name[MAX_PATH];
struct NLS_CALL_STACK *next;
};

struct NLS_CALL_STACK *nls_call_stack;

/*Pushes sub_directoy and file_name onto the stack structure*/
int
push_nls_call_stack(char *sub_directory, char *file_name){
        struct NLS_CALL_STACK *tmp_struct;
        nls_call_stack = (struct NLS_CALL_STACK *) malloc(sizeof(struct NLS_CALL_STACK));
     
    tmp_struct = (struct NLS_CALL_STACK*) malloc(sizeof(struct NLS_CALL_STACK));
    
     if(tmp_struct != NULL){
        
        strncpy(tmp_struct->sub_directory, sub_directory, MAX_PATH);
        strncpy(tmp_struct->file_name, file_name, MAX_PATH);
        tmp_struct->next = nls_call_stack;
        nls_call_stack = tmp_struct;
        return 0;
    }
    return -1;
}

/*Pops sub_directory and file_name off of the stack structure*/
void
pop_nls_call_stack(){
   struct node *tmp_struct;
    if (nls_call_stack != NULL){
        
        tmp_struct = nls_call_stack;
        nls_call_stack = nls_call_stack->next;
        free(tmp_struct);
    }
}
void
destroy_nls_call_stack(){
        struct NLS_CALL_STACK *tmp_struct;
        tmp_struct = nls_call_stack;

        while(tmp_struct != NULL){
        pop_nls_call_stack;
        tmp_struct = tmp_struct->next;
        }
}

/*
open_nls_file attempts to open up a kitten language file
based on a root path defined by the environment variable COREUTIL_NLS_PATH
sub_directory and file_name variables
It uses the LANG environment variable as a file extension
*/
int
open_nls_file(const char *sub_directory, const char *file_name){
    char lang[MAX_LANG_CODE_LENGTH];
    char coreutil_nls_path[PATH_MAX];
    size_t len;
    char nls_file_path[PATH_MAX];
    int rc;

    if( getenv_s( &len, coreutil_nls_path, sizeof(coreutil_nls_path), "COREUTIL_NLS_PATH") != 0 )
        return -1;

    if( getenv_s( &len, lang, sizeof(lang), "LANG") == 0 )
        _snprintf(nls_file_path, PATH_MAX, "%s%s%s%s%s%s%s", coreutil_nls_path, "\\", sub_directory, "\\", file_name, ".", lang);
    else
        return -1;

   if(nls_call_stack != NULL) /* if catalog is open than close */
        kittenclose();
   if(kittenopen (nls_file_path) ==-1)
        return -1; //Failed to open

   rc =  push_nls_call_stack(sub_directory, file_name);
    if(rc == -1){ 
        kittenclose();
        return -1;
    }
 
 return rc;
}

/* closes the kitten file and pops the nls call stack
*/
void
close_nls_file(bool from_main_program){
    
    if(from_main_program)
      destroy_nls_call_stack(); 
    else{
        pop_nls_call_stack();
        open_nls_file(nls_call_stack->sub_directory, nls_call_stack->file_name); /* Reopen kitten as if the prev caller did */
    }
}

/* calls kittengets*/
char *get_nls_string(int set_number, int message_number, char *message){

    return kittengets(set_number,message_number, message);
}



