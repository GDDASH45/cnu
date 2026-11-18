/* SPDX-License-Identifier: GPL-2.0-only */

#include <cnu/efi.h>

static CHAR16 banner[] = {
    'C', 'N', 'U', ' ', 'k', 'e', 'r', 'n', 'e', 'l',
    ' ', '-', ' ', 'x', '8', '6', '_', '6', '4', ' ',
    'U', 'E', 'F', 'I', 13, 10, 0
};

EFI_STATUS EFIAPI efi_main(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable
)
{
    (void)ImageHandle;

    if (SystemTable == 0 || SystemTable->ConOut == 0)
        return 1;

    SystemTable->ConOut->OutputString(SystemTable->ConOut, banner);

    return 0;
}
