/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: sqlUpdateMaterial
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-05/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _SQLUPDATEMATERIAL_H_
#define _SQLUPDATEMATERIAL_H_

#include <basicfb.h>
#include <forte_string.h>

class FORTE_sqlUpdateMaterial: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_sqlUpdateMaterial)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &MID() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventATTEMPTCATCHID = 1;
  static const TEventID scm_nEventCATCHEDID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_STRING &catchMid() {
    return *static_cast<CIEC_STRING*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 0, 1, 0);
  void alg_UPDATE(void);
  void alg_SETMID(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateIdle = 2;
  static const TForteInt16 scm_nStateUpdate = 3;
  static const TForteInt16 scm_nStateSetMid = 4;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateIdle(void);
  void enterStateUpdate(void);
  void enterStateSetMid(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_sqlUpdateMaterial(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_sqlUpdateMaterial(){};

};

#endif //close the ifdef sequence from the beginning of the file

