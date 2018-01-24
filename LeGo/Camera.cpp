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

#include "Camera.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Camera_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Camera, g_nStringIdCamera)

const CStringDictionary::TStringId FORTE_Camera::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPhotoMSGIn1, g_nStringIdPhotoMSGIn2};

const CStringDictionary::TStringId FORTE_Camera::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Camera::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdPhotoMSGOut1, g_nStringIdPhotoMSGOut2};

const CStringDictionary::TStringId FORTE_Camera::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_Camera::scm_anEIWithIndexes[] = {0, -1, 2};
const TDataIOID FORTE_Camera::scm_anEIWith[] = {0, 255, 1, 2, 255};
const CStringDictionary::TStringId FORTE_Camera::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdTakePhoto, g_nStringIdRECVPhotoMSG};

const TDataIOID FORTE_Camera::scm_anEOWith[] = {0, 255, 0, 255, 1, 2, 255};
const TForteInt16 FORTE_Camera::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_Camera::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdDoTakePhoto, g_nStringIdSendPhotoMSG};

const SFBInterfaceSpec FORTE_Camera::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_Camera::alg_initialize(void){

QO() = QI();
}

void FORTE_Camera::alg_deInitialize(void){

QO() = false;
}

void FORTE_Camera::alg_normalOperation(void){
QO() = QI();

if((true == QI())){
/*   only perform normal operation of QI is true*/

};

}

void FORTE_Camera::alg_PhotoMSG(void){
PhotoMSGOut1() = PhotoMSGIn1();
PhotoMSGOut2() = PhotoMSGIn2();
}


void FORTE_Camera::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Camera::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Camera::enterStateNormalOp(void){
  m_nECCState = scm_nStateNormalOp;
  sendOutputEvent( scm_nEventDoTakePhotoID);
}

void FORTE_Camera::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_Camera::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Camera::enterStateRecvMSG(void){
  m_nECCState = scm_nStateRecvMSG;
  alg_PhotoMSG();
  sendOutputEvent( scm_nEventSendPhotoMSGID);
}

void FORTE_Camera::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventINITID == pa_nEIID) && ((true == QI())))
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNormalOp:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventTakePhotoID == pa_nEIID)
          enterStateNormalOp();
        else
        if((scm_nEventINITID == pa_nEIID) && ((false == QI())))
          enterStateDeInit();
        else
        if(scm_nEventRECVPhotoMSGID == pa_nEIID)
          enterStateRecvMSG();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRecvMSG:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


