

#ifndef STATUS_H
#define STATUS_H





#include <stdio.h>

/* status code */
#define TRUE 1 //true
#define FALSE 0 //false
#define OK 1 //pass/success
#define ERROR 0//error/failed


#ifndef OVERFLOW
#define OVERFLOW -2 //stack overflow
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif



/* status */
typedef int Status;

/* Boolean */
typedef int Boolean;


extern Boolean debug;

/* read data form files
 * notes: 1. All string are simple text, such as %d%s%c,but not %2d...
 *
 */
int ReadData(FILE * fp, char * format, ...);
/* press enter to continue
 * if debug=TRUE, code will stop until press enter
 */
void PressEnterToContinue(Boolean debug);


/* let funtions pause some times.
 */
void Wait(long time);



#endif



