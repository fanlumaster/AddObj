//
/// Client.cpp
//
// Demo of client using the COM object from AddObj.dll
//
#include <objbase.h>
#include <stdio.h>
#include <conio.h>
#include <winnt.h>
#include "IAdd.h"
/* #import "IAdd.tlb" raw_interfaces_only */
//
// Here we do a #import on the DLL ,you can also do a #import on the .TLB
// The #import directive generates two files in the output folders.
//

int main()
{
    long n1 = 100, n2 = 200;
    long nOutPut = 0;

    CoInitialize(NULL);
    CodeGuruMathLib::IAddPtr pFastAddAlgorithm;
    //
    // IAddPtr is not the actual interface IAdd, but a template C++ class (_com_ptr_t)
    // that contains an embedded instance of the raw IAdd pointer
    // While destructing , the destructor makes sure to invoke Release() on the internal
    // raw interface pointer. Further, the operator -> has been overloaded to direct all
    // method invocations to the internal raw interface pointer.
    //
    pFastAddAlgorithm.CreateInstance("CodeGuru.FastAddition");

    /* printf("\nEnter the first number:"); */
    /* scanf("%d", &n1); */

    /* printf("\nEnter the second number:"); */
    /* scanf("%d", &n2); */

    pFastAddAlgorithm->SetFirstNumber(n1); //"->" overloading in action
    pFastAddAlgorithm->SetSecondNumber(n2);
    HRESULT res = pFastAddAlgorithm->DoTheAddition(&nOutPut);

    printf("Output after adding %ld & %ld is %ld.\n", n1, n2, nOutPut);
}
