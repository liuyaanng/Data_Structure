
#ifndef UNION_H
#define UNION_H

#include <stdio.h>

#include "../../Status/Status.h"
#include "SqList.h"



// Algorithm 2.1
// A = A u B


void Union(SqList * A, SqList B);


/* equal
 * if the two elem is equal, then return true
 */

Status equal(ElemType e1, ElemType e2);

#endif
