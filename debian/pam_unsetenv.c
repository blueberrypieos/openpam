/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c) 2026 The Blueberry Pie OS Authors */

#include <stdlib.h>
#include <string.h>

#include <security/pam_appl.h>

#include "openpam_impl.h"

static void
wipe_string(char *str)
{
	volatile char *p = str;
	size_t remaining = strlen(str);

	while (remaining-- > 0)
		*p++ = '\0';
}

int
pam_unsetenv(pam_handle_t *pamh, const char *name)
{
	char *removed;
	int index;

	index = openpam_findenv(pamh, name, strlen(name));
	if (index < 0)
		return (PAM_SYSTEM_ERR);

	removed = pamh->env[index];
	pamh->env_count--;
	pamh->env[index] = pamh->env[pamh->env_count];
	pamh->env[pamh->env_count] = NULL;

	wipe_string(removed);
	free(removed);

	return (PAM_SUCCESS);
}
