//
// Registry.cpp
//
// Implementation for DllRegisterServer,DllUnregisterServer
// Contains code to write COM server data into the registry and
// also removing the data that had been written into the registry
// by this module.
//

#include <objbase.h>
#include <windows.h>

#include "AddObjGuid.h"
#define AddObjProgId L"CodeGuru.FastAddition"
extern HMODULE g_hModule;

BOOL HelperWriteKey(HKEY roothk, const WCHAR *lpSubKey, LPCTSTR val_name,
                    DWORD dwType, void *lpvData, DWORD dwDataSize) {
  //
  // Helper function for doing the registry write operations
  //
  // roothk:either of HKCR, HKLM, etc

  // lpSubKey: the key relative to 'roothk'

  // val_name:the key value name where the data will be written

  // dwType:the type of data that will be written ,REG_SZ,REG_BINARY, etc.

  // lpvData:a pointer to the data buffer

  // dwDataSize:the size of the data pointed to by lpvData
  //
  //

  HKEY hk;
  if (ERROR_SUCCESS != RegCreateKey(roothk, lpSubKey, &hk))
    return FALSE;

  if (ERROR_SUCCESS !=
      RegSetValueEx(hk, val_name, 0, dwType, (CONST BYTE *)lpvData, dwDataSize))
    return FALSE;

  if (ERROR_SUCCESS != RegCloseKey(hk))
    return FALSE;
  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DllRegisterServer(void) {
  //
  // As per COM guidelines, every self installable COM inprocess component
  // should export the function DllRegisterServer for printing the
  // specified information to the registry
  //
  //

  WCHAR *lpwszClsid;
  WCHAR szBuff[MAX_PATH] = L"";
  WCHAR szClsid[MAX_PATH] = L"", szInproc[MAX_PATH] = L"", szProgId[MAX_PATH];
  WCHAR szDescriptionVal[256] = L"";

  StringFromCLSID(CLSID_AddObject, &lpwszClsid);

  wsprintf(szClsid, L"%S", lpwszClsid);
  wsprintf(szInproc, L"%s\\%s\\%s", "clsid", szClsid, L"InprocServer32");
  wsprintf(szProgId, L"%s\\%s\\%s", "clsid", szClsid, L"ProgId");

  //
  // write the default value
  //
  wsprintf(szBuff, L"%s", L"Fast Addition Algorithm");
  wsprintf(szDescriptionVal, L"%s\\%s", L"clsid", szClsid);

  HelperWriteKey(HKEY_CLASSES_ROOT, szDescriptionVal,
                 NULL, // write to the "default" value
                 REG_SZ, (void *)szBuff, lstrlen(szBuff));

  //
  // write the "InprocServer32" key data
  //
  GetModuleFileName(g_hModule, szBuff, sizeof(szBuff));
  HelperWriteKey(HKEY_CLASSES_ROOT, szInproc,
                 NULL, // write to the "default" value
                 REG_SZ, (void *)szBuff, lstrlen(szBuff));

  //
  // write the "ProgId" key data under HKCR\clsid\{---}\ProgId
  //
  lstrcpy(szBuff, AddObjProgId);
  HelperWriteKey(HKEY_CLASSES_ROOT, szProgId, NULL, REG_SZ, (void *)szBuff,
                 lstrlen(szBuff));

  //
  // write the "ProgId" data under HKCR\CodeGuru.FastAddition
  //
  wsprintf(szBuff, L"%s", L"Fast Addition Algorithm");
  HelperWriteKey(HKEY_CLASSES_ROOT, AddObjProgId, NULL, REG_SZ, (void *)szBuff,
                 lstrlen(szBuff));

  wsprintf(szProgId, L"%s\\%s", AddObjProgId, L"CLSID");
  HelperWriteKey(HKEY_CLASSES_ROOT, szProgId, NULL, REG_SZ, (void *)szClsid,
                 lstrlen(szClsid));

  return 1;
}

///////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DllUnregisterServer(void) {
  //
  // As per COM guidelines, every self removable COM inprocess component
  // should export the function DllUnregisterServer for erasing all the
  // information that was printed into the registry
  //
  //

  WCHAR szKeyName[256] = L"", szClsid[256] = L"";
  WCHAR *lpwszClsid;

  //
  // delete the ProgId entry
  //
  wsprintf(szKeyName, L"%s\\%s", AddObjProgId, L"CLSID");
  RegDeleteKey(HKEY_CLASSES_ROOT, szKeyName);
  RegDeleteKey(HKEY_CLASSES_ROOT, AddObjProgId);

  //
  // delete the CLSID entry for this COM object
  //
  StringFromCLSID(CLSID_AddObject, &lpwszClsid);
  wsprintf(szClsid, L"%S", lpwszClsid);
  wsprintf(szKeyName, L"%s\\%s\\%s", L"CLSID", szClsid, L"InprocServer32");
  RegDeleteKey(HKEY_CLASSES_ROOT, szKeyName);

  wsprintf(szKeyName, L"%s\\%s\\%s", L"CLSID", szClsid, L"ProgId");
  RegDeleteKey(HKEY_CLASSES_ROOT, szKeyName);

  wsprintf(szKeyName, L"%s\\%s", L"CLSID", szClsid);
  RegDeleteKey(HKEY_CLASSES_ROOT, szKeyName);

  return 1;
}
