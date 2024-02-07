# About

## Introduction

Just a simple try for studying COM(Component Object Model).

The original article is [here](https://www.codeguru.com/soap/step-by-step-com-tutorial/).

And we could find the original codebase [here](https://github.com/grimripper/grim_com_testing) or another changed version [here](https://github.com/HIT-Alibaba/COM-Example).

I made some adjustments so that we could use cmake to compile this project.

Take it easy to study COM and have fun!

## How-to-Use

First, you can use midl.exe to compile `IAdd.idl` file,

```powershell
midl.exe .\IAdd.idl
```

then, you can run powershell script to compile these source files,

```powershell
.\lcompile.ps1
```

then, we need to register our dll file generated during last step,

```powershell
regsvr32.exe .\build64\Debug\AddObj.dll
```

**note**: here we need run `register32` command in Administrator mode, you can simply use scoop tu install gsudo and run `sudo` to enter Administrator mode.

then, `cd test`, and run `lcompile.ps1`, then, execute the exe file,

```powershell
.\build64\Debug\comtest.exe
```

output:

```powershell
Output after adding 100 & 200 is 300.
```


