/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: sqlUpdateMaterial
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-05/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "sqlUpdateMaterial.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "sqlUpdateMaterial_gen.cpp"
#endif

#include "iostream"
#include "iomanip"
#include "windows.h"
using namespace std;
#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","EndOfFile")

DEFINE_FIRMWARE_FB(FORTE_sqlUpdateMaterial, g_nStringIdsqlUpdateMaterial)

const CStringDictionary::TStringId FORTE_sqlUpdateMaterial::scm_anDataInputNames[] = {g_nStringIdMID};

const CStringDictionary::TStringId FORTE_sqlUpdateMaterial::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_sqlUpdateMaterial::scm_anEIWithIndexes[] = {-1, 0, -1};
const TDataIOID FORTE_sqlUpdateMaterial::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_sqlUpdateMaterial::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdATTEMPTCATCH, g_nStringIdCATCHED};

const TForteInt16 FORTE_sqlUpdateMaterial::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_sqlUpdateMaterial::scm_anEventOutputNames[] = {g_nStringIdINITO};

const CStringDictionary::TStringId FORTE_sqlUpdateMaterial::scm_anInternalsNames[] = {g_nStringIdcatchMid};

const CStringDictionary::TStringId FORTE_sqlUpdateMaterial::scm_anInternalsTypeIds[] = {g_nStringIdSTRING};

const SFBInterfaceSpec FORTE_sqlUpdateMaterial::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};


const SInternalVarsInformation FORTE_sqlUpdateMaterial::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_sqlUpdateMaterial::alg_UPDATE(void){
	char * mid = catchMid().getValue();

	char * statement = (char*)malloc(1024);
	strcpy(statement, "update material set status = 'online' where id = ");
    strcat(statement, mid);

	::CoInitialize(NULL);
	_ConnectionPtr m_pConnection("ADODB.Connection");
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConnect="Provider=SQLOLEDB;Server=(local);Database=CIIF;uid=sa;pwd=123456;";
		m_pConnection->Open(strConnect,"","",adModeUnknown);
		if (m_pConnection==NULL)
		{
			cerr<<"Lind data ERROR!\n";
		}
			m_pConnection->Execute(statement,NULL,1); 
	}
	
	catch(_com_error c)
	{
		cerr<<"\nERROR:"<<(char*)c.Description();
	}
	 if(m_pConnection->State)
		  m_pConnection->Close();

	 ::CoUninitialize();
}

void FORTE_sqlUpdateMaterial::alg_SETMID(void){
catchMid() = MID();
}


void FORTE_sqlUpdateMaterial::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_sqlUpdateMaterial::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_sqlUpdateMaterial::enterStateIdle(void){
  m_nECCState = scm_nStateIdle;
}

void FORTE_sqlUpdateMaterial::enterStateUpdate(void){
  m_nECCState = scm_nStateUpdate;
  alg_UPDATE();
}

void FORTE_sqlUpdateMaterial::enterStateSetMid(void){
  m_nECCState = scm_nStateSetMid;
  alg_SETMID();
}

void FORTE_sqlUpdateMaterial::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIdle:
        if(scm_nEventCATCHEDID == pa_nEIID)
          enterStateUpdate();
        else
        if(scm_nEventATTEMPTCATCHID == pa_nEIID)
          enterStateSetMid();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUpdate:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSetMid:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


