cmake_minimum_required(VERSION 3.25.0)

project(AddObj)

# http://www.utf8everywhere.org/
add_definitions(
    /D_UNICODE=1
    /DUNICODE=1
)

add_library(AddObj SHARED
    "AddObj.cpp"
    "AddObj.h"
    "AddObjFactory.cpp"
    "AddObjFactory.h"
    "AddObjGuid.h"
    "Exports.cpp"
    "Exports.def"
    "IAdd_i.c"
    "IAdd.h"
    "Registry.cpp"
    "REGISTRY.H"
)
