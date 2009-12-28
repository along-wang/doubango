/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_transport_layer.h
 * @brief SIP transport layer.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TINYSIP_TRANSPORT_LAYER_H
#define TINYSIP_TRANSPORT_LAYER_H

#include "tinysip_config.h"

#include "tinysip/transports/tsip_transport.h"
#include "tinysip/tsip_message.h"
#include "tsip.h"

#define TSIP_TRANSPORT_LAYER_CREATE(stack)				tsk_object_new(tsip_transport_layer_def_t, stack)
#define TSIP_TRANSPORT_LAYER_SAFE_FREE(self)			tsk_object_unref(self), self = 0

typedef struct tsip_transport_layer_s
{
	TSK_DECLARE_OBJECT;

	const tsip_stack_handle_t *stack;

	unsigned running:1;
	tsip_transports_L_t *transports;
}
tsip_transport_layer_t;

int tsip_transport_layer_add(tsip_transport_layer_t* self, const char* host, tnet_port_t port, const char* description);
int tsip_transport_layer_remove(tsip_transport_layer_t* self, const char* description);

int tsip_transport_layer_send(const tsip_transport_layer_t* self, const char *branch, const tsip_message_t *msg);

int tsip_transport_layer_start(const tsip_transport_layer_t* self);
int tsip_transport_layer_shutdown(const tsip_transport_layer_t* self);

TINYSIP_API const void *tsip_transport_layer_def_t;

#endif /* TINYSIP_TRANSPORT_LAYER_H */