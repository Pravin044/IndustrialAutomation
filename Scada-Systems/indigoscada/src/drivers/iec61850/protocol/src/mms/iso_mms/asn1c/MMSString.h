/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-extended.asn"
 * 	`asn1c -fskeletons-copy`
 */

#ifndef	_MMSString_H_
#define	_MMSString_H_


#include <asn_application.h>

/* Including external dependencies */
#include <UTF8String.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MMSString */
typedef UTF8String_t	 MMSString_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MMSString;
asn_struct_free_f MMSString_free;
asn_struct_print_f MMSString_print;
asn_constr_check_f MMSString_constraint;
ber_type_decoder_f MMSString_decode_ber;
der_type_encoder_f MMSString_encode_der;
xer_type_decoder_f MMSString_decode_xer;
xer_type_encoder_f MMSString_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _MMSString_H_ */
