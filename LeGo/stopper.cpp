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

#include "stopper.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "stopper_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_stopper, g_nStringIdstopper)

const CStringDictionary::TStringId FORTE_stopper::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdtimeParam};

const CStringDictionary::TStringId FORTE_stopper::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_stopper::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdQO1};

const CStringDictionary::TStringId FORTE_stopper::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_stopper::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_stopper::scm_anEIWith[] = {0, 1, 255, 0, 255};
const CStringDictionary::TStringId FORTE_stopper::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdDOWN_REQ};

const TDataIOID FORTE_stopper::scm_anEOWith[] = {0, 255, 1, 0, 255};
const TForteInt16 FORTE_stopper::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_stopper::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SAdapterInstanceDef FORTE_stopper::scm_astAdapterInstances[] = {
{g_nStringIdATimeOut, g_nStringIdATimeOut, true }};

const SFBInterfaceSpec FORTE_stopper::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};

void FORTE_stopper::alg_initialize(void){
QO() = QI();
QO1() = false;
}

void FORTE_stopper::alg_deInitialize(void){

QO() = false;
QO1() = false;
}

void FORTE_stopper::alg_normalOperation(void){
QO1() = true;
}

void FORTE_stopper::alg_ATimeOut(void){
ATimeOut().DT() = timeParam();
}

void FORTE_stopper::alg_RESET(void){
QO1() = false;
}


void FORTE_stopper::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_stopper::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_stopper::enterStateRelease(void){
  m_nECCState = scm_nStateRelease;
  alg_normalOperation();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_stopper::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_stopper::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_stopper::enterStatetimeDelay(void){
  m_nECCState = scm_nStatetimeDelay;
  alg_ATimeOut();
  sendAdapterEvent(scm_nATimeOutAdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_stopper::enterStateReset(void){
  m_nECCState = scm_nStateReset;
  alg_RESET();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_stopper::executeEvent(int pa_nEIID){
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
      case scm_nStateRelease:
        if(1)
          enterStatetimeDelay();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventDOWN_REQID == pa_nEIID)
          enterStateRelease();
        else
        if((scm_nEventINITID == pa_nEIID) && ((false == QI())))
          enterStateDeInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatetimeDelay:
        if(ATimeOut().TimeOut() == pa_nEIID)
          enterStateReset();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReset:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 6.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


