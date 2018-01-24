/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: UR
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-18/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "UR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "UR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_UR, g_nStringIdUR)

const CStringDictionary::TStringId FORTE_UR::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdTakePhotoTimePara, g_nStringIdPhotoMSGIN, g_nStringIdURGraspMSG, g_nStringIdPhotoMSGForMaterial};

const CStringDictionary::TStringId FORTE_UR::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_UR::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdPositionInPallet, g_nStringIdPhotoMSGOUT, g_nStringIdPositionInMaterial, g_nStringIdGraspNumber};

const CStringDictionary::TStringId FORTE_UR::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_UR::scm_anEIWithIndexes[] = {0, -1, -1, 3, 6, -1, -1};
const TDataIOID FORTE_UR::scm_anEIWith[] = {0, 1, 255, 2, 4, 255, 3, 255};
const CStringDictionary::TStringId FORTE_UR::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdPalletIn, g_nStringIdURinPalletPosition, g_nStringIdRecvPhotoMSG, g_nStringIdURGrasp, g_nStringIdURinMaterialPosition, g_nStringIdGraspDone};

const TDataIOID FORTE_UR::scm_anEOWith[] = {0, 255, 1, 255, 2, 255, 3, 255, 4, 255, 4, 255};
const TForteInt16 FORTE_UR::scm_anEOWithIndexes[] = {0, 2, -1, 4, 6, 8, 10, -1};
const CStringDictionary::TStringId FORTE_UR::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdDoGoPallet, g_nStringIdTakePhoto, g_nStringIdSendPhotoMSG, g_nStringIdDoGoMaterial, g_nStringIdDoGrasp, g_nStringIdUpdatePallet};

const CStringDictionary::TStringId FORTE_UR::scm_anInternalsNames[] = {g_nStringIdisFirst, g_nStringIdisMSGForPallet};

const CStringDictionary::TStringId FORTE_UR::scm_anInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const SAdapterInstanceDef FORTE_UR::scm_astAdapterInstances[] = {
{g_nStringIdATimeOut, g_nStringIdATimeOut, true }};

const SFBInterfaceSpec FORTE_UR::scm_stFBInterfaceSpec = {
  7,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  7,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};


const SInternalVarsInformation FORTE_UR::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_UR::alg_initialize(void){
isFirst() = true;
isMSGForPallet() = true;
PhotoMSGForMaterial() = false;
PositionInPallet() = 0;
QO() = QI();
}

void FORTE_UR::alg_deInitialize(void){

QO() = false;
}

void FORTE_UR::alg_normalOperation(void){
QO() = QI();

if((true == QI())){
/*   only perform normal operation of QI is true*/

};

}

void FORTE_UR::alg_GoPosition1(void){
PositionInPallet() = "65";
isFirst() = true;
}

void FORTE_UR::alg_wait(void){
ATimeOut().DT() = TakePhotoTimePara();
}

void FORTE_UR::alg_GoPosition2(void){
PositionInPallet() = "66";
isFirst() = false;
isMSGForPallet() = true;
}

void FORTE_UR::alg_PalletMSGProcessing(void){
PhotoMSGOUT() = PhotoMSGIN();

}

void FORTE_UR::alg_StartGrasp(void){
GraspNumber() = URGraspMSG();

}

void FORTE_UR::alg_GoMaterial(void){
PositionInMaterial() = URGraspMSG();
isMSGForPallet() = false;
}

void FORTE_UR::alg_Update(void){
PhotoMSGForMaterial() = false;
GraspNumber() = URGraspMSG();
}


void FORTE_UR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_UR::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_UR::enterStateGoP1(void){
  m_nECCState = scm_nStateGoP1;
  alg_GoPosition1();
  sendOutputEvent( scm_nEventDoGoPalletID);
}

void FORTE_UR::enterStateOperationOnPallet(void){
  m_nECCState = scm_nStateOperationOnPallet;
}

void FORTE_UR::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_UR::enterStateURinPosition1(void){
  m_nECCState = scm_nStateURinPosition1;
  sendOutputEvent( scm_nEventTakePhotoID);
}

void FORTE_UR::enterStateWaitTime(void){
  m_nECCState = scm_nStateWaitTime;
  alg_wait();
  sendAdapterEvent(scm_nATimeOutAdpNum, FORTE_ATimeOut::scm_nEventSTARTID);
}

void FORTE_UR::enterStateGoP2(void){
  m_nECCState = scm_nStateGoP2;
  alg_GoPosition2();
  sendOutputEvent( scm_nEventDoGoPalletID);
}

void FORTE_UR::enterStateURinPosition2(void){
  m_nECCState = scm_nStateURinPosition2;
  sendOutputEvent( scm_nEventTakePhotoID);
}

void FORTE_UR::enterStatePalletMSG(void){
  m_nECCState = scm_nStatePalletMSG;
  alg_PalletMSGProcessing();
  sendOutputEvent( scm_nEventSendPhotoMSGID);
}

void FORTE_UR::enterStateMaterialMSG(void){
  m_nECCState = scm_nStateMaterialMSG;
  alg_StartGrasp();
  sendOutputEvent( scm_nEventDoGraspID);
}

void FORTE_UR::enterStateOperationOnMaterialArea(void){
  m_nECCState = scm_nStateOperationOnMaterialArea;
}

void FORTE_UR::enterStateGoMaterial(void){
  m_nECCState = scm_nStateGoMaterial;
  alg_GoMaterial();
  sendOutputEvent( scm_nEventDoGoMaterialID);
}

void FORTE_UR::enterStateURinMaterialPosition(void){
  m_nECCState = scm_nStateURinMaterialPosition;
  sendOutputEvent( scm_nEventTakePhotoID);
}

void FORTE_UR::enterStateGraspDone(void){
  m_nECCState = scm_nStateGraspDone;
  alg_Update();
  sendOutputEvent( scm_nEventUpdatePalletID);
}

void FORTE_UR::executeEvent(int pa_nEIID){
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
          enterStateOperationOnPallet();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGoP1:
        if((scm_nEventURinPalletPositionID == pa_nEIID) && ((isFirst() == true)))
          enterStateURinPosition1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOperationOnPallet:
        if(scm_nEventPalletInID == pa_nEIID)
          enterStateGoP1();
        else
        if((scm_nEventINITID == pa_nEIID) && ((false == QI())))
          enterStateDeInit();
        else
        if((scm_nEventRecvPhotoMSGID == pa_nEIID) && ((isMSGForPallet() == true)))
          enterStatePalletMSG();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateURinPosition1:
        if(1)
          enterStateWaitTime();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWaitTime:
        if(ATimeOut().TimeOut() == pa_nEIID)
          enterStateGoP2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGoP2:
        if((scm_nEventURinPalletPositionID == pa_nEIID) && ((isFirst() == false)))
          enterStateURinPosition2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateURinPosition2:
        if(1)
          enterStateOperationOnPallet();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePalletMSG:
        if(1)
          enterStateOperationOnMaterialArea();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateMaterialMSG:
        if(scm_nEventGraspDoneID == pa_nEIID)
          enterStateGraspDone();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOperationOnMaterialArea:
        if(scm_nEventURGraspID == pa_nEIID)
          enterStateGoMaterial();
        else
        if((scm_nEventINITID == pa_nEIID) && ((true == QI())))
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGoMaterial:
        if(scm_nEventURinMaterialPositionID == pa_nEIID)
          enterStateURinMaterialPosition();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateURinMaterialPosition:
        if((scm_nEventRecvPhotoMSGID == pa_nEIID) && (((isMSGForPallet() == false) && (PhotoMSGForMaterial() == true))))
          enterStateMaterialMSG();
        else
        if((scm_nEventRecvPhotoMSGID == pa_nEIID) && (((isMSGForPallet() == false) && (PhotoMSGForMaterial() == false))))
          enterStateURinMaterialPosition();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGraspDone:
        if(1)
          enterStateOperationOnMaterialArea();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 14.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


