/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: findNext
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-05/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _FINDNEXT_H_
#define _FINDNEXT_H_

#include <basicfb.h>
#include <forte_string.h>
#include <forte_int.h>

class FORTE_findNext: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_findNext)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &FINDPOSITION() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &CATCHINFO() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_STRING &MID() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventFINDNEXTID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCATCHID = 1;
  static const TEventID scm_nEventPASSID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_STRING &catchOrPass() {
    return *static_cast<CIEC_STRING*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 1, 2, 1, 0);

virtual void setInitialValues();
  void alg_FIND(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialize = 1;
  static const TForteInt16 scm_nStateFind = 2;
  static const TForteInt16 scm_nStateCatch = 3;
  static const TForteInt16 scm_nStatePass = 4;
  static const TForteInt16 scm_nStateIdle = 5;

  void enterStateSTART(void);
  void enterStateInitialize(void);
  void enterStateFind(void);
  void enterStateCatch(void);
  void enterStatePass(void);
  void enterStateIdle(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_findNext(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_findNext(){};

};

#endif //close the ifdef sequence from the beginning of the file

