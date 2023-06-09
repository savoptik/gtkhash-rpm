/*
 *   Copyright (C) 2007-2016 Tristan Heaven <tristan@tristanheaven.net>
 *
 *   This file is part of GtkHash.
 *
 *   GtkHash is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   GtkHash is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with GtkHash. If not, see <https://gnu.org/licenses/gpl-2.0.txt>.
 */

#ifndef GTKHASH_HASH_HASH_LIB_H
#define GTKHASH_HASH_HASH_LIB_H

#ifndef IN_HASH_LIB
	#error "don't use directly"
#endif

#include <stdlib.h>
#include <stdint.h>
#include <glib.h>

#if GLIB_CHECK_VERSION(2,68,0)
	#undef g_memdup
	#define g_memdup g_memdup2
#endif

#include "hash-func.h"

bool gtkhash_hash_lib_is_supported(enum hash_func_e id);
void gtkhash_hash_lib_start(struct hash_func_s *func, const uint8_t *hmac_key,
	size_t key_size);
void gtkhash_hash_lib_update(struct hash_func_s *func, const uint8_t *buffer,
	size_t size);
void gtkhash_hash_lib_stop(struct hash_func_s *func);
void gtkhash_hash_lib_finish(struct hash_func_s *func);

#define HASH_LIB_DECL(LIB) \
	bool gtkhash_hash_lib_ ## LIB ## _is_supported(enum hash_func_e id); \
	void gtkhash_hash_lib_ ## LIB ## _start(struct hash_func_s *func); \
	void gtkhash_hash_lib_ ## LIB ## _update(struct hash_func_s *func, \
		const uint8_t *buffer, size_t size); \
	void gtkhash_hash_lib_ ## LIB ## _stop(struct hash_func_s *func); \
	uint8_t *gtkhash_hash_lib_ ## LIB ## _finish(struct hash_func_s *func, \
		size_t *size);

#endif
