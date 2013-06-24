#ifndef __TELEM_H
#define __TELEM_H

#include "settings.h" //Required to set telemetry type
#include TELEM_INCLUDE

#ifndef TELEM_TYPE
#error "A telemtry type is not defined."
#endif

//Telemetry packet structure
typedef struct {
    unsigned long sampleIndex;
    TELEM_TYPE telemData;
} telemStruct_t;

typedef union packedTelemUnion {
    vrTelemStruct_t telemStruct;
    unsigned char dataArray[sizeof(telemStruct_t)];
} telemU;

// Prototypes
void telemSetup(); //To be called in main
void telemReadbackSamples(unsigned long);
void telemSaveData(telemStruct_t *data);
void telemSetSamplesToSave(unsigned long n);
void telemErase(unsigned long);
void telemSetSkip(unsigned int skipnum);
void telemSetStartTime(void);
void telemGetSample(unsigned long sampNum, unsigned int sampLen, unsigned char *data);

#endif  // __TELEM_H