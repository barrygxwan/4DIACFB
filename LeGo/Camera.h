/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Camera
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-19/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>

class FORTE_Camera: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Camera)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &PhotoMSGIn1() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_BOOL &PhotoMSGIn2() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &PhotoMSGOut1() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_BOOL &PhotoMSGOut2() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventTakePhotoID = 1;
  static const TEventID scm_nEventRECVPhotoMSGID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventDoTakePhotoID = 1;
  static const TEventID scm_nEventSendPhotoMSGID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(3, 3, 3, 0, 0);
  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_normalOperation(void);
  void alg_PhotoMSG(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateNormalOp = 2;
  static const TForteInt16 scm_nStateInitialized = 3;
  static const TForteInt16 scm_nStateDeInit = 4;
  static const TForteInt16 scm_nStateRecvMSG = 5;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateNormalOp(void);
  void enterStateInitialized(void);
  void enterStateDeInit(void);
  void enterStateRecvMSG(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Camera(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Camera(){};

};

#endif //close the ifdef sequence from the beginning of the file

