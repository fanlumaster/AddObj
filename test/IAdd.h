// Created by Microsoft (R) C/C++ Compiler Version 14.38.33133.0 (d63b799a).
//
// C:\EDisk\CppCodes\ComCodes\AddObj\test\build64\comtest.dir\Debug\IAdd.tlh
//
// C++ source equivalent of type library IAdd.tlb
// compiler-generated file - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace CodeGuruMathLib {

//
// Forward references and typedefs
//

struct __declspec(uuid("3ff1aab8-f3d8-11d4-825d-00104b3646c0"))
/* LIBID */ __CodeGuruMathLib;
struct __declspec(uuid("1221db62-f3d8-11d4-825d-00104b3646c0"))
/* interface */ IAdd;
struct __declspec(uuid("6bee2d26-f3d8-11d4-825d-00104b3646c0"))
/* interface */ IFileIO;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(IAdd, __uuidof(IAdd));
_COM_SMARTPTR_TYPEDEF(IFileIO, __uuidof(IFileIO));

//
// Type library items
//

struct __declspec(uuid("1221db62-f3d8-11d4-825d-00104b3646c0"))
IAdd : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall SetFirstNumber (
        long nX1 ) = 0;
      virtual HRESULT __stdcall SetSecondNumber (
        long nX2 ) = 0;
      virtual HRESULT __stdcall DoTheAddition (
        /*[out,retval]*/ long * pBuffer ) = 0;
};

struct __declspec(uuid("6bee2d26-f3d8-11d4-825d-00104b3646c0"))
IFileIO : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall EnableLog (
        long nEnable ) = 0;
      virtual HRESULT __stdcall IsEnabled (
        long * pEnabled ) = 0;
};

} // namespace CodeGuruMathLib

#pragma pack(pop)
