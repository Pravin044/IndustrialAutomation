#ifndef flowMathCharCmp_H
#define flowMathCharCmp_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "flowConnection.h"
#include "flowLogic.h"


class flowMathCharCmp : public flowLogic
{
public:
   flowMathCharCmp();
   virtual ~flowMathCharCmp();
   virtual wxString  getDefaultName();
#ifdef ENV_EDITOR
   virtual wxInt32   saveDATA(wxFile *FHandle,char chunkName[4],bool isCompiled);
#endif
   virtual wxInt32   loadDATA(wxFile *FHandle,wxUint32 chunkSize,wxUint32 IDOffset,bool isCompiled);
#ifdef ENV_PLAYER
   virtual wxUint64  getAssignedOutput(wxUint64 input);
   virtual wxByte    setCharInput(FlowConnection *connection,wxString value,wxUint32 *flowThreadID,flowObject *object);
   virtual wxByte    getDigitalOutput(FlowConnection *connection,wxInt32 *rcode,wxUint64 lastInput,wxLongLong origCreationTime);
#endif

private:
#ifdef ENV_PLAYER
   wxString txt[MAX_NUM_IOS];
#endif
};

#endif
