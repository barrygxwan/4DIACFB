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

#include "PWM.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "PWM_gen.cpp"
#endif

#include <unistd.h>

DEFINE_FIRMWARE_FB(FORTE_PWM, g_nStringIdPWM)

const CStringDictionary::TStringId FORTE_PWM::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdOUT_X, g_nStringIdDUTY, g_nStringIdFREQ };

const CStringDictionary::TStringId FORTE_PWM::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_PWM::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdSTATUS };

const CStringDictionary::TStringId FORTE_PWM::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING };

const TForteInt16 FORTE_PWM::scm_anEIWithIndexes[] = { 0, 3, -1 };
const TDataIOID FORTE_PWM::scm_anEIWith[] = { 0, 1, 255, 0, 3, 4, 2, 255 };
const CStringDictionary::TStringId FORTE_PWM::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdSTART, g_nStringIdSTOP };

const TDataIOID FORTE_PWM::scm_anEOWith[] = { 0, 1, 255, 0, 1, 255, 0, 1, 255 };
const TForteInt16 FORTE_PWM::scm_anEOWithIndexes[] = { 0, 3, 6, -1 };
const CStringDictionary::TStringId FORTE_PWM::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdSTARTO, g_nStringIdSTOPO };

const SFBInterfaceSpec FORTE_PWM::scm_stFBInterfaceSpec = { 3, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 5, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

const char * const FORTE_PWM::scmOK = "OK";
const char * const FORTE_PWM::scmNotInitialised = "FB not initialized";
const char * const FORTE_PWM::scmWrongDutyValue = "The value of the Duty data input should be <= 100";

FORTE_PWM::~FORTE_PWM(){
  if(isAlive()){
    mExecutePWM = false;
    setAlive(false);
    resumeSelfSuspend();
    end();
  }
}

void FORTE_PWM::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        mInitialized = QO() = CProcessInterface::initialise(false); //initialize as output
        if(!isAlive()){
          start();
        }
      }
      else{
        mInitialized = QO() = CProcessInterface::deinitialise();
        if(isAlive()){
          mExecutePWM = false;
          setAlive(false);
          resumeSelfSuspend();
          end();
        }
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventSTARTID:
      DEVLOG_INFO("PWM: Start event received\n");
      if(mInitialized){
        if(100 >= DUTY()){
          mDutyCyle = DUTY();
          mFrequency = FREQ();
          mRefreshParameters = true;
          DEVLOG_INFO("PWM: Duty cycle correct.\n");
          if(!mExecutePWM || mConstantValue){
            DEVLOG_INFO("PWM: Resuming suspend.\n");
            mExecutePWM = true;
            resumeSelfSuspend();
          }
        }
        else{
          STATUS() = scmWrongDutyValue;
          DEVLOG_ERROR("PWM: Wrong duty value\n");
        }
      }
      else{
        STATUS() = scmNotInitialised;
        DEVLOG_ERROR("PWM: FB not initialized\n");
      }
      sendOutputEvent(scm_nEventSTARTOID);
      break;
    case scm_nEventSTOPID:
      DEVLOG_INFO("PWM: Stop event received\n");
      if(mInitialized){
        mExecutePWM = false;
        if(mConstantValue){
          resumeSelfSuspend();
        }
      }
      else{
        STATUS() = scmNotInitialised;
        DEVLOG_ERROR("PWM: FB not initialized\n");
      }
      sendOutputEvent(scm_nEventSTARTOID);
      break;
  }
}

void FORTE_PWM::run(){
  DEVLOG_INFO("PWM: Thread started\n");
  while(isAlive()){
    DEVLOG_INFO("PWM: Entering selfsuspend\n");
    selfSuspend();
    DEVLOG_INFO("PWM: Leaving selfsuspend\n");
    if(!isAlive()){
      break;
    }
    unsigned int uSecondsOn = 0;
    unsigned int uSecondsOff = 0;
    while(mExecutePWM){
      if(mRefreshParameters){
        mRefreshParameters = false;
        unsigned int uPeriod = (1000000 / mFrequency);
        uSecondsOn = uPeriod * mDutyCyle / 100;
        uSecondsOff = uPeriod - uSecondsOn;
        if(0 != uSecondsOff && 0 != uSecondsOn){
          mConstantValue = false;
        }
        DEVLOG_INFO("PWM: PWM. Parameters refreshed frequency = %u, duty = %u, period = %u, ON = %u, OFF = %u\n", mFrequency, mDutyCyle, uPeriod, uSecondsOn, uSecondsOff);
      }

      if(0 == uSecondsOff){
        OUT_X() = true;
        writePin();
        mConstantValue = true;
        DEVLOG_INFO("PWM: OFF is %u (should be zero) so led always ON and entering selfsuspend.\n", uSecondsOff);
        selfSuspend();
      }
      else if(0 == uSecondsOn){
        OUT_X() = false;
        writePin();
        mConstantValue = true;
        DEVLOG_INFO("PWM: ON is %u (should be zero) so led always OFF and entering selfsuspend\n", uSecondsOn);
        selfSuspend();
      }
      else{
        OUT_X() = true;
        writePin();
        usleep(uSecondsOn);
        OUT_X() = false;
        writePin();
        usleep(uSecondsOff);
      }
    }
    DEVLOG_INFO("PWM: Outside loop, about to turn led off\n");
    OUT_X() = false;
    writePin();
  }
}

void FORTE_PWM::resumeSelfSuspend(){
  mThreadSemaphore.semInc();
}

void FORTE_PWM::selfSuspend(){
  mThreadSemaphore.semWaitIndefinitly();
}

