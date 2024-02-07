cmake_minimum_required(VERSION 3.25.0)

project(AddObj)

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
