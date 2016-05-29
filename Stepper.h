// pins 2, 3, 4, 5, 6, 7
class StepperOne
{
private:
  const byte pins = ~B11111100;
  const byte outputs[8] = {B11000000, // full a
                           B11001100,
                           B00001100, // full b
                           B10101100,
                           B10100000, // rev a
                           B10110100,
                           B00010100, // rev b
                           B11010100};
  byte output = 0;
  const byte stepSize;
  int steps = 0;

public:
  void spin() { PORTD = pins & PORTD; }

  StepperOne( const bool h=false ) : stepSize(h ? 1 : 2)
  {
    DDRD |= ~pins;
  }
  
  void step( byte dir=0 )
  {
    if( dir )
    {
      output += stepSize;
      steps += stepSize;
    }
    else
    {
      output -= stepSize;
      steps -= stepSize;
    }
    
    PORTD = ( pins & PORTD ) | outputs[ output%8 ];
  }
};

// pins 8, 9, 10, 11, 12, 13
class StepperTwo
{
private:
  const byte pins = ~B00111111;
  const byte outputs[8] = {B00110000, // full a
                           B00110011,
                           B00000011, // full b
                           B00101011,
                           B00101000, // rev a
                           B00101101,
                           B00000101, // rev b
                           B00110101};
  byte output = 0;
  const byte stepSize;
  int steps = 0;

public:
  void spin() { PORTB = pins & PORTB; }

  StepperTwo( const bool h=false ) : stepSize(h ? 1 : 2)
  {
    DDRB |= ~pins;
  }
  
  void step( byte dir=0 )
  {
    if( dir )
    {
      output += stepSize;
      steps += stepSize;
    }
    else
    {
      output -= stepSize;
      steps -= stepSize;
    }
    
    PORTB = ( pins & PORTB ) | outputs[ output%8 ];
  }
};
