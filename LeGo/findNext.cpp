/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: findNext
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-01-05/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "findNext.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "findNext_gen.cpp"
#endif

#include "iostream"
#include "iomanip"
#include "windows.h"
using namespace std;
#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","EndOfFile")

DEFINE_FIRMWARE_FB(FORTE_findNext, g_nStringIdfindNext)

const CStringDictionary::TStringId FORTE_findNext::scm_anDataInputNames[] = {g_nStringIdFINDPOSITION};

const CStringDictionary::TStringId FORTE_findNext::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const CStringDictionary::TStringId FORTE_findNext::scm_anDataOutputNames[] = {g_nStringIdCATCHINFO, g_nStringIdMID};

const CStringDictionary::TStringId FORTE_findNext::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_findNext::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_findNext::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_findNext::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdFINDNEXT};

const TDataIOID FORTE_findNext::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_findNext::scm_anEOWithIndexes[] = {-1, 0, -1, -1};
const CStringDictionary::TStringId FORTE_findNext::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCATCH, g_nStringIdPASS};

const CStringDictionary::TStringId FORTE_findNext::scm_anInternalsNames[] = {g_nStringIdcatchOrPass};

const CStringDictionary::TStringId FORTE_findNext::scm_anInternalsTypeIds[] = {g_nStringIdSTRING};

const SFBInterfaceSpec FORTE_findNext::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_findNext::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_findNext::setInitialValues(){
  catchOrPass() = "''";
}

void FORTE_findNext::alg_FIND(void){
	int findPos = FINDPOSITION();

	char * m1 = (char*)malloc(2);
	char * m2 = (char*)malloc(2);

	if(findPos == 1) {
		m1 = "22";
		m2 = "22";
	}
	else if(findPos == 2) {
		m1 = "23";
		m2 = "32";
	}
	else if(findPos == 3) {
		m1 = "24";
		m2 = "42";
	}
	else if(findPos == 4) {
		m1 = "26";
		m2 = "62";
	}

	char * statement = (char*)malloc(1024);
	strcpy(statement, "select m.id, m.sfc, m.color, m.model from orders o, material m where m.sfc = o.sfc and m.status = 'ready' and (m.model = '");
    strcat(statement, m1);
	strcat(statement, "' or m.model = '");
	strcat(statement, m2);
	strcat(statement, "') order by priority desc, createtime asc");

	::CoInitialize(NULL);//初始化OLE/COM库环境，为访问ADO接口做准备
	_RecordsetPtr m_pRecordset("ADODB.Recordset");
	_ConnectionPtr m_pConnection("ADODB.Connection");
	_bstr_t bstrSQL(statement);
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConnect="Provider=SQLOLEDB;Server=(local);Database=CIIF;uid=sa;pwd=123456;";
		m_pConnection->Open(strConnect,"","",adModeUnknown);
		if (m_pConnection==NULL)
		{
			cerr<<"Lind data ERROR!\n";
		}
		//创建记录集
		m_pRecordset.CreateInstance(_uuidof(Recordset));
		//取得表中的记录
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		_variant_t mid = "", colour = "";
		while (!m_pRecordset->EndOfFile)

		{
			mid = m_pRecordset->GetCollect("id");
			colour = m_pRecordset->GetCollect("color");
			break;
		}
		m_pRecordset->Close(); // 关闭记录集

		char * mid_c = (char*)malloc(100);
		char * colour_c = (char*)malloc(100);
  
		strcpy(mid_c, (LPCSTR)_bstr_t(mid));
		strcpy(colour_c, (LPCSTR)_bstr_t(colour));

		if(strcmp(mid_c, "") == 0) {
			catchOrPass() = "pass";
		}
		else {
			catchOrPass() = "catch";

			char * ret = (char*)malloc(4);
			strcpy(ret, m1);
			strcat(ret, "0");
			strcat(ret, colour_c);

			CATCHINFO() = ret;
			MID() = mid_c;
		}
	}
	// 捕捉异常
	catch(_com_error c)
	{
		cerr<<"\nERROR:"<<(char*)c.Description();
	}
	 if(m_pConnection->State)
		  m_pConnection->Close();

	 ::CoUninitialize();
}


void FORTE_findNext::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_findNext::enterStateInitialize(void){
  m_nECCState = scm_nStateInitialize;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_findNext::enterStateFind(void){
  m_nECCState = scm_nStateFind;
  alg_FIND();
}

void FORTE_findNext::enterStateCatch(void){
  m_nECCState = scm_nStateCatch;
  sendOutputEvent( scm_nEventCATCHID);
}

void FORTE_findNext::enterStatePass(void){
  m_nECCState = scm_nStatePass;
  sendOutputEvent( scm_nEventPASSID);
}

void FORTE_findNext::enterStateIdle(void){
  m_nECCState = scm_nStateIdle;
}

void FORTE_findNext::executeEvent(int pa_nEIID){
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
      case scm_nStateFind:
        if(catchOrPass() == "pass")
          enterStatePass();
        else
        if(catchOrPass() == "catch")
          enterStateCatch();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCatch:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePass:
        if(1)
          enterStateIdle();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIdle:
        if(scm_nEventFINDNEXTID == pa_nEIID)
          enterStateFind();
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


