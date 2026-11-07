/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c) 2026 The Blueberry Pie OS Authors */
#include <security/pam_appl.h>
#include "openpam_impl.h"

int
openpam_configure_apple(pam_handle_t *pamh, const char *service)
{
	(void)pamh;
	(void)service;
	return (PAM_SYSTEM_ERR);
}
