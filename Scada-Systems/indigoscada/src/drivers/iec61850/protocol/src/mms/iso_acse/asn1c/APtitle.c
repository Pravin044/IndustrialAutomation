/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "ACSE1"
 * 	found in "../isoAcseLayer.asn"
 * 	`asn1c -fskeletons-copy`
 */

#include <asn_internal.h>

#include "APtitle.h"

static asn_TYPE_member_t asn_MBR_APtitle_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct APtitle, choice.aptitleform2),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_APtitleform2,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"aptitleform2"
		},
};
static asn_TYPE_tag2member_t asn_MAP_APtitle_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 } /* aptitleform2 at 129 */
};
static asn_CHOICE_specifics_t asn_SPC_APtitle_specs_1 = {
	sizeof(struct APtitle),
	offsetof(struct APtitle, _asn_ctx),
	offsetof(struct APtitle, present),
	sizeof(((struct APtitle *)0)->present),
	asn_MAP_APtitle_tag2el_1,
	1,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_APtitle = {
	"APtitle",
	"APtitle",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_APtitle_1,
	1,	/* Elements count */
	&asn_SPC_APtitle_specs_1	/* Additional specs */
};

