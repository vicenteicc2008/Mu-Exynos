## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = j2corelte
  PLATFORM_GUID                  = 1df3decf-e6be-460b-923a-c5d8446787db
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/j2coreltePkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = j2coreltePkg/j2corelte.fdf
  BROKEN_CNTFRQ_EL0              = 1
  HAS_SPECIAL_BUTTON             = 0

[BuildOptions.common]
  *_CLANG38_AARCH64_CC_FLAGS = -DBROKEN_CNTFRQ_EL0=$(BROKEN_CNTFRQ_EL0) -DHAS_SPECIAL_BUTTON=$(HAS_SPECIAL_BUTTON)

[LibraryClasses.common]
  PlatformMemoryMapLib|j2coreltePkg/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf

[PcdsFixedAtBuild.common]
  # Platform-specific
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x40000000         # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x40000000         # 1GB Size

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"vice2008"   # Device Maintainer

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x40C40000

  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x40C00000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000      # 256K stack

  # SmBios
  gSamsungPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Samsung Electronics Co., Ltd."
  gSamsungPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Galaxy J2 Core"
  gSamsungPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"J260M"
  gSamsungPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Galaxy_J2_Core_J260M"
  gSamsungPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Galaxy J2 Core"

  # Buttons
  gSamsungPkgTokenSpaceGuid.PcdButtonsPinctrlBase|0x139F0000
  gSamsungPkgTokenSpaceGuid.PcdVolumeDownButtonBankOffset|0x80
  gSamsungPkgTokenSpaceGuid.PcdVolumeDownButtonGpaPin|0x3
  gSamsungPkgTokenSpaceGuid.PcdVolumeUpButtonBankOffset|0x40
  gSamsungPkgTokenSpaceGuid.PcdVolumeUpButtonGpaPin|0x7
  gSamsungPkgTokenSpaceGuid.PcdPowerButtonBankOffset|0x40
  gSamsungPkgTokenSpaceGuid.PcdPowerButtonGpaPin|0x4      # TODO: Write pmic power keys driver
  # Simple FrameBuffer
  gSamsungPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|540
  gSamsungPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|960
  gSamsungPkgTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|32

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|540
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|960
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|540
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|960
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|90
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|80
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|90
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|80

!include E7570Pkg/E7570Pkg.dsc.inc
