/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: lifter
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-17/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _LIFTER_H_
#define _LIFTER_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_time.h>
#include "ATimeOut.h"

class FORTE_lifter: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_lifter)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &QI1() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_TIME &timeParam() {
    return *static_cast<CIEC_TIME*>(getDI(2));
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
  static const TEventID scm_nEventUP_REQID = 1;
  static const TEventID scm_nEventDOWN_REQID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventDo_CNFID = 1;
  static const TEventID scm_nEventUP_FINISHEDID = 2;
  static const TEventID scm_nEventDOWN_FINISHEDID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_ATimeOut& ATimeOut1() {
    return (*static_cast<FORTE_ATimeOut*>(m_apoAdapters[0]));
  };
  static const int scm_nATimeOut1AdpNum = 0;
  FORTE_ATimeOut& ATimeOut2() {
    return (*static_cast<FORTE_ATimeOut*>(m_apoAdapters[1]));
  };
  static const int scm_nATimeOut2AdpNum = 1;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 3, 2, 0, 2);
  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_UP(void);
  void alg_UPtimeDelay(void);
  void alg_Down(void);
  void alg_DownTimeDelay(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateDoUP = 2;
  static const TForteInt16 scm_nStateInitialized = 3;
  static const TForteInt16 scm_nStateDeInit = 4;
  static const TForteInt16 scm_nStateUPtime = 5;
  static const TForteInt16 scm_nStateUPfinish = 6;
  static const TForteInt16 scm_nStateDoDOWN = 7;
  static const TForteInt16 scm_nStateDOWNtime = 8;
  static const TForteInt16 scm_nStateDownFinish = 9;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateDoUP(void);
  void enterStateInitialized(void);
  void enterStateDeInit(void);
  void enterStateUPtime(void);
  void enterStateUPfinish(void);
  void enterStateDoDOWN(void);
  void enterStateDOWNtime(void);
  void enterStateDownFinish(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_lifter(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_lifter(){};

};

#endif //close the ifdef sequence from the beginning of the file

