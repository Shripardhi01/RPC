/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "fact.h"

bool_t
xdr_val (XDR *xdrs, val *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	return TRUE;
}
