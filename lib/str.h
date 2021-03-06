
/**
 @file str.h

 @brief String matching functions

 @par Copyright &copy; 2015 Mike Gore, GPL License
 @par You are free to use this code under the terms of GPL
  Please retain a copy of this notice in any code you use it in.

  This is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option)
  any later version.
  
  This software is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _STR_H_
#define _STR_H_

#ifdef ESP8266
    #include "user_config.h"
#endif

#ifndef MEMSPACE
#define MEMSPACE /**/
#endif

#include <stdint.h>
#include <math.h>

// The odd notation for SWAP avoids certian compiler optimizations
#define SWAP(a, b) do { a ^= b; b ^= a; a ^= b; } while(0)
#define ABS(x) ((x)<0 ? -(x) : (x))
#define SIGN(x) (((x) == 0) ? 0 : ((x) > 0) ? 1 : -1)
#define MAX(x,y) (((x) > (y)) ? x : y)

#define SPACES " \t\r"
#define SPACESNL " \t\n\r"

/* str.c */
MEMSPACE uint8_t hexd ( char c );
MEMSPACE long atoh ( const char *p );

// skip if we have linux isdigit
#ifndef _CTYPE_H
MEMSPACE int isdigit ( int c );
MEMSPACE int isupper ( int c );
MEMSPACE int islower ( int c );
MEMSPACE int tolower ( int c );
MEMSPACE int toupper ( int c );
#endif

// Skip if we have linux string.h
#ifndef _STRING_H
MEMSPACE size_t strlen ( const char *str );
MEMSPACE int strcmp ( const char *str , const char *pat );
MEMSPACE int strncmp ( const char *str , const char *pat , size_t len );
#endif

// Skip if we have linux strings.h
#ifndef _STRINGS_H
MEMSPACE int strcasecmp ( const char *str , const char *pat );
MEMSPACE int strncasecmp ( const char *str , const char *pat , size_t len );
#endif

MEMSPACE int MATCH ( char *str , char *pat );
MEMSPACE int MATCHI ( char *str , char *pat );
MEMSPACE int MATCH_LEN ( char *str , char *pat );
MEMSPACE int MATCHI_LEN ( char *str , char *pat );
MEMSPACE void reverse ( char *str );
MEMSPACE void strupper ( char *str );
MEMSPACE char *strnalloc ( char *str , int len );
MEMSPACE char *stralloc ( char *str );
MEMSPACE char *skipspaces ( char *ptr );
MEMSPACE char *nextspace ( char *ptr );
MEMSPACE char *skipchars ( char *str , char *pat );
MEMSPACE void trim_tail ( char *str );
MEMSPACE char *get_token ( char *str , char *token , int max );
MEMSPACE int token ( char *str , char *pat );

#endif
