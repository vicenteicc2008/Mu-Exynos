#ifndef CLOCK_PROTOCOL_H
#define CLOCK_PROTOCOL_H

// Protocol GUID definition
#define EFI_CLOCK_PROTOCOL_GUID \
  { \
    0x241afae6, 0x885f, 0x4f6c, { 0xa7, 0xea, 0xc2, 0x8e, 0xab, 0x79, 0xc3, 0xe5 } \
  }

// Forward declaration
typedef struct _EFI_CLOCK_PROTOCOL EFI_CLOCK_PROTOCOL;

// Protocol API definitions
typedef
EFI_STATUS
(EFIAPI *EFI_ENABLE_CLOCK)(
  IN EFI_CLOCK_PROTOCOL  *This,
  IN UINT32              ClockId
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_CLOCK_FREQ)(
  IN EFI_CLOCK_PROTOCOL  *This,
  IN UINT32              ClockId,
  IN UINT32              Freq,
  OUT UINT32             *ActualFreq OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_CLOCK_FREQ)(
  IN EFI_CLOCK_PROTOCOL  *This,
  IN UINT32              ClockId,
  OUT UINT32             *Freq
);

// Clock Protocol Structure
struct _EFI_CLOCK_PROTOCOL {
  EFI_ENABLE_CLOCK      EnableClock;
  EFI_SET_CLOCK_FREQ    SetClockFreq;
  EFI_GET_CLOCK_FREQ    GetClockFreq;
};

// Protocol GUID definition
extern EFI_GUID gEfiClockProtocolGuid;

#endif // CLOCK_PROTOCOL_H
