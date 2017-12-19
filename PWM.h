/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: PWM
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-06-29/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _PWM_H_
#define _PWM_H_

#include <forte_bool.h>
#include <forte_string.h>
#include <forte_uint.h>
#include <processinterface.h>
#include <forte_sync.h>
#include <forte_thread.h>
#include <forte_sem.h>

class FORTE_PWM : public CProcessInterface, public CThread{
  DECLARE_FIRMWARE_FB(FORTE_PWM)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_STRING &PARAMS(){
      return *static_cast<CIEC_STRING*>(getDI(1));
    }
    ;

    CIEC_BOOL &OUT_X(){
      return *static_cast<CIEC_BOOL*>(getDI(2));
    }
    ;

    CIEC_UINT &DUTY(){
      return *static_cast<CIEC_UINT*>(getDI(3));
    }
    ;

    CIEC_UINT &FREQ(){
      return *static_cast<CIEC_UINT*>(getDI(4));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_STRING &STATUS(){
      return *static_cast<CIEC_STRING*>(getDO(1));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventSTARTID = 1;
    static const TEventID scm_nEventSTOPID = 2;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventSTARTOID = 1;
    static const TEventID scm_nEventSTOPOID = 2;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(3, 5, 2, 0)
    ;

    void executeEvent(int pa_nEIID);

    void resumeSelfSuspend();
    void selfSuspend();

    unsigned int mDutyCyle;
    unsigned int mFrequency;

    bool mExecutePWM;
    bool mRefreshParameters;
    bool mInitialized;
    bool mConstantValue;

    static const char * const scmOK;
    static const char * const scmNotInitialised;
    static const char * const scmWrongDutyValue;

    forte::arch::CSemaphore mThreadSemaphore;

  protected:
    virtual void run();

  public:
    FORTE_PWM(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
        CProcessInterface(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData), CThread(), mDutyCyle(0), mFrequency(0), mExecutePWM(false), mRefreshParameters(false), mInitialized(false), mConstantValue(false), mThreadSemaphore(0){
    }

    virtual ~FORTE_PWM();
};

#endif //close the ifdef sequence from the beginning of the file
