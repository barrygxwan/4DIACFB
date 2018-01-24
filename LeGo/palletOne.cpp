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

#include "palletOne.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "palletOne_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_palletOne, g_nStringIdpalletOne)

const CStringDictionary::TStringId FORTE_palletOne::scm_anDataInputNames[] = {g_nStringIdC1, g_nStringIdC2, g_nStringIdC3, g_nStringIdC4};

const CStringDictionary::TStringId FORTE_palletOne::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_palletOne::scm_anDataOutputNames[] = {g_nStringIdFINDPOSITION};

const CStringDictionary::TStringId FORTE_palletOne::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_palletOne::scm_anEIWithIndexes[] = {-1, -1, 0, -1};
const TDataIOID FORTE_palletOne::scm_anEIWith[] = {0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_palletOne::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdCATCHED, g_nStringIdCAMERAED, g_nStringIdPASS};

const TDataIOID FORTE_palletOne::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_palletOne::scm_anEOWithIndexes[] = {-1, 0, -1, -1};
const CStringDictionary::TStringId FORTE_palletOne::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdFINDENEXT, g_nStringIdFULL};

const CStringDictionary::TStringId FORTE_palletOne::scm_anInternalsNames[] = {g_nStringIdpos1, g_nStringIdpos2, g_nStringIdpos3, g_nStringIdpos4, g_nStringIdisFull, g_nStringIdcurrentPos};

const CStringDictionary::TStringId FORTE_palletOne::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdINT};

const SFBInterfaceSpec FORTE_palletOne::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_palletOne::scm_stInternalVars = {6, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_palletOne::setInitialValues(){
  pos1() = -1;
  pos2() = -1;
  pos3() = -1;
  pos4() = -1;
  isFull() = false;
  currentPos() = 0;
}

void FORTE_palletOne::alg_SETPOSITION(void){
pos1() = C1();
pos2() = C2();
pos3() = C3();
pos4() = C4();
}

void FORTE_palletOne::alg_PUTMATERIAL(void){
if((((currentPos() == 1)))){
	pos1() = 1;
};

if((((currentPos() == 2)))){
	pos2() = 1;
};

if((((currentPos() == 3)))){
	pos3() = 1;
};

if((((currentPos() == 4)))){
	pos4() = 1;
};
}

void FORTE_palletOne::alg_SETPASS(void){
if((((currentPos() == 1)))){
	pos1() = 0;
};

if((((currentPos() == 2)))){
	pos2() = 0;
};

if((((currentPos() == 3)))){
	pos3() = 0;
};

if((((currentPos() == 4)))){
	pos4() = 0;
}
}

void FORTE_palletOne::alg_ISFULL(void){
currentPos() = 0;
isFull() = true;

if((((pos1() == -1)))){
	currentPos() = 1;
	isFull() = false;
};

if((((pos2() == -1)))){
	currentPos() = 2;
	isFull() = false;
};

if((((pos3() == -1)))){
	currentPos() = 3;
	isFull() = false;
};

if((((pos4() == -1)))){
	currentPos() = 4;
	isFull() = false;
};
}

void FORTE_palletOne::alg_RESETPOSITION(void){
pos1() = -1;
pos2() = -1;
pos3() = -1;
pos4() = -1;
}

void FORTE_palletOne::alg_SETFINDPOSITION(void){
FINDPOSITION() = currentPos();
}


void FORTE_palletOne::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_palletOne::enterStateInitialize(void){
  m_nECCState = scm_nStateInitialize;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_palletOne::enterStateIdle(void){
  m_nECCState = scm_nStateIdle;
}

void FORTE_palletOne::enterStateInitPosition(void){
  m_nECCState = scm_nStateInitPosition;
  alg_SETPOSITION();
}

void FORTE_palletOne::enterStatePutMaterial(void){
  m_nECCState = scm_nStatePutMaterial;
  alg_PUTMATERIAL();
}

void FORTE_palletOne::enterStateNotifyFind(void){
  m_nECCState = scm_nStateNotifyFind;
  alg_SETFINDPOSITION();
  sendOutputEvent( scm_nEventFINDENEXTID);
}

void FORTE_palletOne::enterStatePassPosition(void){
  m_nECCState = scm_nStatePassPosition;
  alg_SETPASS();
}

void FORTE_palletOne::enterStateExam(void){
  m_nECCState = scm_nStateExam;
  alg_ISFULL();
}

void FORTE_palletOne::enterStateNotifyFull(void){
  m_nECCState = scm_nStateNotifyFull;
  alg_RESETPOSITION();
  sendOutputEvent( scm_nEventFULLID);
}

void FORTE_palletOne::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInitialize();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialize:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIdle:
        if(scm_nEventCAMERAEDID == pa_nEIID)
          enterStateInitPosition();
        else
        if(scm_nEventCATCHEDID == pa_nEIID)
          enterStatePutMaterial();
        else
        if(scm_nEventPASSID == pa_nEIID)
          enterStatePassPosition();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitPosition:
        if(1)
          enterStateExam();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePutMaterial:
        if(1)
          enterStateExam();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNotifyFind:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePassPosition:
        if(1)
          enterStateExam();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExam:
        if(isFull() == false)
          enterStateNotifyFind();
        else
        if(isFull() == true)
          enterStateNotifyFull();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNotifyFull:
        if(1)
          enterStateIdle();
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


