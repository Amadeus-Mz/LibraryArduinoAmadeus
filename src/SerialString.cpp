#include "SerialString.h"

Sender::Sender()
{
          
}

void Sender::begin(int index)
{
          _index = index;
}

void Sender::DataArray(int index, String data)
{
          if(index < _index)
          {
                    DataSeed[index] = data;
          }
}

void Sender::send()
{
          for (size_t i = 0; i < _index; i++)
          {
                    if(i > 0)
                    {
                              _DataSend += ':';
                    }

                    if(DataSeed[i] != "")
                    {
                              _DataSend += DataSeed[i];
                    }
                    else
                    {
                              _DataSend += '-';
                    }
          }
          _DataSend += ';';

          Serial.print(_DataSend);
          _DataSend = "";
}

//############################################################

Receiver::Receiver()
{

}

void Receiver::begin(int index)
{
          _index = index;
}

void Receiver::read()
{
          if(Serial.available() > 0)
          {
                    data = Serial.read();
                    BufferRx += data;
                    EndData = BufferRx.indexOf(';');

                    if(EndData > 0)
                    {
                              FullData = BufferRx.substring(0, EndData);
                              strRare = FullData;

                              for (size_t i = 0; i < _index; i++)
                              {
                                        int Cut = 0;
                                        Cut = strRare.indexOf(':');

                                        DataSeed[i] = strRare.substring(0, Cut);
                                        strRare = strRare.substring(Cut + 1);
                              }

                              BufferRx = "";
                              EndData = 0;
                    }
          }
}