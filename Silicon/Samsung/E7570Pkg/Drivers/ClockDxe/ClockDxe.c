/** @file ClockDxe.c

  This file implements clock EFI protocol interface.

  Copyright (c) 2010-2024 Samsung Electronics, Inc. All rights reserved.

**/
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include "Clock.h"

EFI_STATUS
EFIAPI
ClockDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS              Status;
  EFI_CLOCK_PROTOCOL      *Clock;

  // Locate the clock protocol instance
  Status = gBS->LocateProtocol (&gEfiClockProtocolGuid, NULL, (VOID **) &Clock);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  // Enable the clock with ID 0
  Status = Clock->EnableClock (Clock, 0);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  // Set the clock frequency to 100 MHz
  Status = Clock->SetClockFreq (Clock, 0, 26000000, NULL);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  // Get the current clock frequency
  UINT32 Freq;
  Status = Clock->GetClockFreq (Clock, 0, &Freq);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  // Print the current clock frequency
  DEBUG((EFI_D_WARN, "Current clock frequency is %u Hz\n", Freq));

  return EFI_SUCCESS;
}
