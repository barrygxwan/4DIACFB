/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: palletOne
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-05/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _PALLETONE_H_
#define _PALLETONE_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_int.h>

class FORTE_palletOne: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_palletOne)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &C1() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  CIEC_INT &C2() {
    return *static_cast<CIEC_INT*>(getDI(1));
  };

  CIEC_INT &C3() {
    return *static_cast<CIEC_INT*>(getDI(2));
  };

  CIEC_INT &C4() {
    return *static_cast<CIEC_INT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &FINDPOSITION() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventCATCHEDID = 1;
  static const TEventID scm_nEventCAMERAEDID = 2;
  static const TEventID scm_nEventPASSID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventFINDENEXTID = 1;
  static const TEventID scm_nEventFULLID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &pos1() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_INT &pos2() {
    return *static_cast<CIEC_INT*>(getVarInternal(1));
  };

  CIEC_INT &pos3() {
    return *static_cast<CIEC_INT*>(getVarInternal(2));
  };

  CIEC_INT &pos4() {
    return *static_cast<CIEC_INT*>(getVarInternal(3));
  };

  CIEC_BOOL &isFull() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(4));
  };

  CIEC_INT &currentPos() {
    return *static_cast<CIEC_INT*>(getVarInternal(5));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 4, 1, 6, 0);

virtual void setInitialValues();
  void alg_SETPOSITION(void);
  void alg_PUTMATERIAL(void);
  void alg_SETPASS(void);
  void alg_ISFULL(void);
  void alg_RESETPOSITION(void);
  void alg_SETFINDPOSITION(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialize = 1;
  static const TForteInt16 scm_nStateIdle = 2;
  static const TForteInt16 scm_nStateInitPosition = 3;
  static const TForteInt16 scm_nStatePutMaterial = 4;
  static const TForteInt16 scm_nStateNotifyFind = 5;
  static const TForteInt16 scm_nStatePassPosition = 6;
  static const TForteInt16 scm_nStateExam = 7;
  static const TForteInt16 scm_nStateNotifyFull = 8;

  void enterStateSTART(void);
  void enterStateInitialize(void);
  void enterStateIdle(void);
  void enterStateInitPosition(void);
  void enterStatePutMaterial(void);
  void enterStateNotifyFind(void);
  void enterStatePassPosition(void);
  void enterStateExam(void);
  void enterStateNotifyFull(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_palletOne(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_palletOne(){};

};

#endif //close the ifdef sequence from the beginning of the file

