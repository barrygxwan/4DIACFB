/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WorkstationCtl
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-10/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "WorkstationCtl.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WorkstationCtl_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_WorkstationCtl, g_nStringIdWorkstationCtl)

const CStringDictionary::TStringId FORTE_WorkstationCtl::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdQI1, g_nStringIdRedPara, g_nStringIdYellowPara};

const CStringDictionary::TStringId FORTE_WorkstationCtl::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdTIME, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_WorkstationCtl::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdGreen, g_nStringIdRed, g_nStringIdYellow, g_nStringIdQO1};

const CStringDictionary::TStringId FORTE_WorkstationCtl::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_WorkstationCtl::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_WorkstationCtl::scm_anEIWith[] = {0, 2, 3, 255, 1, 255};
const CStringDictionary::TStringId FORTE_WorkstationCtl::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_WorkstationCtl::scm_anEOWith[] = {0, 255, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_WorkstationCtl::scm_anEOWithIndexes[] = {0, 2, 6, -1};
const CStringDictionary::TStringId FORTE_WorkstationCtl::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdNEXT};

const SAdapterInstanceDef FORTE_WorkstationCtl::scm_astAdapterInstances[] = {
{g_nStringIdATimeOut, g_nStringIdATimeOut1, true },
{g_nStringIdATimeOut, g_nStringIdATimeOut2, true }};

const SFBInterfaceSpec FORTE_WorkstationCtl::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  2,scm_astAdapterInstances};

void FORTE_WorkstationCtl::alg_initialize(void){

QO() = QI();
}

void FORTE_WorkstationCtl::alg_deInitialize(void){

QO() = false;
}

void FORTE_WorkstationCtl::alg_idel(void){
Green() = true;
Red() = false;
Yellow() = false;
}

void FORTE_WorkstationCtl::alg_WoktimeDelay(void){
ATimeOut1().DT() = RedPara();
}

void FORTE_WorkstationCtl::alg_busy(void){
Green() = false;
Red() = true;
Yellow() = false;
}

void FORTE_WorkstationCtl::alg_FinishFlag(void){
Green() = false;
Red() = false;
Yellow() = true;
}

void FORTE_WorkstationCtl::alg_FlagTime(void){
ATimeOut2().DT() = YellowPara();
}


void FORTE_WorkstationCtl::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_WorkstationCtl::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_WorkstationCtl::enterStategreen(void){
  m_nECCState = scm_nStategreen;
  alg_idel();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_WorkstationCtl::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_WorkstationCtl::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_WorkstationCtl::enterStateGreenToRed(void){
  m_nECCState = scm_nStateGreenToRed;
  alg_busy();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_WorkstationCtl::enterStateRedDelay(void){
  m_nECCState = scm_nStateRedDelay;
  alg_WoktimeDelay();
  sendAdapterEvent(scm_nATimeOut1AdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_WorkstationCtl::enterStateRedToYellow(void){
  m_nECCState = scm_nStateRedToYellow;
  alg_FinishFlag();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_WorkstationCtl::enterStateYellowDelay(void){
  m_nECCState = scm_nStateYellowDelay;
  alg_FlagTime();
  sendAdapterEvent(scm_nATimeOut2AdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_WorkstationCtl::executeEvent(int pa_nEIID){
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
      case scm_nStategreen:
        if((scm_nEventREQID == pa_nEIID) && ((true == QI1())))
          enterStateGreenToRed();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if((scm_nEventINITID == pa_nEIID) && ((false == QI())))
          enterStateDeInit();
        else
        if(1)
          enterStategreen();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGreenToRed:
        if(1)
          enterStateRedDelay();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRedDelay:
        if(ATimeOut1().TimeOut() == pa_nEIID)
          enterStateRedToYellow();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRedToYellow:
        if(1)
          enterStateYellowDelay();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateYellowDelay:
        if(ATimeOut2().TimeOut() == pa_nEIID)
          enterStategreen();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 8.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


