#include "stdafx.h"
#include "MNVAdamProtocol.h"

unsigned long WINAPI Thread_AdamSync(void * __pParm)
{
	CMNV_Adam6050 * pAdam = (CMNV_Adam6050 *)__pParm;
	pAdam->AdamThread();

	return 0;
}
