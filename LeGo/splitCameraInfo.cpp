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

#include "splitCameraInfo.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "splitCameraInfo_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_splitCameraInfo, g_nStringIdsplitCameraInfo)

const CStringDictionary::TStringId FORTE_splitCameraInfo::scm_anDataInputNames[] = {g_nStringIdINFO};

const CStringDictionary::TStringId FORTE_splitCameraInfo::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_splitCameraInfo::scm_anDataOutputNames[] = {g_nStringIdC1, g_nStringIdC2, g_nStringIdC3, g_nStringIdC4};

const CStringDictionary::TStringId FORTE_splitCameraInfo::scm_anDataOutputTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT};

const TForteInt16 FORTE_splitCameraInfo::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_splitCameraInfo::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_splitCameraInfo::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdCAMERAED};

const TDataIOID FORTE_splitCameraInfo::scm_anEOWith[] = {0, 1, 2, 3, 255};
const TForteInt16 FORTE_splitCameraInfo::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_splitCameraInfo::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdDONE};

const SFBInterfaceSpec FORTE_splitCameraInfo::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_splitCameraInfo::alg_SPLIT(void){
char * info = INFO().getValue();
	if(info[0] != '9') {
		C1() = 2;
	}
	else {
		C1() = -1;
	}
	if(info[1] != '9') {
		C2() = 2;
	}
	else {
		C2() = -1;
	}
	if(info[2] != '9') {
		C3() = 2;
	}
	else {
		C3() = -1;
	}
	if(info[3] != '9') {
		C4() = 2;
	}
	else {
		C4() = -1;
	}
}


void FORTE_splitCameraInfo::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_splitCameraInfo::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_splitCameraInfo::enterStateSplit(void){
  m_nECCState = scm_nStateSplit;
  alg_SPLIT();
  sendOutputEvent( scm_nEventDONEID);
}

void FORTE_splitCameraInfo::enterStateState(void){
  m_nECCState = scm_nStateState;
}

void FORTE_splitCameraInfo::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(1)
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSplit:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState:
        if(scm_nEventCAMERAEDID == pa_nEIID)
          enterStateSplit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


