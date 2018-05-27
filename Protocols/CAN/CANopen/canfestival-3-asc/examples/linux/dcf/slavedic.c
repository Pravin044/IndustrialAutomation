
/* File generated by gen_cfile.py. Should not be modified. */

#include "slavedic.h"

/**************************************************************************/
/* Declaration of mapped variables                                        */
/**************************************************************************/
UNS32 counter = 0x0;		/* Mapped at index 0x2000, subindex 0x00 */
INTEGER16 position = 0x0;		/* Mapped at index 0x2001, subindex 0x00 */

/**************************************************************************/
/* Declaration of value range types                                       */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 slavedic_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 slavedic_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 slavedic_iam_a_slave = 1;

TIMER_HANDLE slavedic_heartBeatTimers[1];

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 slavedic_obj1000 = 0x0;	/* 0 */
                    subindex slavedic_Index1000[] = 
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1000, NULL }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 slavedic_obj1001 = 0x0;	/* 0 */
                    subindex slavedic_Index1001[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&slavedic_obj1001, NULL }
                     };

/* index 0x1003 :   Pre-defined Error Field */
                    UNS8 slavedic_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 slavedic_obj1003[] = 
                    {
                      0x0	/* 0 */
                    };
                    subindex slavedic_Index1003[] = 
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1003, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1003[0], NULL }
                     };

/* index 0x1005 :   SYNC COB ID */
                    UNS32 slavedic_obj1005 = 0x0;   /* 0 */

/* index 0x1006 :   Communication / Cycle Period */
                    UNS32 slavedic_obj1006 = 0x0;   /* 0 */

/* index 0x100C :   Guard Time */ 
                    UNS16 slavedic_obj100C = 0x0;   /* 0 */

/* index 0x100D :   Life Time Factor */ 
                    UNS8 slavedic_obj100D = 0x0;   /* 0 */

/* index 0x1014 :   Emergency COB ID */
                    UNS32 slavedic_obj1014 = 0x80 + 0x00;   /* 128 + NodeID */

/* index 0x1016 :   Consumer Heartbeat Time */
                    UNS8 slavedic_highestSubIndex_obj1016 = 0;
                    UNS32 slavedic_obj1016[]={0};

/* index 0x1017 :   Producer Heartbeat Time. */
                    UNS16 slavedic_obj1017 = 0x0;	/* 0 */
                    subindex slavedic_Index1017[] = 
                     {
                       { RW, uint16, sizeof (UNS16), (void*)&slavedic_obj1017, NULL }
                     };

/* index 0x1018 :   Identity. */
                    UNS8 slavedic_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 slavedic_obj1018_Vendor_ID = 0x0;	/* 0 */
                    UNS32 slavedic_obj1018_Product_Code = 0x0;	/* 0 */
                    UNS32 slavedic_obj1018_Revision_Number = 0x0;	/* 0 */
                    UNS32 slavedic_obj1018_Serial_Number = 0x0;	/* 0 */
                    subindex slavedic_Index1018[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1018, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1018_Vendor_ID, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1018_Product_Code, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1018_Revision_Number, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1018_Serial_Number, NULL }
                     };

/* index 0x1200 :   Server SDO Parameter. */
                    UNS8 slavedic_highestSubIndex_obj1200 = 2; /* number of subindex - 1*/
                    UNS32 slavedic_obj1200_COB_ID_Client_to_Server_Receive_SDO = 0x600;	/* 1536 */
                    UNS32 slavedic_obj1200_COB_ID_Server_to_Client_Transmit_SDO = 0x580;	/* 1408 */
                    subindex slavedic_Index1200[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1200, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1200_COB_ID_Client_to_Server_Receive_SDO, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&slavedic_obj1200_COB_ID_Server_to_Client_Transmit_SDO, NULL }
                     };

/* index 0x1400 :   Receive PDO 1 Parameter. */
                    UNS8 slavedic_highestSubIndex_obj1400 = 6; /* number of subindex - 1*/
                    UNS32 slavedic_obj1400_COB_ID_used_by_PDO = 0x200;	/* 512 */
                    UNS8 slavedic_obj1400_Transmission_Type = 0xFE;	/* 254 */
                    UNS16 slavedic_obj1400_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 slavedic_obj1400_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 slavedic_obj1400_Event_Timer = 0x0;	/* 0 */
                    UNS8 slavedic_obj1400_SYNC_start_value = 0x0;	/* 0 */
                    subindex slavedic_Index1400[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1400, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&slavedic_obj1400_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_obj1400_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&slavedic_obj1400_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_obj1400_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&slavedic_obj1400_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_obj1400_SYNC_start_value, NULL }
                     };

/* index 0x1600 :   Receive PDO 1 Mapping. */
                    UNS8 slavedic_highestSubIndex_obj1600 = 1; /* number of subindex - 1*/
                    UNS32 slavedic_obj1600[] = 
                    {
                      0x20010010	/* 536936464 */
                    };
                    subindex slavedic_Index1600[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1600, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&slavedic_obj1600[0], NULL }
                     };

/* index 0x1800 :   Transmit PDO 1 Parameter. */
                    UNS8 slavedic_highestSubIndex_obj1800 = 6; /* number of subindex - 1*/
                    UNS32 slavedic_obj1800_COB_ID_used_by_PDO = 0x180;	/* 384 */
                    UNS8 slavedic_obj1800_Transmission_Type = 0xFE;	/* 254 */
                    UNS16 slavedic_obj1800_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 slavedic_obj1800_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 slavedic_obj1800_Event_Timer = 0x1F4;	/* 500 */
                    UNS8 slavedic_obj1800_SYNC_start_value = 0x0;	/* 0 */
                    subindex slavedic_Index1800[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1800, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&slavedic_obj1800_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_obj1800_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&slavedic_obj1800_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_obj1800_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&slavedic_obj1800_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_obj1800_SYNC_start_value, NULL }
                     };

/* index 0x1A00 :   Transmit PDO 1 Mapping. */
                    UNS8 slavedic_highestSubIndex_obj1A00 = 1; /* number of subindex - 1*/
                    UNS32 slavedic_obj1A00[] = 
                    {
                      0x20000020	/* 536870944 */
                    };
                    subindex slavedic_Index1A00[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&slavedic_highestSubIndex_obj1A00, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&slavedic_obj1A00[0], NULL }
                     };

/* index 0x2000 :   Mapped variable counter */
                    subindex slavedic_Index2000[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&counter, NULL }
                     };

/* index 0x2001 :   Mapped variable position */
                    subindex slavedic_Index2001[] = 
                     {
                       { RW, int16, sizeof (INTEGER16), (void*)&position, NULL }
                     };

/**************************************************************************/
/* Declaration of pointed variables                                       */
/**************************************************************************/

const indextable slavedic_objdict[] = 
{
  { (subindex*)slavedic_Index1000,sizeof(slavedic_Index1000)/sizeof(slavedic_Index1000[0]), 0x1000},
  { (subindex*)slavedic_Index1001,sizeof(slavedic_Index1001)/sizeof(slavedic_Index1001[0]), 0x1001},
  { (subindex*)slavedic_Index1017,sizeof(slavedic_Index1017)/sizeof(slavedic_Index1017[0]), 0x1017},
  { (subindex*)slavedic_Index1018,sizeof(slavedic_Index1018)/sizeof(slavedic_Index1018[0]), 0x1018},
  { (subindex*)slavedic_Index1200,sizeof(slavedic_Index1200)/sizeof(slavedic_Index1200[0]), 0x1200},
  { (subindex*)slavedic_Index1400,sizeof(slavedic_Index1400)/sizeof(slavedic_Index1400[0]), 0x1400},
  { (subindex*)slavedic_Index1600,sizeof(slavedic_Index1600)/sizeof(slavedic_Index1600[0]), 0x1600},
  { (subindex*)slavedic_Index1800,sizeof(slavedic_Index1800)/sizeof(slavedic_Index1800[0]), 0x1800},
  { (subindex*)slavedic_Index1A00,sizeof(slavedic_Index1A00)/sizeof(slavedic_Index1A00[0]), 0x1A00},
  { (subindex*)slavedic_Index2000,sizeof(slavedic_Index2000)/sizeof(slavedic_Index2000[0]), 0x2000},
  { (subindex*)slavedic_Index2001,sizeof(slavedic_Index2001)/sizeof(slavedic_Index2001[0]), 0x2001},
};

const indextable * slavedic_scanIndexOD (CO_Data *d, UNS16 wIndex, UNS32 * errorCode)
{
	int i;
	switch(wIndex){
		case 0x1000: i = 0;break;
		case 0x1001: i = 1;break;
		case 0x1017: i = 2;break;
		case 0x1018: i = 3;break;
		case 0x1200: i = 4;break;
		case 0x1400: i = 5;break;
		case 0x1600: i = 6;break;
		case 0x1800: i = 7;break;
		case 0x1A00: i = 8;break;
		case 0x2000: i = 9;break;
		case 0x2001: i = 10;break;
		default:
			*errorCode = OD_NO_SUCH_OBJECT;
			return NULL;
	}
	*errorCode = OD_SUCCESSFUL;
	return &slavedic_objdict[i];
}

/* 
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status slavedic_PDO_status[1] = {s_PDO_status_Initializer};

const quick_index slavedic_firstIndex = {
  4, /* SDO_SVR */
  0, /* SDO_CLT */
  5, /* PDO_RCV */
  6, /* PDO_RCV_MAP */
  7, /* PDO_TRS */
  8 /* PDO_TRS_MAP */
};

const quick_index slavedic_lastIndex = {
  4, /* SDO_SVR */
  0, /* SDO_CLT */
  5, /* PDO_RCV */
  6, /* PDO_RCV_MAP */
  7, /* PDO_TRS */
  8 /* PDO_TRS_MAP */
};

const UNS16 slavedic_ObjdictSize = sizeof(slavedic_objdict)/sizeof(slavedic_objdict[0]); 

CO_Data slavedic_Data = CANOPEN_NODE_DATA_INITIALIZER(slavedic);
