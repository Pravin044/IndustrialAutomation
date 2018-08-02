/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO8823PRESENTATION"
 * 	found in "../isoPresentationLayer.asn"
 * 	`asn1c -fskeletons-copy`
 */

#ifndef	_PDVlist_H_
#define	_PDVlist_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Transfersyntaxname.h"
#include "Presentationcontextidentifier.h"
#include <ANY.h>
#include <OCTET_STRING.h>
#include <BIT_STRING.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum presentationdatavalues_PR {
	presentationdatavalues_PR_NOTHING,	/* No components present */
	presentationdatavalues_PR_singleASN1type,
	presentationdatavalues_PR_octetaligned,
	presentationdatavalues_PR_arbitrary
} presentationdatavalues_PR;

/* PDVlist */
typedef struct PDVlist {
	Transfersyntaxname_t	*transfersyntaxname	/* OPTIONAL */;
	Presentationcontextidentifier_t	 presentationcontextidentifier;
	struct presentationdatavalues {
		presentationdatavalues_PR present;
		union PDVlist__presentationdatavalues_u {
			ANY_t	 singleASN1type;
			OCTET_STRING_t	 octetaligned;
			BIT_STRING_t	 arbitrary;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} presentationdatavalues;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDVlist_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDVlist;

#ifdef __cplusplus
}
#endif

#endif	/* _PDVlist_H_ */
