#ifndef SerialString_h
#define SerialString_h
#include "Arduino.h"

class Sender
{
private:
          int _index;
          String _DataSend;
public:
          String DataSeed[100];

          Sender();
          void begin(int index);
          void DataArray(int index, String data);
          void send();
};

class Receiver
{
private:
          int _index;
          int EndData;
          char data;
          String BufferRx;
          String FullData;
          String strRare;
public:
          String DataSeed[100];

          Receiver();
          void begin(int index);
          void read();
};

#endif