/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "ACSE1"
 * 	found in "../isoAcseLayer.asn"
 * 	`asn1c -fskeletons-copy`
 */

#ifndef	_Applicationcontextnamelist_H_
#define	_Applicationcontextnamelist_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Applicationcontextname.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Applicationcontextnamelist */
typedef struct Applicationcontextnamelist {
	A_SEQUENCE_OF(Applicationcontextname_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Applicationcontextnamelist_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Applicationcontextnamelist;

#ifdef __cplusplus
}
#endif

#endif	/* _Applicationcontextnamelist_H_ */
