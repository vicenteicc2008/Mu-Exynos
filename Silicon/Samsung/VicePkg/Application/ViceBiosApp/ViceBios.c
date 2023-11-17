#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Protocol/HiiImage.h>

EFI_STATUS
EFIAPI
UefiMain(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
)
{
  EFI_STATUS Status;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;

  // Inicializar la instancia de ConOut para la salida de texto
  Status = gST->ConOut->ClearScreen(gST->ConOut);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  // Imprimir un mensaje en la pantalla
  Status = gST->ConOut->OutputString(gST->ConOut, L"Hello, I am Vice from BIOS!\n");
  if (EFI_ERROR(Status)) {
    return Status;
  }

  DEBUG((EFI_D_INFO, "¡Hello, world! starting ViceBios.\n"));

  Status = gBS->AllocatePool (
                EfiBootServicesData,
				10,
				(VOID **)&Buffer
                );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  gBS->FreePool(Buffer);

  return EFI_SUCCESS;
}
