# DXWrapperBMS
D3D9 Wrapper that is compatible with Falcon BMS 4.34 U3 servers. It stops rendering when the server goes into 3D, and enables rendering when the server comes back to 2D.

# Purpose

BMS, as of 4.34 U3, does not have a dedicated server. The client must function as a server. Additionally, the server instance *must* enter the 3D world when hosting Campaigns and Tactical Engagements, even if it is to be used as a dedicated server. This unncessary rendering puts a strain on the Falcon BMS server. This DLL is meant as a lightweight interim solution to mitigate server stress.

# Installation

For 64-bit servers, place d3d9.dll inside your Falcon BMS 4.34\bin\x64 directory.
For 32-bit servers, please consider running BMS in 64-bit. :)
