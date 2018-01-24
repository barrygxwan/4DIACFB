/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: stopper
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-17/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _STOPPER_H_
#define _STOPPER_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_time.h>
#include "ATimeOut.h"

class FORTE_stopper: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_stopper)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &timeParam() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &QO1() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventDOWN_REQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_ATimeOut& ATimeOut() {
    return (*static_cast<FORTE_ATimeOut*>(m_apoAdapters[0]));
  };
  static const int scm_nATimeOutAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 2, 0, 1);
  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_normalOperation(void);
  void alg_ATimeOut(void);
  void alg_RESET(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateRelease = 2;
  static const TForteInt16 scm_nStateInitialized = 3;
  static const TForteInt16 scm_nStateDeInit = 4;
  static const TForteInt16 scm_nStatetimeDelay = 5;
  static const TForteInt16 scm_nStateReset = 6;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateRelease(void);
  void enterStateInitialized(void);
  void enterStateDeInit(void);
  void enterStatetimeDelay(void);
  void enterStateReset(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_stopper(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_stopper(){};

};

#endif //close the ifdef sequence from the beginning of the file

