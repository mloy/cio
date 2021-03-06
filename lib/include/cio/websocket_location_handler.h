/*
 * SPDX-License-Identifier: MIT
 *
 * The MIT License (MIT)
 *
 * Copyright (c) <2017> <Stephan Gatzka>
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

#ifndef CIO_WEBSOCKET_LOCATION_HANDLER_H
#define CIO_WEBSOCKET_LOCATION_HANDLER_H

#include <stddef.h>
#include <stdint.h>

#include "cio/export.h"
#include "cio/http_location_handler.h"
#include "cio/timer.h"
#include "cio/websocket.h"
#include "cio/write_buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

enum { CIO_SEC_WEB_SOCKET_KEY_LENGTH = 24 };
enum { CIO_SEC_WEB_SOCKET_GUID_LENGTH = 36 };
enum { CIO_SEC_WEBSOCKET_ACCEPT_LENGTH = 30 };

struct cio_websocket_location_handler {

	/**
	 * @privatesection
	 */
	struct cio_http_location_handler http_location;

	void (*location_handler_free)(struct cio_websocket_location_handler *);

	uint8_t sec_websocket_key[CIO_SEC_WEB_SOCKET_KEY_LENGTH + CIO_SEC_WEB_SOCKET_GUID_LENGTH];

	const char **subprotocols;
	size_t number_subprotocols;
	struct {
		unsigned int current_header_field : 2;
		unsigned int subprotocol_requested : 1;
		unsigned int ws_version_ok : 1;
	} flags;

	signed int chosen_subprotocol;
	char accept_value[CIO_SEC_WEBSOCKET_ACCEPT_LENGTH];
	struct cio_write_buffer wb_upgrade_header;
	struct cio_write_buffer wb_accept_value;
	struct cio_write_buffer wb_protocol_field;
	struct cio_write_buffer wb_protocol_value;
	struct cio_write_buffer wb_protocol_end;

	struct cio_websocket websocket;
};

struct cio_websocket_location_config {
	uint64_t upgrade_response_timeout;
	cio_websocket_on_connect_t on_connect;
	void (*free)(struct cio_websocket_location_handler *);
	unsigned int num_sub_protocols;
	const char *sub_protocols[];
};

/**
 * @brief Initializes a websocket handler.
 * @param handler The handler to initialize.
 * @param subprotocols An array of strings containing the supported subprotocols.
 * Please note that the functions will not copy this array, this array must be
 * available as long as this cio_websocket_location_handler exists!
 * @param num_subprotocols The number of entries @p subprotocols contains.
 * @param on_connect Function that will be called if websocket is connected.
 * @param location_handler_free This function will be called if the client connection for this handler is closed.
 * After this function is called, the memory @p handler points to will no longer be accessed.
 * Could be @c NULL.
 * @return CIO_SUCCESS if no error occured.
 */
CIO_EXPORT enum cio_error cio_websocket_location_handler_init(struct cio_websocket_location_handler *handler,
                                                              const char *subprotocols[],
                                                              size_t num_subprotocols,
                                                              cio_websocket_on_connect_t on_connect,
                                                              void (*location_handler_free)(struct cio_websocket_location_handler *));

#ifdef __cplusplus
}
#endif

#endif
