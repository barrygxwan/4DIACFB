/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: splitCameraInfo
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-23/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _SPLITCAMERAINFO_H_
#define _SPLITCAMERAINFO_H_

#include <basicfb.h>
#include <forte_string.h>
#include <forte_int.h>

class FORTE_splitCameraInfo: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_splitCameraInfo)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &INFO() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &C1() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  CIEC_INT &C2() {
    return *static_cast<CIEC_INT*>(getDO(1));
  };

  CIEC_INT &C3() {
    return *static_cast<CIEC_INT*>(getDO(2));
  };

  CIEC_INT &C4() {
    return *static_cast<CIEC_INT*>(getDO(3));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventCAMERAEDID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventDONEID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 4, 0, 0);
  void alg_SPLIT(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateSplit = 2;
  static const TForteInt16 scm_nStateState = 3;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateSplit(void);
  void enterStateState(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_splitCameraInfo(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_splitCameraInfo(){};

};

#endif //close the ifdef sequence from the beginning of the file

