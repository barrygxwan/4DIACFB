/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: logic
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-09/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _LOGIC_H_
#define _LOGIC_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_time.h>
#include "ATimeOut.h"

class FORTE_logic: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_logic)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI0() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &QI1() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_TIME &timePara() {
    return *static_cast<CIEC_TIME*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO0() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &QO1() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &QO2() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventNEXTID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_ATimeOut& timeOut1() {
    return (*static_cast<FORTE_ATimeOut*>(m_apoAdapters[0]));
  };
  static const int scm_ntimeOut1AdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(3, 3, 3, 0, 1);
  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_setQO1(void);
  void alg_resetQO1(void);
  void alg_timeDelay(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateenable = 2;
  static const TForteInt16 scm_nStateInitialized = 3;
  static const TForteInt16 scm_nStateDeInit = 4;
  static const TForteInt16 scm_nStateunenable = 5;
  static const TForteInt16 scm_nStatedelay = 6;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateenable(void);
  void enterStateInitialized(void);
  void enterStateDeInit(void);
  void enterStateunenable(void);
  void enterStatedelay(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_logic(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_logic(){};

};

#endif //close the ifdef sequence from the beginning of the file

