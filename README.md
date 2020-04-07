# DXWrapperBMS
This project is a D3D9 Wrapper developed by BibleClinger that is compatible with Falcon BMS 4.34 U3 servers. It stops rendering when the server goes into 3D, and enables rendering when the server comes back to 2D.

# Purpose

BMS, as of 4.34 U3, does not have a dedicated server. The client must function as a server. Additionally, the server instance *must* enter the 3D world when hosting Campaigns and Tactical Engagements, even if it is to be used as a dedicated server. This unncessary rendering puts a strain on the Falcon BMS server.

This DLL is meant as a lightweight interim solution to mitigate server stress until a proper dedicated server is created.

# Installation

- For 64-bit servers, place x64\d3d9.dll inside `Falcon BMS 4.34\bin\x64`.
- For 32-bit servers, place x86\d3d9.dll inside `Falcon BMS 4.34\bin\x86\`, and please consider running BMS in 64-bit. :)

# Usage (for Falcon BMS server administrators)

Everything about Falcon BMS server operations apply, except for two things:

- When it comes time to exit the server from 3D, this may be difficult as you will be blind. Nevertheless, `ESC -> E` still works.
- If you need to enable/disable drawing, focus the console window (the black DOS-like window) that should be attached to the BMS process, and press either `CTRL + BREAK` or `CTRL + C`.

# Prior Testing

UOAF has tested this project throughout early development during regular weekly MP events. No crashes. \o/

# Extra Reading

* The Windows API for Direct3D 9: https://docs.microsoft.com/en-us/windows/win32/api/_direct3d9/. This resource is necessary for any D3D9 project.
* Matt's Webcorner's D3D9Interceptor: http://graphics.stanford.edu/~mdfisher/D3D9Interceptor.html. Matt's work was very helpful in understanding how to intercept D3D9 calls.

# Disclaimer

This project is not affilliated with Benchmark Sims. It is a 3rd party DLL designed to support Falcon BMS server administrators.
