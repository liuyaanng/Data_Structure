#include <stdio.h>
#include "Status.h"



Boolean debug = FALSE;
/* Boolean debug = TRUE; */

/* Press enter to continue if debug is true */
void PressEnterToContinue(Boolean debug){
	fflush(stdin);

	if (debug){
		printf("\nPress Enter To Continue...");
		getchar();
	}
	else{
		printf("\n");
	}
	fflush(stdin);
}



/* Let Functions pause some times */

void Wait(long time){
	double i;

	if(time < 0){
		time = -time;
	}


	for(i = 0.01; i <= 100000.0 * time; i += 0.01){
		/* empty loop */
	}
}

