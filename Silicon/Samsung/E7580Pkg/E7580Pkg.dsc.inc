## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

# SoC Defines
[Defines]
  USE_PHYSICAL_TIMER             = 1
  CUSTOM_KEYPAD_IMPL             = 1

[BuildOptions.common]
  *_*_*_CC_FLAGS = -march=armv8.2-a+crypto+rcpc

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|26000000
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|13
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|14
  gArmTokenSpaceGuid.PcdArmArchTimerVirtIntrNum|11
  gArmTokenSpaceGuid.PcdArmArchTimerHypIntrNum|10
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x10C01000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x10C02000 
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0x10C01000

  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x00007580
  gEmbeddedTokenSpaceGuid.PcdInterruptBaseAddress|0x10C01000

  gSamsungPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Exynos (TM) 7580 @ 1.60 GHz"
  gSamsungPkgTokenSpaceGuid.PcdSmbiosProcessorRetailModel|"E7580"

  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gArmPlatformTokenSpaceGuid.PcdClusterCount|2

[LibraryClasses.common]
  PlatformPeiLib|E7580Pkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  PlatformPrePiLib|E7580Pkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf
  HwResetSystemLib|E7580Pkg/Library/ResetSystemLib/ResetSystemLib.inf
  ResetSystemLib|E7580Pkg/Library/ResetSystemLib/ResetSystemLib.inf
  KeypadDeviceImplLib|E7580Pkg/Library/KeypadDeviceImplLib/KeypadDeviceImplLib.inf

[Components.common]
  E7580Pkg/Drivers/SmBiosTableDxe/SmBiosTableDxe.inf

!include SamsungPkg/SamsungPkg.dsc.inc
