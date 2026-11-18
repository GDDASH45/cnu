/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _CNU_EFI_H
#define _CNU_EFI_H

#include <stdint.h>

#define EFIAPI __attribute__((ms_abi))

typedef void *EFI_HANDLE;
typedef uint64_t EFI_STATUS;
typedef uint16_t CHAR16;

typedef struct {
    uint64_t Signature;
    uint32_t Revision;
    uint32_t HeaderSize;
    uint32_t CRC32;
    uint32_t Reserved;
} EFI_TABLE_HEADER;

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_STATUS (EFIAPI *Reset)(
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
        uint8_t ExtendedVerification
    );
    EFI_STATUS (EFIAPI *OutputString)(
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
        CHAR16 *String
    );
    void *TestString;
    void *QueryMode;
    void *SetMode;
    void *SetAttribute;
    void *ClearScreen;
    void *SetCursorPosition;
    void *EnableCursor;
    void *Mode;
};

typedef struct {
    EFI_TABLE_HEADER Hdr;
    CHAR16 *FirmwareVendor;
    uint32_t FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    void *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    void *StdErr;
    void *RuntimeServices;
    void *BootServices;
    uint64_t NumberOfTableEntries;
    void *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif
