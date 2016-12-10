#include <MozziGuts.h>
#include <EventDelay.h>
#include <SampleHuffman.h>



class SoundEvent {

  
  public:
    SoundEvent() {
      _null = true;
      _del = 100;
    }
    SoundEvent(SampleHuffman *sample, int del) {
      _sample = sample;
      _del = del;
      _null = false;
    }
    ~SoundEvent(){
    }
    
    void start() {
      _kTriggerDelay.start(_del);
    }
    void start(int del) {
      _del = del;
      _kTriggerDelay.start(_del);
    }

    
    bool ready() {
      return _kTriggerDelay.ready();
    }
    

    void onTriggered() {
      _sample->start();
//      Serial.println("triggered");
    }
    void setDelay(int del) {
      _del = del;
    }
    int getDelay() {
      return _del;
    }


    void setSample(SampleHuffman *sample) {
      _sample = sample;
    }

    SampleHuffman* getSample() {
      return _sample;
    }

    bool isNull() {
      return _null;
    }

    void setNull(bool b){
      _null = b;
    }
  
    EventDelay getTrigger() {
      return _kTriggerDelay;
    }

    SoundEvent SoundEvent::operator=( const SoundEvent& rhs ) {
      _null = rhs.isNull();
      _sample = rhs.getSample();
      _del = rhs.getDelay();
      return *this;
    }
  private:
    bool _null = true;
    SampleHuffman *_sample;
    int _del = 0;
    EventDelay _kTriggerDelay = new EventDelay();
};

