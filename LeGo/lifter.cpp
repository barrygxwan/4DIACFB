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

#include "lifter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "lifter_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_lifter, g_nStringIdlifter)

const CStringDictionary::TStringId FORTE_lifter::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdQI1, g_nStringIdtimeParam};

const CStringDictionary::TStringId FORTE_lifter::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_lifter::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdQO1};

const CStringDictionary::TStringId FORTE_lifter::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_lifter::scm_anEIWithIndexes[] = {0, 3, -1};
const TDataIOID FORTE_lifter::scm_anEIWith[] = {0, 2, 255, 1, 255};
const CStringDictionary::TStringId FORTE_lifter::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUP_REQ, g_nStringIdDOWN_REQ};

const TDataIOID FORTE_lifter::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_lifter::scm_anEOWithIndexes[] = {0, 2, -1, -1, -1};
const CStringDictionary::TStringId FORTE_lifter::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdDo_CNF, g_nStringIdUP_FINISHED, g_nStringIdDOWN_FINISHED};

const SAdapterInstanceDef FORTE_lifter::scm_astAdapterInstances[] = {
{g_nStringIdATimeOut, g_nStringIdATimeOut1, true },
{g_nStringIdATimeOut, g_nStringIdATimeOut2, true }};

const SFBInterfaceSpec FORTE_lifter::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  2,scm_astAdapterInstances};

void FORTE_lifter::alg_initialize(void){
QO1() = false;
QO() = QI();
}

void FORTE_lifter::alg_deInitialize(void){

QO() = false;
}

void FORTE_lifter::alg_UP(void){
QO1() = true;
}

void FORTE_lifter::alg_UPtimeDelay(void){
ATimeOut1().DT() = timeParam();
}

void FORTE_lifter::alg_Down(void){
QO1() = false;
}

void FORTE_lifter::alg_DownTimeDelay(void){
ATimeOut2().DT() = timeParam();
}


void FORTE_lifter::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_lifter::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_lifter::enterStateDoUP(void){
  m_nECCState = scm_nStateDoUP;
  alg_UP();
  sendOutputEvent( scm_nEventDo_CNFID);
}

void FORTE_lifter::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_lifter::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_lifter::enterStateUPtime(void){
  m_nECCState = scm_nStateUPtime;
  alg_UPtimeDelay();
  sendAdapterEvent(scm_nATimeOut1AdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_lifter::enterStateUPfinish(void){
  m_nECCState = scm_nStateUPfinish;
  sendOutputEvent( scm_nEventUP_FINISHEDID);
}

void FORTE_lifter::enterStateDoDOWN(void){
  m_nECCState = scm_nStateDoDOWN;
  alg_Down();
  sendOutputEvent( scm_nEventDo_CNFID);
}

void FORTE_lifter::enterStateDOWNtime(void){
  m_nECCState = scm_nStateDOWNtime;
  alg_DownTimeDelay();
  sendAdapterEvent(scm_nATimeOut2AdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_lifter::enterStateDownFinish(void){
  m_nECCState = scm_nStateDownFinish;
  alg_initialize();
  sendOutputEvent( scm_nEventDOWN_FINISHEDID);
}

void FORTE_lifter::executeEvent(int pa_nEIID){
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
      case scm_nStateDoUP:
        if(1)
          enterStateUPtime();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventUP_REQID == pa_nEIID)
          enterStateDoUP();
        else
        if((scm_nEventINITID == pa_nEIID) && ((false == QI())))
          enterStateDeInit();
        else
        if(scm_nEventDOWN_REQID == pa_nEIID)
          enterStateDoDOWN();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUPtime:
        if(ATimeOut1().TimeOut() == pa_nEIID)
          enterStateUPfinish();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUPfinish:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDoDOWN:
        if(1)
          enterStateDOWNtime();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDOWNtime:
        if(ATimeOut2().TimeOut() == pa_nEIID)
          enterStateDownFinish();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDownFinish:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 9.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


