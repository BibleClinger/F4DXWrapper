# F4DXWrapper

This project is a D3D Wrapper developed by BibleClinger that is compatible with Falcon BMS 4.34 U3, 4.34 U4, as well as 4.35, 4.36, and 4.37 servers. It stops rendering when the server goes into 3D, and enables rendering when the server comes back to 2D.

# Purpose

BMS, at least up to 4.35, does not have a dedicated server. The client must function as a server. Additionally, the server instance *must* enter the 3D world when hosting Campaigns and Tactical Engagements, even if it is to be used as a dedicated server. This unnecessary rendering puts a strain on the Falcon BMS server.

This DLL is meant as a lightweight interim solution to mitigate server stress until a proper dedicated server is created.

**Note:** *Falcon BMS 4.35 has made the transition from DirectX9 to DirectX11. It has also made a vast improvement in attempting to separate the logic from the rendering. To quote one of the devs, as of the initial release of 4.35, "[...] BMS 4.35 is now ALWAYS CPU bound" with the exception of servers that have a "very weak GPU[.]" In short, if your server has no GPU or a weak GPU, you should expect to see some gains in performance by using this DLL. Otherwise, this DLL may provide negligible aid in 4.35 for those servers that have a decent GPU. The 4.34 DLL, however, should still provide a significant boost in performance for those that still wish to run that older version.*

# Installation

- For Falcon BMS 4.34, place `d3d9.dll` inside `Falcon BMS 4.34\bin\x64`.
- For Falcon BMS 4.35, place `d3d11.dll` inside `Falcon BMS 4.35\bin\x64`.
- For Falcon BMS 4.36, place `d3d11.dll` inside `Falcon BMS 4.36\bin\x64`.

Please do not mix these files up!

# Usage (for Falcon BMS server administrators)

Everything about Falcon BMS server operations apply, with some exceptions:

1. If the correct DLL has been installed and loaded successfully, you should see a console window (a black DOS-like window) when the server is launched. The title bar of the console window will have the name of the DLL project and the version.
1. It may appear that the server has frozen before it enters 3D. This likely means that the drawing has stopped successfully prior to drawing the 3D view. If your server is configured for audio, hearing the sound from the jet is a good sign all is working well.
1. When it comes time to exit the server from 3D, this may be difficult as you will be blind. Nevertheless:
   1. Ensure that focus is on the BMS window (and NOT the console window).
   1. Press `ESC -> E` to exit. You may need to pause briefly between the `ESC` and the `E`.
1. If you need to enable/disable drawing:
   1. Place the focus on the aforementioned console window (and NOT the BMS window).
   1. Press either `CTRL + BREAK` or `CTRL + C`.

# Documentation

Please see the project wiki at github for more extensive documentation: https://github.com/BibleClinger/F4DXWrapper/wiki

# Prior Testing

- The d3d9.dll was specifically tested extensively at UOAF during weekly events.
- Special thanks to I-Hawk from the Falcon BMS dev team for testing different versions of the d3d11.dll implementation.

# Extra Reading

D3D9:
* The Windows API for Direct3D 9: https://docs.microsoft.com/en-us/windows/win32/api/_direct3d9/. This resource is necessary for any D3D9 project.
* Matt's Webcorner's D3D9Interceptor: http://graphics.stanford.edu/~mdfisher/D3D9Interceptor.html. Matt's work was very helpful in understanding how to intercept D3D9 calls.

D3D11:
* The Windows API for Direct3D 11: https://docs.microsoft.com/en-us/windows/win32/api/_direct3d11/

# Disclaimer

This project is not affilliated with Benchmark Sims. It is a 3rd party DLL designed to support Falcon BMS server administrators.
