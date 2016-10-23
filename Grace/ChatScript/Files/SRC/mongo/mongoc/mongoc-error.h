/*
 * Copyright 2013 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MONGOC_ERRORS_H
#define MONGOC_ERRORS_H

#if !defined (MONGOC_INSIDE) && !defined (MONGOC_COMPILATION)
#pragma error "Only <mongoc.h> can be included directly."
#endif

#include "../bson/bson.h"


BSON_BEGIN_DECLS


typedef enum
{
   MONGOC_ERROR_CLIENT = 1,
   MONGOC_ERROR_STREAM,
   MONGOC_ERROR_PROTOCOL,
   MONGOC_ERROR_CURSOR,
   MONGOC_ERROR_QUERY,
   MONGOC_ERROR_INSERT,
   MONGOC_ERROR_SASL,
   MONGOC_ERROR_BSON,
   MONGOC_ERROR_MATCHER,
   MONGOC_ERROR_NAMESPACE,
   MONGOC_ERROR_COMMAND,
   MONGOC_ERROR_COLLECTION,
   MONGOC_ERROR_GRIDFS,
   MONGOC_ERROR_SCRAM,
   MONGOC_ERROR_SERVER_SELECTION,
   MONGOC_ERROR_WRITE_CONCERN,
} mongoc_error_domain_t;


typedef enum
{
   MONGOC_ERROR_STREAM_INVALID_TYPE = 1,
   MONGOC_ERROR_STREAM_INVALID_STATE,
   MONGOC_ERROR_STREAM_NAME_RESOLUTION,
   MONGOC_ERROR_STREAM_SOCKET,
   MONGOC_ERROR_STREAM_CONNECT,
   MONGOC_ERROR_STREAM_NOT_ESTABLISHED,

   MONGOC_ERROR_CLIENT_NOT_READY,
   MONGOC_ERROR_CLIENT_TOO_BIG,
   MONGOC_ERROR_CLIENT_TOO_SMALL,
   MONGOC_ERROR_CLIENT_GETNONCE,
   MONGOC_ERROR_CLIENT_AUTHENTICATE,
   MONGOC_ERROR_CLIENT_NO_ACCEPTABLE_PEER,
   MONGOC_ERROR_CLIENT_IN_EXHAUST,

   MONGOC_ERROR_PROTOCOL_INVALID_REPLY,
   MONGOC_ERROR_PROTOCOL_BAD_WIRE_VERSION,

   MONGOC_ERROR_CURSOR_INVALID_CURSOR,

   MONGOC_ERROR_QUERY_FAILURE,

   MONGOC_ERROR_BSON_INVALID,

   MONGOC_ERROR_MATCHER_INVALID,

   MONGOC_ERROR_NAMESPACE_INVALID,
   MONGOC_ERROR_NAMESPACE_INVALID_FILTER_TYPE,

   MONGOC_ERROR_COMMAND_INVALID_ARG,

   MONGOC_ERROR_COLLECTION_INSERT_FAILED,
   MONGOC_ERROR_COLLECTION_UPDATE_FAILED,
   MONGOC_ERROR_COLLECTION_DELETE_FAILED,
   MONGOC_ERROR_COLLECTION_DOES_NOT_EXIST = 26,

   MONGOC_ERROR_GRIDFS_INVALID_FILENAME,

   MONGOC_ERROR_SCRAM_NOT_DONE,
   MONGOC_ERROR_SCRAM_PROTOCOL_ERROR,

   MONGOC_ERROR_QUERY_COMMAND_NOT_FOUND = 59,
   MONGOC_ERROR_QUERY_NOT_TAILABLE = 13051,

   MONGOC_ERROR_SERVER_SELECTION_BAD_WIRE_VERSION,
   MONGOC_ERROR_SERVER_SELECTION_FAILURE,
   MONGOC_ERROR_SERVER_SELECTION_INVALID_ID,

   MONGOC_ERROR_GRIDFS_CHUNK_MISSING,

   /* Dup with query failure. */
   MONGOC_ERROR_PROTOCOL_ERROR = 17,

   MONGOC_ERROR_WRITE_CONCERN_ERROR = 64,
} mongoc_error_code_t;


BSON_END_DECLS


#endif /* MONGOC_ERRORS_H */
