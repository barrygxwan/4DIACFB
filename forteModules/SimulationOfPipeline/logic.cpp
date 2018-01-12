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

#include "logic.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "logic_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_logic, g_nStringIdlogic)

const CStringDictionary::TStringId FORTE_logic::scm_anDataInputNames[] = {g_nStringIdQI0, g_nStringIdQI1, g_nStringIdtimePara};

const CStringDictionary::TStringId FORTE_logic::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_logic::scm_anDataOutputNames[] = {g_nStringIdQO0, g_nStringIdQO1, g_nStringIdQO2};

const CStringDictionary::TStringId FORTE_logic::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_logic::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_logic::scm_anEIWith[] = {0, 2, 255, 1, 2, 255};
const CStringDictionary::TStringId FORTE_logic::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_logic::scm_anEOWith[] = {0, 255, 1, 255, 2, 255};
const TForteInt16 FORTE_logic::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_logic::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdNEXT};

const SAdapterInstanceDef FORTE_logic::scm_astAdapterInstances[] = {
{g_nStringIdATimeOut, g_nStringIdtimeOut1, true }};

const SFBInterfaceSpec FORTE_logic::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};

void FORTE_logic::alg_initialize(void){

QO0() = QI0();
}

void FORTE_logic::alg_deInitialize(void){

QO0() = false;
}

void FORTE_logic::alg_setQO1(void){
QO1() = true;
}

void FORTE_logic::alg_resetQO1(void){
QO1() = false;
QO2() = true;
}

void FORTE_logic::alg_timeDelay(void){
timeOut1().DT() = timePara();
}


void FORTE_logic::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_logic::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_logic::enterStateenable(void){
  m_nECCState = scm_nStateenable;
  alg_setQO1();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_logic::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_logic::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_logic::enterStateunenable(void){
  m_nECCState = scm_nStateunenable;
  alg_resetQO1();
  sendOutputEvent( scm_nEventCNFID);
  sendOutputEvent( scm_nEventNEXTID);
}

void FORTE_logic::enterStatedelay(void){
  m_nECCState = scm_nStatedelay;
  alg_timeDelay();
  sendAdapterEvent(scm_ntimeOut1AdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_logic::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(true == QI0())
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
      case scm_nStateenable:
        if(1)
          enterStatedelay();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if((scm_nEventREQID == pa_nEIID) && ((true == QI1())))
          enterStateenable();
        else
        if(false == QI0())
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
      case scm_nStateunenable:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatedelay:
        if(timeOut1().TimeOut() == pa_nEIID)
          enterStateunenable();
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


