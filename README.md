# LSM100A_SDK




## Introduction

This document is a guide for the SDK provided to help develop devices based on the LSM100A LoRa/Sigfox module of Seongji.

The LSM100A is a state-of-art module integrating STMicroelectronics’ STM32WL. 
It is very less current consumption for IoT device to extend battery life. 
And, it also supports both of technologies – Sigfox and LoRa – with LSM100A module itself. 

You can switch Sigfox or LoRa with it so that you can also reduce cost. 
It is highly optimized for IoT solution (Low-Power Consumption, Low-Cost)

For other information, please refer to the document in Document.


<br/>

## Architecture of the SDK

> Document <br/>
- HW Datasheet
- User Manual
- FW Download Guide
- SDK Quick Start Guide
- LoRa CLI Manual
- LoRa API Manual
- Sigfox CLI Manual
- Sigfox API Manual

> Drivers <br/>

> Middlewares <br/>

> Projects
>> NUCLEO-WL55CC
>>> Applications
>>>> LoRaWAN_Sigfox
>>>>> LSM100A 
>>>>> - Core
>>>>> - LoRaWAN
>>>>> - Sigfox

>>>> LoRaWAN
>>>>> LoRaWAN_End_Node

>>>> SubGHz_Phy
>>>>> SubGHz_Phy_Per <br/>
>>>>> SubGHz_Phy_PingPong

> Utilities
>> PC_Software
>>>  + AT Command GUI for LoRa
>>>  + AT Command GUI for Sigfox


<br/>


## SDK Build

- ST Software Development Tools
  + STM32CubeIDE <br/>
    * Download link: https://www.st.com/en/development-tools/stm32cubeide.html

	* Document link: https://www.st.com/en/development-tools/stm32cubeide.html#documentation

<br/>

###	Build using the STM32CubeIDE <br/>

  1. Execute the .project file in Projects\NUCLEO-WL55CC\Applications\LoRaWAN_Sigfox\LSM100A\STM32CubeIDE folder. <br/>

  2. After STM32CubeIDE is executed, LSM100A_SDK_LoRaWAN_Sigfox project is created in the left Project Explorer tab. <br/>
    The program name is subject to change. <br/>

  3. Run Build All from the Project menu.
    After the build is completed, a hex file is created in the Release folder. <br/>

  * Refer to [**[SEONGJI]_LSM100A_SDK_Quick_start_guide.pdf**](https://github.com/SeongJiIoT/LSM100A_SDK/blob/main/Document/%5BSEONGJI%5D_LSM100A_SDK_Quick_start_guide.pdf) in Document folder

<br/>
	
## FW Download

- ST Software Development Tools
  + STM32CubeProgrammer <br/>
    * Download link: https://www.st.com/en/development-tools/stm32cubeprog.html
	
	* Document link: https://www.st.com/en/development-tools/stm32cubeprog.html#documentation
	
Refer [**[SEONGJI]_LSM100A_FW_Download_Guide.pdf**](https://github.com/SeongJiIoT/LSM100A_SDK/blob/main/Document/%5BSEONGJI%5D_LSM100A_FW_Download_Guide.pdf) in Document folder


<br/>

## USB Driver
- Download and Install VCP Drivers on SILICON LABS web site
  + Downloads for Windows, Macintosh, Linux and Android below.
	* Download link: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers



