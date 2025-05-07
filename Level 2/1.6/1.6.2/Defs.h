/**
*
* Defs.h
*
* Header file containing macro definitions compute the
* maximum value among variables
* 
* This file defines two macros:
*	- MAX2: Returns the maximum value between two variables
*	- MAX3: Returns the maximum value among three variables
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#ifndef DEFS_H // Prevent multiple inclusions
#define DEFS_H

// Macro to compute the maximum value between two variables
#define MAX2(x,y) ((x) > (y) ? (x) : (y))

// Macro to compute the maximum value among three variables
#define MAX3(x,y,z) ((MAX2(x,y)) > (z) ? (MAX2(x,y)) : (z))

#endif