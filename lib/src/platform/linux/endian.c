/*
 * SPDX-License-Identifier: MIT
 *
 * The MIT License (MIT)
 *
 * Copyright (c) <2016> <Stephan Gatzka>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _DEFAULT_SOURCE
#include <endian.h>
#include <stdint.h>

#include "cio/endian.h"

uint16_t cio_be16toh(uint16_t big_endian_16bits)
{
	return be16toh(big_endian_16bits); // NOLINT
}

uint32_t cio_be32toh(uint32_t big_endian_32bits)
{
	return be32toh(big_endian_32bits); // NOLINT
}

uint64_t cio_be64toh(uint64_t big_endian_64bits)
{
	return be64toh(big_endian_64bits); // NOLINT
}

uint16_t cio_htobe16(uint16_t host_endian_16bits)
{
	return htobe16(host_endian_16bits); // NOLINT
}

uint32_t cio_htobe32(uint32_t host_endian_32bits)
{
	return htobe32(host_endian_32bits); // NOLINT
}

uint64_t cio_htobe64(uint64_t host_endian_64bits)
{
	return htobe64(host_endian_64bits); // NOLINT
}

uint16_t cio_le16toh(uint16_t little_endian_16bits)
{
	return le16toh(little_endian_16bits);
}

uint32_t cio_le32toh(uint32_t little_endian_32bits)
{
	return le32toh(little_endian_32bits);
}

uint64_t cio_le64toh(uint64_t little_endian_64bits)
{
	return le64toh(little_endian_64bits);
}

uint16_t cio_htole16(uint16_t host_endian_16bits)
{
	return htole16(host_endian_16bits);
}

uint32_t cio_htole32(uint32_t host_endian_32bits)
{
	return htole32(host_endian_32bits);
}

uint64_t cio_htole64(uint64_t host_endian_64bits)
{
	return htole64(host_endian_64bits);
}
