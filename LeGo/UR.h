/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: UR
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-18/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _UR_H_
#define _UR_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <forte_time.h>
#include "ATimeOut.h"

class FORTE_UR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_UR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &TakePhotoTimePara() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_STRING &PhotoMSGIN() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_STRING &URGraspMSG() {
    return *static_cast<CIEC_STRING*>(getDI(3));
  };

  CIEC_BOOL &PhotoMSGForMaterial() {
    return *static_cast<CIEC_BOOL*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &PositionInPallet() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_STRING &PhotoMSGOUT() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  CIEC_STRING &PositionInMaterial() {
    return *static_cast<CIEC_STRING*>(getDO(3));
  };

  CIEC_STRING &GraspNumber() {
    return *static_cast<CIEC_STRING*>(getDO(4));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventPalletInID = 1;
  static const TEventID scm_nEventURinPalletPositionID = 2;
  static const TEventID scm_nEventRecvPhotoMSGID = 3;
  static const TEventID scm_nEventURGraspID = 4;
  static const TEventID scm_nEventURinMaterialPositionID = 5;
  static const TEventID scm_nEventGraspDoneID = 6;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventDoGoPalletID = 1;
  static const TEventID scm_nEventTakePhotoID = 2;
  static const TEventID scm_nEventSendPhotoMSGID = 3;
  static const TEventID scm_nEventDoGoMaterialID = 4;
  static const TEventID scm_nEventDoGraspID = 5;
  static const TEventID scm_nEventUpdatePalletID = 6;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &isFirst() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  CIEC_BOOL &isMSGForPallet() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(1));
  };

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_ATimeOut& ATimeOut() {
    return (*static_cast<FORTE_ATimeOut*>(m_apoAdapters[0]));
  };
  static const int scm_nATimeOutAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(7, 5, 5, 2, 1);
  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_normalOperation(void);
  void alg_GoPosition1(void);
  void alg_wait(void);
  void alg_GoPosition2(void);
  void alg_PalletMSGProcessing(void);
  void alg_StartGrasp(void);
  void alg_GoMaterial(void);
  void alg_Update(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateGoP1 = 2;
  static const TForteInt16 scm_nStateOperationOnPallet = 3;
  static const TForteInt16 scm_nStateDeInit = 4;
  static const TForteInt16 scm_nStateURinPosition1 = 5;
  static const TForteInt16 scm_nStateWaitTime = 6;
  static const TForteInt16 scm_nStateGoP2 = 7;
  static const TForteInt16 scm_nStateURinPosition2 = 8;
  static const TForteInt16 scm_nStatePalletMSG = 9;
  static const TForteInt16 scm_nStateMaterialMSG = 10;
  static const TForteInt16 scm_nStateOperationOnMaterialArea = 11;
  static const TForteInt16 scm_nStateGoMaterial = 12;
  static const TForteInt16 scm_nStateURinMaterialPosition = 13;
  static const TForteInt16 scm_nStateGraspDone = 14;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateGoP1(void);
  void enterStateOperationOnPallet(void);
  void enterStateDeInit(void);
  void enterStateURinPosition1(void);
  void enterStateWaitTime(void);
  void enterStateGoP2(void);
  void enterStateURinPosition2(void);
  void enterStatePalletMSG(void);
  void enterStateMaterialMSG(void);
  void enterStateOperationOnMaterialArea(void);
  void enterStateGoMaterial(void);
  void enterStateURinMaterialPosition(void);
  void enterStateGraspDone(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_UR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_UR(){};

};

#endif //close the ifdef sequence from the beginning of the file

